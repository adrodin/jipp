#include <iostream>

using namespace std;

int sumOfDivisors(int a){
    int sum=1;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            if(i*i!=a){
            sum+=i;
            sum+=a/i;
            }
            else sum+=i;
        }
    }
    return sum;
}

bool is(int a,int sum){
    return a+1==sum;
}

int main(){
    int a,b;
    int sumA,sumB;
    cout<<"Podaj liczbe a: ";
    cin>>a;
    cout<<"Podaj liczbe b: ";
    cin>>b;
    sumA = sumOfDivisors(a);
    sumB = sumOfDivisors(b);
    cout<<"Skojarzone: ";
    if(is(a,sumB)&&(b,sumA)) cout<<"TAK";
    else cout<<"NIE";
}