#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "modernize-avoid-bind"
#pragma ide diagnostic ignored "performance-unnecessary-copy-initialization"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedLocalVariable"

#include <string>
#include <vector>
#include <array>
#include <map>
#include <memory>
#include <tuple>
#include <unordered_map>
#include <iostream>

#ifdef _WIN32
#include <functional>
#endif

void test_basic_types() {
    int i = 1;
    auto aInt = i; // int

    float f = 2;
    auto aFlat = f; // float

    const double d = 3;
    auto aDouble = d; // double

    auto aChar = "char"; // const char *

    bool b = true;
    auto aBool = b; // bool // Obvious type hint should be enabled
}

template<typename T>
void test_template_parameter_type(T t) {
    auto at = t; // T
}

class myClass {
};

myClass getClass() { return {}; }

void test_custom_class() {
    auto mc = getClass(); // myClass
}


void test_pointers() {

    int *pInt = nullptr;
    auto aInt = pInt; // int*

    int **ppInt = nullptr;
    auto aIInt = ppInt; // int**

    const int *pcInt = nullptr;
    auto apcInt = pcInt; // const int*

    int *const cpInt = nullptr;
    auto acpInt = cpInt; // int*

    const char *const *pChar = nullptr;
    auto apChar = pChar; // const char *const*

    bool b[] = {true, false};
    auto apBool = b; // bool *

    auto aNull = nullptr; // nullptr_t
}

void test_string(const std::string &str) {
    std::string s("foo");
    auto aString = s; // string

    const auto &refStr = str; // const string&
    auto wStr = std::to_wstring(2137LL); // wstring
}


void test_std_type() {
    std::vector v = {1, 2, 3};
    auto aVec = v; // vector<int>

    std::array a = {1.0, 2.0, 3.0};
    auto aArr = a; // array<double, 3>

    std::map<char, bool> m = {{'c', true}};
    auto aMap = m; // map<char, bool>

    const auto tuple = std::make_tuple(1, 'a', 2.3); // const tuple<int, char, double>

    auto aList = {1, 2, 3, 4}; // initializer_list<int>
}


void test_pair(const std::unordered_map<std::string, int> &v) {
    std::cout << std::boolalpha;

    for (const auto &item: v) { // const pair<const string, int>&
        std::cout << "\t\t - " << "";//item.first;
    }
}


void test_structured_bindings() {
    int a = 1, b = 2;
    const auto &[x, // int&
            y  // int&
    ] = std::tie(a, b);

    const auto &[i, // const int
            c, // const char
            d // const double
    ] = std::make_tuple(1, 'a', 2.3);
}


template<class T>
void test_iterator(typename T::iterator Iter) {
    auto X = Iter; // T::iterator
}


void test_smart_ptr() {
    auto pShared = std::make_shared<myClass>(); // shared_ptr<myClass>
    auto pUnique = std::make_unique<myClass>(); // unique_ptr<myClass>
}


void test_loop() {
    std::vector v = {1, 2, 3};
    for (const auto &item: v) { // int const&

    }

    std::map<char, bool> m = {{'c', true}};
    for (auto &&item: m) {  // pair<const char, bool> &

    }
}

int add(int x, int y) { return x + y; }

void test_bind_to_lambda(int num) {
    int x = 2;
    auto clj = std::bind(add, x, num); // __bind<int (&)(int, int), int&, int&>
}


template<typename T, typename U>
auto doOperation(T t, U u) -> decltype(t + u) {
    return t + u;
}

void test_fun_type() {
    auto op = doOperation(3, 1); //  int
    auto op1 = doOperation(3L, 0); // long
    auto op2 = doOperation(3.0, 0); // double
}

#pragma clang diagnostic pop