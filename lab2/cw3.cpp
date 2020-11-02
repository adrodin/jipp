#include <iostream>
#include <algorithm>

using namespace std;

void fun(int &a,int *b){
    int tmp=a;
    a=*b;
    *b=tmp;

}

int main()
{
    int a=10,b=11;
    cout<<a<<" "<<b<<endl;
    fun(a,&b);
    cout<<a<<" "<<b;

}