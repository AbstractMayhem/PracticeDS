#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
int n;
scanf("%d",&n);
string str;
for(int i=1;i<=n;++i){
getline(cin,str);
while(str.length()==0)getline(cin,str);
printf("\n%s",str.c_str());
}
return 0;
}


