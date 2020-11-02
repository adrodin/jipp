#include <iostream>
#include <algorithm>

using namespace std;

template <class T> void swap(T **a, T **b) {
    T *tmp = *a;
      *a = *b;
    *b = tmp;
}

int main()
{
    string a="aaaaaa",b="bbbbbb";
    string *ptrA=&a,*ptrB=&b;
    cout<<*ptrA<<" "<<*ptrB<<endl;
    swap(&ptrA,&ptrB);
    cout<<*ptrA<<" "<<*ptrB;

    cout<<endl<<endl;

    int c=10,d=11;
    int *ptrC=&c,*ptrD=&d;
    cout<<*ptrC<<" "<<*ptrD<<endl;
    swap(&ptrC,&ptrD);
    cout<<*ptrC<<" "<<*ptrD;


}