#include<iostream>
//#include<time.h>
#include<random>

using namespace std;

class Base
{
public:
virtual void function1(){cout<<"In Function 1 of Base Class"<<endl;}
virtual void function2(){cout<<"In Function 2 of Base Class"<<endl;}
virtual void function3(){cout<<"In Function 3 of Base Class"<<endl;}
};

class Derived1:public Base
{
public:
void function1(){cout<<"In Function 1 of Derived1 Class"<<endl;}
void function2(){cout<<"In Function 2 of Derived1 Class"<<endl;}
};

class Derived2:public Base
{
public:
void function2(){cout<<"In Function 2 of Derived2 Class"<<endl;}
void function3(){cout<<"In Function 3 of Derived2 Class"<<endl;}
};

int main(int argc,char **argv)
{
srand(time(NULL));
Base *b;

//b->function1();
//b->function2();
//b->function3();
int num=rand()%10+1;
if(num>5)
{
Derived2 d2;
b=&d2;
}
else
{
Derived1 d1;
b=&d1;
}
if(dynamic_cast<Derived2*>(b)!=NULL)
{
Derived2 *d2obj=dynamic_cast<Derived2*>(b); 
d2obj->function2();
}
else
{
Derived1 *d1obj=dynamic_cast<Derived1*>(b); 
d1obj->function2();
}
return 0;
}