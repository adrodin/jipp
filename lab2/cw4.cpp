#include <iostream>
#include <algorithm>

using namespace std;

int fun(int a,int b,int *product){
        *product = a*b;

        return a+b;
}

int main()
{
    int a=10,b=11,product;
    int sum = fun(a,b,&product);
    cout<<sum<<" "<<product;
}