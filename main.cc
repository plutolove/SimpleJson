#include <json.h>
#include <iostream>
#include <string>

using namespace std;
using meng::Json;

int main() {
  string fname = "../tests/test.json";
  meng::Json tmp = parse_file(fname.c_str());
  cout << tmp["editor.fontFamily"].string_value() << endl;
  cout << tmp["code-runner.executorMap"]["java"].string_value() << endl;
  cout << tmp["python.linting.pylintArgs"][0].string_value() << endl;
  cout << tmp["editor.fontSize"].int_value() << endl;
  Json my_json = Json::object{
      {"key1", "value1"}, {"key2", false}, {"key3", Json::array{1, 2, 3}},
  };
  std::string json_str = my_json.dump();
  cout << json_str << endl;
  return 0;
}