#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  string line;
  ifstream myfile;
  myfile.open("20k.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      cout << line << endl;
    }
    myfile.close();
  }
  return 0;
}
