#include <iostream>
#include "gtest/gtest.h"
#include "json.h"
using namespace std;
TEST(Parser, File) {
    string fname = "/home/meng/CLionProjects/Lisp/tests/calc.json";
	meng::Json tmp = parse_file(fname.c_str());
    ASSERT_EQ("and", tmp["type"].string_value());
    ASSERT_EQ("hammersley", tmp["postprocessors"][0]["type"].string_value());
    ASSERT_EQ(tmp["descendants"][0]["type"].string_value(), "directory");
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}