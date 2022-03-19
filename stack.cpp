#include <cstdlib>
#include <iostream>

template <class T> class Stack {
  int top;
  int n;
  T *arr;

public:
  Stack(int N) : top(-1), n(N) { arr = new T[n]; }
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == n - 1)
      return true;
    else
      return false;
  }
  void push(T elem) {
    if (!isFull())
      arr[++top] = elem;
    else
      std::cout << "Stack is Full" << std::endl;
  }
  T pop() {
    if (!isEmpty()) {
      arr[top] = 0;
      return arr[top--];
    } else
      std::cout << "Stack is Empty" << std::endl;
  }
  T peek() {
    if (!isEmpty())
      return arr[top];
    else
      std::cout << "Stack is Empty" << std::endl;
  }
  void printStack() {
    for (int i = 0; i < n; i++)
      std::cout << arr[i] << std::endl;
  }
  ~Stack() { delete arr; }
};

int main(int argc, char const *argv[]) {
  Stack<int> objI(10);
  for (int i = 1; i <= 10; i++)
    objI.push(i);

  objI.printStack();

  Stack<double> objD(20);
  for (int i = 1; i <= 20; i++)
    objD.push(i + 2.55);

  objD.printStack();

  return 0;
}
