#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedParameter"
#pragma ide diagnostic ignored "ConstantParameter"

void basic_parameter_test(auto x) {} // int

[[maybe_unused]] void check_basic_parameter_test() { basic_parameter_test(2); }

template <typename T> void basic_parameter_test_with_template(T x) {} // ?

[[maybe_unused]] void check_basic_parameter_test_with_template() {
  basic_parameter_test_with_template(2);
}

template <class T>
concept Meowable = requires(T x) { x.moew; };

void concept_test(Meowable auto x) {} // Cat

class Cat {
public:
  bool moew;
};

[[maybe_unused]] void check_concept_test() { concept_test(Cat()); }

#pragma clang diagnostic pop