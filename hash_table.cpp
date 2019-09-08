#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
//#include<functional>

using namespace std;

struct NodeType{
string str;
struct NodeType *next;
NodeType(){str="";next=NULL;}
NodeType(string st){str=st;next=NULL;}
~NodeType(){}
};
typedef struct NodeType Node;

class HashTable{
int N;
Node **hashTable;
public:
HashTable(int n):N(n){hashTable=new Node*[N];}
void insertHT(string str);
void searchHT(string str);
friend void printHT(HashTable &ht);
~HashTable(){
for(int i=0;i<N;++i)
{
Node *ptr=hashTable[i];
Node *prev=NULL;
while(ptr!=NULL)
{
prev=ptr;
ptr=ptr->next;
delete prev;
}
hashTable[i]=NULL;
}
}
};

#if 1
static long hashFunction(string str)
{
hash<string> hash_fn;
unsigned long hash=hash_fn(str);
return hash;
}
#endif

#if 0
static long hashFunction(string str)
{
int seed=131;
unsigned long hash=0;
//#pragma omp parallel for reduction(+:hash)
for(int i=0;i<str.length();++i)
hash=(hash*seed)+str[i];

return hash;
}
#endif

#if 0
static long hashFunction(string str)
{
long hashVal=1;
srand(time(0));
int randVal=(rand()%40000)+1;
#if 0
for(int i=0;i<str.length();++i)
{
hashVal*=(int)str[i];
}
#endif
return randVal;
}
#endif

void HashTable::insertHT(string str){
Node *newNode=new Node(str);
unsigned long hashVal=hashFunction(str);
long index=hashVal % N;
if(hashTable[index]!=NULL){
Node *ptr=hashTable[index];
newNode->next=ptr;
hashTable[index]=newNode;
}
else
{
hashTable[index]=newNode;
}
}

void printHT(HashTable &ht)
{
for(int i=0;i<ht.N;++i)
{
Node *ptr=ht.hashTable[i];
if(ptr==NULL)
{
printf("\n[%d] -> NULL",i);
}
else
{
printf("\n[%d] -> ",i);
while(ptr!=NULL){printf("%s,",(ptr->str).c_str());ptr=ptr->next;}
}
}
printf("\n");
}

void HashTable::searchHT(string str)
{
unsigned long hashVal=hashFunction(str);
long index=hashVal % N;
int pos=1;
Node *ptr=hashTable[index];
while(ptr!=NULL&&ptr->str!=str)
{
ptr=ptr->next;
++pos;
}
if(ptr==NULL)
printf("\n%s is not found in hash table. It is not stored!!!",str.c_str());
else
printf("\nFound %s At Index %ld At Position %d",str.c_str(),index,pos);
}

int main(int argc,char *argv[])
{
if(argc!=3)
{
printf("\nThree Arguments Needed!!!");
printf("\n Second Argument is file name \n Third Argument is length of hash table.\n\n");
exit(0);
}
int len=atoi(argv[2]);
string fileName=argv[1];
HashTable htable(len);
int n;
//printf("\nEnter the value of number of Strings");
//scanf("%d",&n);
string st;
ifstream myfile;
myfile.open(fileName);
if(myfile.is_open())
{
while(getline(myfile,st))
{
htable.insertHT(st);
}
myfile.close();
}

#if 0
for(int i=1;i<=n;++i)
{
getline(cin,st);
while(st.length()==0)
getline(cin,st);
htable.insertHT(st);
}
#endif
printHT(htable);
htable.searchHT("the");
printf("\n");
return 0;
}
