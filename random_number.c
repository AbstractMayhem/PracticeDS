#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int x = rand() % 100;
  // printf("%d",x);
  int a = 23;
  int *c = &a;

  printf("\n%d", *c);

#pragma omp parallel
  { printf("Hello World!!!"); }
  return 0;
}
