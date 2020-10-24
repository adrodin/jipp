#include <iostream>

using namespace std;

bool isPalindrom(string word){
    for(int i=0;i<word.length()/2;i++){
        if(word[i]!=word[word.length()-i-1]) return false;
    }

    return true;
}

int main(int argc, char *arg[]){
  cout<<"Jest palindromem: ";
  if(isPalindrom(arg[1])) cout<<"TAK";
  else cout<<"NIE";
  cout<<endl;

}