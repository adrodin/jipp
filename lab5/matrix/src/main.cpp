
#include <iostream>
#include "matrix.hpp"
#include <ctime>

using namespace std;


int main() {

    try{
        cout<<"Proba utworzenia macierzy -1x-1"<<endl;
        Matrix matrix = Matrix(-1);
    } catch(invalid_argument &e){
        cout<<e.what()<<endl<<endl;
    }

    try{
        cout<<"Proba wpisania danych poza zakres zadeklarowanej macierzy"<<endl;
        Matrix matrix = Matrix(4);
        matrix.set(10,7,20);

    }catch(out_of_range &e){
        cout<<e.what()<<endl<<endl;
    }

    try{
        cout<<"Dodanwanie macierzy 2x3 i 5x6"<<endl;
        Matrix m1 = Matrix(2,3);
        Matrix m2 = Matrix(5,6);
        m1.add(m2);
    }catch(invalid_argument &e){
        cout<<e.what()<<endl<<endl;
    }

    try{
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

        //rows()
        cout << "rows()" << endl;
        cout << m3.rows() << endl;
        //cols()
        cout << "cols()" << endl;
        cout << m3.cols() << endl;

        //zapisanie m1 do pliku
        m1.print();
        m1.store("matrix.txt", ".");

        //odczytanie m1 z pliku
        Matrix m5("./matrix.txt");
        cout<<"m5:\n";
        m5.print();

    } catch(invalid_argument &e){
        cout<<e.what()<<endl<<endl;
    } catch(out_of_range &e){
        cout<<e.what()<<endl<<endl;
    } catch(runtime_error &e){
        cout<<e.what()<<endl<<endl;
    }



    

}


