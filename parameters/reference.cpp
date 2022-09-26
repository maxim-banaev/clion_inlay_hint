#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

void might_modify(int &arg);

void check_non_const_reference(int argc) {
  might_modify(argc); // &
}

#pragma clang diagnostic pop