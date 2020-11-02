#include <iostream>
#include <algorithm>

using namespace std;

template <class T> void sWap(T *a,T *b){
    T tmp = *a;
    *a=*b;
    *b=tmp;

}

int main()
{
    string a="aaaaa",b="bbbbbb";
    cout<<a<<" "<<b<<endl;
    sWap(&a,&b);
    cout<<a<<" "<<b<<endl<<endl;

    int c=10,d=11;
    cout<<c<<" "<<d<<endl;
    sWap(&c,&d);
    cout<<c<<" "<<d;
}