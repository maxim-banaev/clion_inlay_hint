#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedLocalVariable"

#include <array>
#include <vector>

void check_c_array() {
  int arr[] = {0, 1, 2, 3}; // [0]: ...

  int arr22[2][3] = {{0, 1, 2},  // [0]: [0]: ...
                     {3, 4, 5}}; // [1]: [0]: ...
  // negative case
  // All elements are initialized with 0, so we should not show hints
  int frequency[4] = {0}; // none
  int* frequency_p[4] = {nullptr}; // none
}

void check_std_container() {
  std::array<int, 3> a = {1, 2, 3}; // none

  std::vector<int> v = {1, 2, 3, 4}; // none

  auto f = {1, 2, 3, 4}; // none
}

#pragma clang diagnostic pop