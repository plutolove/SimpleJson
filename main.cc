#include <iostream>
#include <string>
#include <json.h>
using namespace std;
using meng::Json;
int main() {
	string fname = "../tests/calc.json";
	meng::Json tmp = parse_file(fname.c_str());
	cout<<tmp["type"].string_value()<<endl;
	cout<<tmp["postprocessors"][0]["type"].string_value()<<endl;
	cout<<tmp["descendants"][0]["type"].string_value()<<endl;

	Json my_json = Json::object {
		{ "key1", "value1" },
		{ "key2", false },
		{ "key3", Json::array { 1, 2, 3 } },
	};
	std::string json_str = my_json.dump();
	cout<<json_str<<endl;
	return 0;
}