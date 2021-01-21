
#include <iostream>
#include "matrix.hpp"
#include <ctime>

using namespace std;

void cmp(Matrix &m1,Matrix &m2){
    if(m1==m2) cout<<"Macierze sa takie same"<<endl;
    else cout<<"Macierze nie sa takie same"<<endl;

}

int main() {

  
    Matrix m1 = Matrix(4);
    Matrix m2 = Matrix(4);

    //losowe wypełnienie macierzy m1 i m2
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m1.set(i, j, rand() % 10);
            m2.set(i, j, rand() % 10);
        }
    }

    //wypisanie m1 i m2
    cout << "M1:" << endl;
    m1.print();
    cout << "M2:" << endl;
    m2.print();


    //dodawanie
    Matrix m3 = m1+m2;
    cout << "Wynik dodawania m1 do m2" << endl;
    m3.print();

     //odejmowanie
    m3 = m1-m2;
    cout << "Wynik odejmowania m2 od m1" << endl;
    m3.print();

    //mnozenie
    m3 = m1*m2;
    cout << "Mnozenie m1 przez m2" << endl;
    m3.print();

    //operator ==
    cout<<"Operator =="<<endl;
    cout<<"m1 == m2"<<endl;
    cmp(m1,m2);
    cout<<"m1 == m1"<<endl;
    cmp(m1,m1);

    //operator ++
    cout<<"m1 przed ++"<<endl;
    m1.print();
    m1++;
    cout<<"m1 po ++"<<endl;
    m1.print();

     //operator --
    cout<<"m1 przed --"<<endl;
    m1.print();
    m1--;
    cout<<"m1 po --"<<endl;
    m1.print();


}


