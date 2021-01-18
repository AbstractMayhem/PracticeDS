#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct NodeType
{
char ch;
int freq;
struct NodeType *left;
struct NodeType *right;
}Node;

bool compareInterval(Node *i1, Node *i2) 
{ 
    return (i1->freq < i2->freq); 
} 

void buildTree(vector<Node*> &freqList)
{
}

int main(int argc,char *argv[])
{
	int arr[256];
	memset(arr,0,sizeof(arr));
	fstream file;
	string line;
	file.open("a.txt",ios::in|ios::out);
	if(!file)
	{
	cerr<<"Error in file opening"<<endl;
	cout<<"Exiting"<<endl;
	}
	else
	{
	while(getline(file,line))
	{
		if(file.eof())
		break;
		stringstream str(line);
		string word="";
		while(getline(str,word,' '))
		{
			for(int i=0;i<word.length();i++)
			{
			int asciiVal=(int)(word[i]);
			arr[asciiVal]++;
			}
		}
	}
	file.close();
	}
	//Printing Frequency
	//for(int i=0;i<=255;i++)
	//cout<<(char)(i)<<" := "<<arr[i]<<endl;

	vector<Node*> freqList;
	for(int i=0;i<=255;i++)
	{
	Node *newNode=new Node();
	newNode->ch=(char)i;
	newNode->freq=arr[i];
	newNode->left=NULL;
	newNode->right=NULL;
	freqList.push_back(newNode);
	}
	sort(freqList.begin(),freqList.end(),compareInterval);
	for(int i=0;i<=255;i++)
	{
		cout<<freqList[i]->ch<<" := "<<freqList[i]->freq<<endl;
	}
	return 0;
}
