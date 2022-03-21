// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_STACK_ARGS_HPP_
#define INCLUDE_STACK_ARGS_HPP_

#include <iostream>
#include <string>
#include <utility>

template <typename T>
class StackArgs {
 private:
  struct StackArgs_body {
    T value;
    StackArgs_body* next;
  };

 private:
  StackArgs_body* _head;

 public:
  StackArgs() : _head(nullptr) {}
  explicit StackArgs(T&& val) noexcept {
    _head = new StackArgs_body(val, nullptr);
  }

  StackArgs(const StackArgs& st) = delete;
  StackArgs(StackArgs&& st) noexcept : _head(st._head) { st._head = nullptr; }

  void push(T&& value) {
    auto _new = new StackArgs_body{std::forward<T>(value), _head};
    _head = _new;
  }

  void push(const T& value) {
    auto _new = new StackArgs_body{value, _head};
    _head = _new;
  }

  template <typename... Args>
  void push_emplace(Args&&... args) {
    auto _new = new StackArgs_body{{std::forward<Args>(args)...}, _head};
    _head = _new;
  }

  T pop() {
    if (!_head) {
      throw std::out_of_range("StackArgs is empty!");
    } else {
      auto* helper = _head;
      auto data = _head->value;
      _head = _head->next;
      delete helper;
      return data;
    }
  }

  const T& head() {
    if (!_head) {
      throw std::out_of_range("StackArgs is empty!");
    } else {
      return _head->value;
    }
  }

  StackArgs& operator=(const StackArgs& st) = delete;
  StackArgs& operator=(StackArgs&& st) noexcept {
    if (this == &st) return *this;
    this->_head = st._head;
    st._head = nullptr;
    return *this;
  }

  ~StackArgs() {
    while (_head) {
      auto helper = _head;
      _head = _head->next;
      delete helper;
    }
  }
};

#endif  // INCLUDE_STACK_ARGS_HPP_
