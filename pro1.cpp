#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

template <typename T> int noOfOcurrences(T (&arr)[100], int n, T &value) {
  int count = 0;
  for (int i = 0; i < n; ++i)
    if (arr[i] == value)
      count++;
  return count;
}

template <typename T> void fill(T (&arr)[100]) {
  for (int i = 0; i < 100; ++i)
    arr[i] = 2 * (i + 1);
}

template <typename T> T inner_product(T (&a)[100], T (&b)[100]) {
  T res = 0.0;
  for (int i = 0; i < 100; ++i)
    res += a[i] * b[i];
  return res;
}

int main(int argc, char *argv[]) {
  int x = 3, y = 4;
  swap(x, y);
  printf("\n x=%d \n y=%d", x, y);

  float a[100];
  float val = 34.000;
  fill<float>(a);
  fill<float>(b);
  printf("No Of Occurences of %f is %d", val,
         noOfOcurrences<float>(a, 100, val));

  return 0;
}
