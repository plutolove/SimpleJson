//
// Created by meng on 17-8-20.
//

#include "json.h"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <limits>

namespace meng {
using std::string;
using std::vector;
using std::map;
using std::make_shared;
using std::initializer_list;
using std::move;
using std::to_string;

struct Null {};

static void dump(Null, string &out) { out += "null"; }

static void dump(double value, string &out) { out += to_string(value); }

static void dump(int value, string &out) { out += to_string(value); }

static void dump(bool value, string &out) { out += value ? "true" : "false"; }

static void dump(const string &value, string &out) {
  out += '"';
  out += value;
  out += '"';
}

static void dump(const Json::array &values, string &out) {
  bool first = true;
  out += "[";
  for (const auto &item : values) {
    if (!first) out += ", ";
    item.dump(out);
    first = false;
  }
  out += "]";
}

static void dump(const Json::object &values, string &out) {
  bool first = true;
  out += "{";
  for (const auto &kv : values) {
    if (!first) out += ", ";
    dump(kv.first, out);
    out += ": ";
    kv.second.dump(out);
    first = false;
  }
  out += "}";
}

void Json::dump(string &out) const { m_ptr->dump(out); }

template <Type tp, typename T>
class Value : public JValue {
 protected:
  explicit Value(const T &value) : m_value(value) {}
  explicit Value(T &&value) : m_value(move(value)) {}

  Type type() const override { return tp; }

  const T m_value;
  void dump(string &out) const override { meng::dump(m_value, out); }
};

class JDouble final : public Value<Type::NUMBER, double> {
  double number_value() const override { return m_value; }
  int int_value() const override { return static_cast<int>(m_value); }

 public:
  explicit JDouble(double value) : Value(value) {}
};

class JInt final : public Value<Type::NUMBER, int> {
  double number_value() const override { return m_value; }
  int int_value() const override { return m_value; }

 public:
  explicit JInt(int value) : Value(value) {}
};

class JsonBoolean final : public Value<Type::BOOL, bool> {
  bool bool_value() const override { return m_value; }

 public:
  explicit JsonBoolean(bool value) : Value(value) {}
};

class JsonString final : public Value<Type::STRING, string> {
  const string &string_value() const override { return m_value; }

 public:
  explicit JsonString(const string &value) : Value(value) {}
  explicit JsonString(string &&value) : Value(move(value)) {}
};

class JArray final : public Value<Type::ARRAY, Json::array> {
  const Json::array &array_items() const override { return m_value; }
  const Json &operator[](size_t i) const override;

 public:
  explicit JArray(const Json::array &value) : Value(value) {}
  explicit JArray(Json::array &&value) : Value(move(value)) {}
};

class JObject final : public Value<Type::OBJECT, Json::object> {
  const Json::object &object_items() const override { return m_value; }
  const Json &operator[](const string &key) const override;

 public:
  explicit JObject(const Json::object &value) : Value(value) {}
  explicit JObject(Json::object &&value) : Value(move(value)) {}
};

class JsonNull final : public Value<Type::NUL, Null> {
 public:
  JsonNull() : Value({}) {}
};

struct Statics {
  const std::shared_ptr<JValue> null = make_shared<JsonNull>();
  const std::shared_ptr<JValue> t = make_shared<JsonBoolean>(true);
  const std::shared_ptr<JValue> f = make_shared<JsonBoolean>(false);
  const string empty_string;
  const vector<Json> empty_vector;
  const map<string, Json> empty_map;
  Statics() {}
};

static const Statics &statics() {
  static const Statics s{};
  return s;
}

static const Json &static_null() {
  static const Json json_null;
  return json_null;
}

Json::Json() noexcept : m_ptr(statics().null) {}
Json::Json(std::nullptr_t) noexcept : m_ptr(statics().null) {}
Json::Json(double value) : m_ptr(make_shared<JDouble>(value)) {}
Json::Json(int value) : m_ptr(make_shared<JInt>(value)) {}
Json::Json(bool value) : m_ptr(value ? statics().t : statics().f) {}
Json::Json(const string &value) : m_ptr(make_shared<JsonString>(value)) {}
Json::Json(string &&value) : m_ptr(make_shared<JsonString>(move(value))) {}
Json::Json(const char *value) : m_ptr(make_shared<JsonString>(value)) {}
Json::Json(const Json::array &values) : m_ptr(make_shared<JArray>(values)) {}
Json::Json(Json::array &&values)
    : m_ptr(make_shared<JArray>(move(values))) {}
Json::Json(const Json::object &values)
    : m_ptr(make_shared<JObject>(values)) {}
Json::Json(Json::object &&values)
    : m_ptr(make_shared<JObject>(move(values))) {}

Type Json::type() const { return m_ptr->type(); }
double Json::number_value() const { return m_ptr->number_value(); }
int Json::int_value() const { return m_ptr->int_value(); }
bool Json::bool_value() const { return m_ptr->bool_value(); }
const string &Json::string_value() const { return m_ptr->string_value(); }
const vector<Json> &Json::array_items() const { return m_ptr->array_items(); }
const map<string, Json> &Json::object_items() const {
  return m_ptr->object_items();
}
const Json &Json::operator[](size_t i) const { return (*m_ptr)[i]; }
const Json &Json::operator[](const string &key) const { return (*m_ptr)[key]; }

double JValue::number_value() const { return 0; }
int JValue::int_value() const { return 0; }
bool JValue::bool_value() const { return false; }
const string &JValue::string_value() const { return statics().empty_string; }
const vector<Json> &JValue::array_items() const {
  return statics().empty_vector;
}
const map<string, Json> &JValue::object_items() const {
  return statics().empty_map;
}
const Json &JValue::operator[](size_t) const { return static_null(); }
const Json &JValue::operator[](const string &) const {
  return static_null();
}

const Json &JObject::operator[](const string &key) const {
  auto iter = m_value.find(key);
  return (iter == m_value.end()) ? static_null() : iter->second;
}
const Json &JArray::operator[](size_t i) const {
  if (i >= m_value.size())
    return static_null();
  else
    return m_value[i];
}
}