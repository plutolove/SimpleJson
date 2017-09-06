[![Build Status](https://travis-ci.org/plutolove/SimpleJson.svg?branch=master)](https://travis-ci.org/plutolove/SimpleJson)
### SimpleJson
---
SimpleJson是一个借助Flex和Bison工具实现的简易Json解释器，用C++11实现，目前不支持Unicode。
### Build SimpleJson
* 安装cmake，Flex，Bison  
* git clone https://github.com/plutolove/SimpleJson.git  
* cd SimpleJson && mkdir build && cd build  
* cmake .. && make
### Usage
---
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
测试的json文件
```json
{
    "editor.fontFamily": "Monaco",
    "editor.fontSize": 20,
    "editor.cursorStyle": "block",
    "rust.racerPath": "/home/user/.cargo/bin/racer",
    "rust.rustfmtPath": "/home/user/.cargo/bin/rustfmt",
    "rust.rustsymPath": "/home/user/.cargo/bin/rustsym",
    "rust.rustLangSrcPath": "/home/user/.cargo/src",
    "rust.cargoPath": "/home/user/.cargo/bin/cargo",
    "rust.cargoHomePath": "/home/user/.cargo",
  "code-runner.executorMap": {
    "javascript": "node",
    "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
    "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "objective-c": "cd $dir && gcc -framework Cocoa $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
    "php": "php",
    "python": "python",
    "perl": "perl",
    "ruby": "ruby",
    "go": "go run",
    "lua": "lua",
    "groovy": "groovy",
    "powershell": "powershell -ExecutionPolicy ByPass -File",
    "bat": "cmd /c",
    "shellscript": "bash",
    "fsharp": "fsi",
    "csharp": "scriptcs",
    "vbscript": "cscript //Nologo",
    "typescript": "ts-node",
    "coffeescript": "coffee",
    "scala": "scala",
    "swift": "swift",
    "julia": "julia",
    "crystal": "crystal",
    "ocaml": "ocaml",
    "r": "Rscript",
    "applescript": "osascript",
    "clojure": "lein exec",
    "haxe": "haxe --cwd $dirWithoutTrailingSlash --run $fileNameWithoutExt",
    "rust": "cd $dir && cargo run",
    "racket": "racket",
    "ahk": "autohotkey",
    "autoit": "autoit3",
    "kotlin": "cd $dir && kotlinc $fileName -include-runtime -d $fileNameWithoutExt.jar && java -jar $fileNameWithoutExt.jar",
    "dart": "dart",
    "pascal": "cd $dir && fpc $fileName && $dir$fileNameWithoutExt",
    "d": "cd $dir && dmd $fileName && $dir$fileNameWithoutExt",
    "haskell": "runhaskell"
  },
  "workbench.colorTheme": "One Dark Pro",
  "python.linting.pylintArgs": [
    "-d c0103, c0111"
  ],
  "extensions.ignoreRecommendations": false,
  "workbench.iconTheme": "vscode-great-icons",
  "C_Cpp.clang_format_style": "Google"
}
```