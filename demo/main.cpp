#include "stack.hpp"
#include "stack_args.hpp"

int main() {
  StackArgs<std::pair<int, int>> stack;
  stack.push_emplace(1, 2);
  Stack<float> stack1;
  stack1.push(1);
  stack1.pop();
  return 0;
}