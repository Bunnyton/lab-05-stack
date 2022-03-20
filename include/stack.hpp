// Copyright 2021 Your Name <your_email>

#ifndef LAB_05_STACK_STACK_HPP
#define LAB_05_STACK_STACK_HPP

#include <iostream>

template <typename T>
class Stack {
 private:
  struct Stack_body {
    T value;
    Stack_body* next;
  };

 private:
  Stack_body* _head;

 public:
  Stack() : _head(nullptr) {}
  explicit Stack(T&& val) noexcept { _head = new Stack_body(val, nullptr); }

  Stack(const Stack& st) = delete;
  Stack(Stack&& st) noexcept : _head(st._head) { st._head = nullptr; }

  void push(T&& value) {
    auto _new = new Stack_body{std::forward<T>(value), _head};
    _head = _new;
  }

  void push(const T& value) {
    auto _new = new Stack_body(value, _head);
    _head = _new;
  }

  void pop() {
    if (!_head) {
      throw std::out_of_range("Stack is empty!");
    } else {
      auto* helper = _head;
      _head = _head->next;
      delete helper;
    }
  }

  const T& head() {
    if (!_head) {
      throw std::out_of_range("Stack is empty!");
    } else {
      return _head->value;
    }
  }

  Stack& operator=(const Stack& st) = delete;
  Stack& operator=(Stack&& st) noexcept {
    if (this == &st) return *this;
    this->_head = st._head;
    st._head = nullptr;
    return *this;
  }

  ~Stack() {
      while (_head) {
        auto helper = _head;
        _head = _head->next;
        delete helper;
      }
  }
};

#endif  // LAB_05_STACK_STACK_HPP
