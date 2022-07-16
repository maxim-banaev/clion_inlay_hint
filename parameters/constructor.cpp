#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "UnusedLocalVariable"

#include <string>

struct Point {
    int x, y;
};

struct S {
    enum {
        CHAR, INT, DOUBLE
    } tag;
    union {
        char c;
        int i;
        double d;
    };
};

[[maybe_unused]] void check_structure() {
    Point p{0, 0}; // .x ... .y

    S s = {S::CHAR, 'a'}; // .tag ... .c
}

union A {
    int x;
    char c[4];
};

[[maybe_unused]] void check_union() {
    A u = {1}; // .x
}


struct Foo { int x, y; };

struct Bar {
    Foo f;
    Bar() : f{1,2} {} // .x .y
};

struct Bat {
    Foo f;
    Bat(Foo val) : f{val} {} // none
};

struct Baz {
    Foo &f;
    Baz(Foo &ref) : f{ref} {} //  none
};

// Designated initializer
struct Person
{
    std::string name{};
    std::string surname{};
    unsigned age{};
};

struct Employee : public Person
{
    unsigned salary{10000};
};

void check_designated_initializer(){
    Employee emp { {"John", "Wick", 40}, 5000}; // .name ... .surname ... .age ... .salary
}

#pragma clang diagnostic pop