#include <iostream>
#include "gtest/gtest.h"
#include "json.h"
using namespace std;
TEST(Parser, File) {
    string fname = "../tests/test.json";
    meng::Json tmp = parse_file(fname.c_str());
    ASSERT_EQ(tmp["editor.fontFamily"].string_value(), "Monaco");
    ASSERT_EQ(tmp["code-runner.executorMap"]["java"].string_value(), "cd $dir && javac $fileName && java $fileNameWithoutExt");
    ASSERT_EQ(tmp["python.linting.pylintArgs"][0].string_value(), "-d c0103, c0111");
    ASSERT_EQ(tmp["editor.fontSize"].int_value(), 20);
}

TEST(ToJson, object) {
    using meng::Json;
    Json my_json = Json::object {
		{ "key1", "value1" },
		{ "key2", false },
		{ "key3", Json::array { 1, 2, 3 } },
	};
    std::string json_str = my_json.dump();
    ASSERT_EQ(json_str, "{\"key1\": \"value1\", \"key2\": false, \"key3\": [1, 2, 3]}");
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}