#include <algorithm> // to use sort function
#include <cstring>   // for inclusion of memset function
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

map<char, string> codeDict;

typedef struct NodeType {
  unsigned char ch;
  int freqInfo;
  string code;
  struct NodeType *left;
  struct NodeType *right;
} Node;

int compareInterval(Node *ifirst, Node *isecond) {
  return ifirst->freqInfo < isecond->freqInfo;
}

// it is not a binary Tree it is a max heap tree
void buildTree(vector<Node *> &freqList) {
  while (freqList.size() > 1) {
    Node *newNode = new Node();
    newNode->ch = '\0';
    newNode->freqInfo = freqList[0]->freqInfo + freqList[1]->freqInfo;
    newNode->code = "";
    newNode->left = freqList[0];
    newNode->right = freqList[1];

    freqList.push_back(newNode);
    freqList.erase(freqList.begin());
    freqList.erase(freqList.begin());
    sort(freqList.begin(), freqList.end(), compareInterval);
  }
}

// Function to traverse the tree
void traverseTree(Node *root) {
  if (root != NULL) {
    traverseTree(root->left);
    if (root->left == NULL && root->right == NULL) {
      cout << root->ch << " := " << root->freqInfo << " == " << root->code
           << endl;
    }
    traverseTree(root->right);
  }
}

// Function to encode the tree with 0 and 1
void encodeTree(Node *root, Node *par, string str) {
  if (root == NULL) {
    par->code = str;
    codeDict.insert({par->ch, par->code});
    return;
  } else {
    encodeTree(root->left, root, str + '1');
    encodeTree(root->right, root, str + '0');
  }
}

// ENCODE THE FILE USING HUFFMAN CODING
void encodeFile(string file_name) {
  fstream file;
  fstream encoded_file;
  encoded_file.open("encoded_file.dat", ios::binary | ios::out);
  file.open(file_name, ios::in);
  if (!file && !encoded_file) {
    cerr << "Error in creating either " << file_name
         << "or encoded_file.dat file!!" << endl;
    return;
  } else {
    string line;
    while (getline(file, line)) {
      for (int i = 0; i < line.length(); i++) {
        char x = line[i];
        string val = codeDict[x];
        encoded_file.write(val.c_str(), (val.length()) * sizeof(char));
      }
      // encoded_file<<"\n";
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Usage :- ./a.out <file_name>" << endl;
    return -1;
  }
  int count = 0; // count the number of words
  int arr[256];  // arr to hold the frequency of the characters occured in the
                 // word
  memset(arr, 0, sizeof(arr));
  string file_name = argv[1];
  fstream file;
  file.open(file_name);
  if (!file) {
    cerr << "Error in opening file!!!" << endl;
    exit(0);
  } else {
    string line;
    while (getline(file, line)) {
      // stringstream str(line);
      // string word;
      // while(getline(str,word,' '))
      //{
      // cout<<word<<endl;
      for (int i = 0; i < line.length(); i++) {
        int asciiVal = (int)line[i];
        arr[asciiVal]++;
      }
      count++;
      //}// End of while loop for each word
    } // End of while loop for each line
    file.close();
  }

  vector<Node *> freqList; // vector pointer to store the frequencies of
                           // characters in a file

  for (int i = 0; i < 128; i++) {
    if (arr[i] != 0) {
      Node *newNode = new Node();
      cout << (unsigned char)i << ",";
      cout << arr[i] << endl;
      newNode->ch = (unsigned char)i;
      newNode->freqInfo = arr[i];
      newNode->code = "";
      newNode->left = NULL;
      newNode->right = NULL;
      freqList.push_back(newNode);
    }
  }

  sort(freqList.begin(), freqList.end(), compareInterval);

  buildTree(freqList);

  // map<char,string>codingDict;//Store the codes according to their characters
  encodeTree(freqList[0], NULL, "");
  // cout<<freqList.at(0)->right->right->freqInfo;

  traverseTree(freqList[0]);

  encodeFile(file_name);

#if 0
cout<<"Total Number of Words:- "<<count<<endl;
cout<<"Printing Frequency of Characters !!!"<<endl;
for(int i=0;i<128;i++)
cout<<(unsigned char)i<<" := "<<arr[i]<<"\n";

for(auto i : freqList)
{
cout<<i->ch<<" := "<<i->freqInfo<<"\n";
}
#endif
  return 0;
}
