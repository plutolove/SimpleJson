### SimpleJson
SimpleJson是一个借助Flex和Bison工具实现的简易Json解释器，用C++11实现，目前不支持Unicode。
### Build SimpleJson
* 安装cmake，Flex，Bison  
* git clone https://github.com/plutolove/SimpleJson.git  
* cd SimpleJson && mkdir build && cd build  
* cmake .. && make
### Usage
```cpp
#include <iostream>
#include <string>
#include <json.h>
using namespace std;
using meng::Json;
int main() {
	string fname = "../tests/calc.json";

    //从文件解析json
	meng::Json tmp = parse_file(fname.c_str());
	cout<<tmp["type"].string_value()<<endl;
	cout<<tmp["postprocessors"][0]["type"].string_value()<<endl;
	cout<<tmp["descendants"][0]["type"].string_value()<<endl;
    
    //将对象生成json
	Json my_json = Json::object {
		{ "key1", "value1" },
		{ "key2", false },
		{ "key3", Json::array { 1, 2, 3 } },
	};
	std::string json_str = my_json.dump();
	cout<<json_str<<endl;
	return 0;
}
```