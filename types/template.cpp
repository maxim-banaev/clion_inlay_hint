#include <map>
#include <string>
template <class T> struct Foo {
  T fake() {
    auto tt = T{}; // T
    return tt;
  }

  using value_type = T;

  auto getElem() -> value_type {
    auto vt = value_type{}; // value_type
    return vt;
  }
};

int main() {
  Foo<int> f;
  [[maybe_unused]] auto val = f.getElem(); //  int
  [[maybe_unused]] auto va1 = f.fake();    //  int

  Foo<std::string> f1;
  auto val2 = f1.getElem(); //  string
  auto val3 = f1.fake();    //  string

  using namespace std;

  map<string, bool> m = {{"One", true}};
  [[maybe_unused]] auto val4 = m["One"]; // bool
}