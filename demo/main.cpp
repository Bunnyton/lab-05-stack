#include "stack_args.hpp"

int main() {
  StackArgs<std::pair<int, int>> stack;
  stack.push_emplace(1, 2);
  return 0;
}