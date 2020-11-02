#include <iostream>
#include <algorithm>

using namespace std;

void swapIfSmaller(int *a, int *b) {
    if (*b<*a) {
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }
}

int main()
{
    
    int a=10,b=11;
    cout<<a<<" "<<b<<endl;
    swapIfSmaller(&a,&b);
    cout<<a<<" "<<b<<endl<<endl;

     a=11;
     b=10;
    cout<<a<<" "<<b<<endl;
    swapIfSmaller(&a,&b);
    cout<<a<<" "<<b;
    
}