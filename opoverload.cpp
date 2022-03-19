#include <iostream>
using namespace std;

template <typename T> class Box {
  T length;
  T breadth;
  T height;

public:
  Box(T l = 0, T b = 0, T h = 0) : length(l), breadth(b), height(h) {}
  void setLength(T length) { this->length = length; }
  void setBreadth(T breadth) { this->breadth = breadth; }
  void setHeight(T height) { this->height = height; }
  T getLength() { return length; }
  T getBreadth() { return breadth; }
  T getHeight() { return height; }
  // Operator Overloading
  Box operator+(const Box &x) {
    Box box;
    box.length = this->length + x.length;
    box.breadth = this->breadth + x.breadth;
    box.height = this->height + x.height;
    return box;
  }

  friend ostream &operator<<(ostream &output, const Box &b) {
    output << "(Length,Breadth,Height)=(" << b.length << "," << b.breadth << ","
           << b.height << ")" << endl;
    ;
    return output;
  }
  friend istream &operator>>(istream &input, const Box &b) {
    input >> b.length >> b.breadth >> b.height;
    return input;
  }
};

int main(int argc, char const *argv[]) {
  Box<int> b1(10, 20, 30);
  Box<int> b2(40, 50, 60);
  Box<int> b3 = b1 + b2;
  cout << b3 << endl;
  return 0;
}
