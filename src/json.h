//
// Created by meng on 17-8-20.
//
#ifndef MENG_JSON_H
#define MENG_JSON_H

#include <initializer_list>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace meng {
class JValue;
enum class Type { NUL, NUMBER, BOOL, STRING, ARRAY, OBJECT };

class Json final {
 public:
  using array = std::vector<Json>;
  using object = std::map<std::string, Json>;

  Json() noexcept;
  Json(std::nullptr_t) noexcept;
  Json(double value);
  Json(int value);
  Json(bool value);
  Json(const std::string &value);
  Json(std::string &&value);
  Json(const char *value);
  Json(const array &values);
  Json(array &&values);
  Json(const object &values);
  Json(object &&values);

  //实现to_json接口的类可以直接转换为Json对象
  template <typename T, typename = decltype(&T::to_json())>
  Json(const T &t) : Json(t.to_json()) {}

  // map
  template <
      typename M,
      typename std::enable_if<
          std::is_constructible<
              std::string, decltype(std::declval<M>().begin()->first)>::value &&
              std::is_constructible<
                  Json, decltype(std::declval<M>().begin()->second)>::value,
          int>::type = 0>
  Json(const M &m) : Json(object(m.begin(), m.end())) {}

  // array
  template <class V,
            typename std::enable_if<
                std::is_constructible<
                    Json, decltype(*std::declval<V>().begin())>::value,
                int>::type = 0>
  Json(const V &v) : Json(array(v.begin(), v.end())) {}

  Type type() const;

  bool is_null() const { return type() == Type::NUL; }
  bool is_number() const { return type() == Type::NUMBER; }
  bool is_bool() const { return type() == Type::BOOL; }
  bool is_string() const { return type() == Type::STRING; }
  bool is_array() const { return type() == Type::ARRAY; }
  bool is_object() const { return type() == Type::OBJECT; }

  double number_value() const;
  int int_value() const;
  bool bool_value() const;
  const std::string &string_value() const;
  const array &array_items() const;
  const object &object_items() const;

  const Json &operator[](size_t i) const;
  const Json &operator[](const std::string &key) const;

  void dump(std::string &out) const;

  std::string dump() const {
    std::string out;
    dump(out);
    return out;
  }

 private:
  std::shared_ptr<JValue> m_ptr;
};

class JValue {
 protected:
  friend class Json;
  friend class JInt;
  friend class JDouble;
  virtual Type type() const = 0;
  virtual void dump(std::string &out) const = 0;
  virtual double number_value() const;
  virtual int int_value() const;
  virtual bool bool_value() const;
  virtual const std::string &string_value() const;
  virtual const Json::array &array_items() const;
  virtual const Json &operator[](size_t i) const;
  virtual const Json::object &object_items() const;
  virtual const Json &operator[](const std::string &key) const;
  virtual ~JValue() {}
};
}

meng::Json parse_string(const std::string &s);
meng::Json parse_file(const char *filename);
#endif  // MENG_JSON_H