#include <iostream>


using namespace std;

int main(){
    double mA[2][3],mB[2][3];

    cout<<"Wprowadz macierz A:"<<endl;
     for (int i=0;i<2;i++){
        for (int j=0;j<3;j++) cin>>mA[i][j];
     }
    cout<<"Wprowadz macierz B:"<<endl;
    for (int i=0;i<2;i++){
        for (int j=0;j<3;j++) cin>>mB[i][j];
     }

    for (int i=0;i<2;i++){
        for (int j=0;j<3;j++) mA[i][j]+=mB[i][j];
     }

    

    cout<<"Wynik dodawania macierzy:"<<endl;
    for (int i=0;i<2;i++){
        for (int j=0;j<3;j++) cout<<mA[i][j]<<" ";
        cout<<endl;
     }



}