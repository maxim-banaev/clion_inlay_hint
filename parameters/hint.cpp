#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "UnusedLocalVariable"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

#include <string>

void function_with_one_parameter(int number);
void function_with_one_default_parameter(int number = 100);
void function_with_two_parameter(int number, bool flag);

void check_function_call() {
    function_with_one_parameter(100); // number
    function_with_one_parameter({}); // number

    function_with_one_default_parameter(100); // number

    function_with_two_parameter(1, true); // number ... flag


    //negative cases
    int number = 100;
    function_with_one_parameter(number);
    function_with_one_parameter(/*number=*/100);
    function_with_one_parameter(/*number*/100);

    function_with_one_default_parameter();
}


class Tes {
    int number;
public:
    explicit Tes(int number) : number(number) {}
};


void check_constructor_call() {
    std::string s("foo"); // s
    std::string s1{"bar"}; // s

    Tes t(1); // number

    // negative
    std::string s2{};
}

void foo(int Params...) {}

void check_variadic_parameter() {
    foo(5, 6); // Params
}


template<typename T>
void tp_function_with_one_parameter(T number) {}

void check_template_function_call() {
    tp_function_with_one_parameter(100); // number
}

#define FOO(A) A

void check_macro() {
    FOO(100); // ?
}




#pragma clang diagnostic pop