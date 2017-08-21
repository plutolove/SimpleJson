#include <iostream>
#include "gtest/gtest.h"
#include "json.h"
using namespace std;
TEST(Parser, File) {
    string fname = "/home/meng/CLionProjects/Lisp/tests/calc.json";
	meng::Json tmp = parse_file(fname.c_str());
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}