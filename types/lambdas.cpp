#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "performance-unnecessary-value-param"
#include <string>

class myClass {};

void test_basic() {
  auto ldb_empty = []() -> void {}; // void () const
  auto ldb_empty_2 = [] {};         // void () const
  auto lbd_param = [](int x, int y) -> int {
    return x + y;
  };                                                 // int (int,int) const
  auto ldb_captures = [&](std::string s) -> void {}; // void (string) const
}

#pragma clang diagnostic pop