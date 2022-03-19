#include <math.h>
#include <stdio.h>
void fun() { printf("\nHello World from Fun function!!!."); }
void fun1() { printf("\nHello World from Fun 1 function!!!."); }
void fun2() { printf("\nHello World from Fun 2 function!!!."); }
void fun3() { printf("\nHello World from Fun 3 function!!!."); }
void fun4() { printf("\nHello World from Fun 4 function!!!."); }
void fun5() { printf("\nHello World from Fun 5 function!!!."); }

int main(int argc, char const *argv[]) {
  void (*fun_ptr[5])();
  fun_ptr[0] = fun;
  fun_ptr[1] = fun1;
  fun_ptr[2] = fun2;
  fun_ptr[3] = fun3;
  fun_ptr[4] = fun4;
  // fun_ptr[5]=fun;

  for (int i = 0; i < 5; i++) {
    fun_ptr[i]();
  }
  printf("\n");
  return 0;
}
