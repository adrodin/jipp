#include <iostream>
#include <algorithm>

using namespace std;

void mySwap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;

}

int main()
{
    int a=10,b=11;
    cout<<a<<" "<<b<<endl;
    mySwap(a,b);
    cout<<a<<" "<<b;
}