enum Choice {
    Yes, No [[maybe_unused]]
};

void do_thing(Choice Cancelable);

[[maybe_unused]] void check_enum_basic() {
    do_thing(Yes); //  Cancelable
}