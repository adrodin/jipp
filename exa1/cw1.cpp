#include <iostream>
#include <algorithm>

using namespace std;



int main(int argc, char *arg[])
{

    int *tab = new int[argc-1];

    for(int i=0;i<argc;i++){
        tab[i] = atoi(arg[i+1]);

    }

   sort(tab,tab+argc-1);

   cout<<"out = ";
   for(int i=0;i<argc-1;i++){
       cout<<tab[i]<<" ";
   }


   delete []tab;

}