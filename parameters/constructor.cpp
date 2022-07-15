#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "UnusedLocalVariable"

struct Point {
    int x, y;
};

[[maybe_unused]] void check_structure() {
    Point p{0, 0}; // .x .y
}

#pragma clang diagnostic pop