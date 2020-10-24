#include <iostream>
#include <iomanip>
using namespace std;



int main(){
    double weight;
    double height;
    double bmi;

    cout<<"Podaj wzrost i wage"<<endl<<"Wzrost(cm): ";
    cin>> height;
    cout<<"Waga(kg): ";
    cin>>weight;

    bmi = weight/(height*height/10000);
    cout<<"Twoje BMI to: ";
    cout<<setprecision(4)<<bmi<<" - ";

    if(bmi<16) cout<<"wyglodzenie";
    else{
        if(bmi<17) cout<<"wychudzenie";
        else{
            if(bmi<18.5) cout<<"niedowaga";
            else{
                if(bmi<25) cout<<"wartosc prawidlowa";
                else{
                    if(bmi<30) cout<<"nadwaga";
                    else{
                        if(bmi<35)cout <<"I stopien otylosci";
                        else{
                            if(bmi<40) cout<<"II stopien otylosci";
                            else cout<<"otylosc skrajna";
                        }
                    }
                }
            }
        }
    }





    return 0;
}