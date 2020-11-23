
#include <iostream>
#include "matrix.hpp"
#include <ctime>

using namespace std;


int main() {

    //zadeklarowanie macierzy (pierwszy konstruktor)
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

    //pobranie jednej wartości
    cout << "Wartosc M1[3,3]" << endl;
    cout << m1.get(2, 2) << endl;

   

    //dodawanie
    Matrix m3 = m1.add(m2);
    cout << "Wynik dodawania m1 do m2" << endl;
    m3.print();

    //odejmowanie
    
    m3 = m1.substract(m2);
    cout << "Wynik odejmowania m2 od m1" << endl;
    m3.print();

    //mnozenie
    m3 = m1.multiply(m2);
    cout << "Mnozenie m1 przez m2" << endl;
    m3.print();

    //drugi konstruktor
    cout<<"Drugi konstruktor"<<endl;
    Matrix m4 = Matrix(4, 5);

    //losowe wypelnienie m4
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            m4.set(i, j, rand() % 10);
        }
    }
    m4.print();
    //rows()
    cout << "rows()" << endl;
    cout << m4.rows() << endl;
    //cols()
    cout << "cols()" << endl;
    cout << m4.cols() << endl;

    //zapisanie m1 do pliku
    m1.store("matrix.txt", ".");

    //odczytanie m1 z pliku
    Matrix m5("./matrix.txt");

    //wypisanie macierzy otrzymanej z pliku
    cout << "wypisanie macierzy otrzymanej z pliku" << endl;
    m5.print();

}


