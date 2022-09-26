#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

auto getInt() { return 0; } // int

void check_lambda_return() {
  []() {};                  // void
  [&](int c) {};            // void
  []() { return 1; };       // int
  [=]() { return ""; };     // const char *
  []() { return []() {}; }; // void () const ... void
}

#pragma clang diagnostic pop