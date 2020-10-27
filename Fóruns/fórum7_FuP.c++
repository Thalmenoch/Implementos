#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void fun(string name, int birth){
    cout << "Digite seu nome : ";
    getline(cin, name); 
    
    cout << "Digite sua data de nascimento: "; 
    cin >> birth;

    cout << "Olá " << name << ", você possui " << 2020 - birth << " !" << endl; 
}

int main() {
    string y;
    int x;
    fun(y, x);
}
