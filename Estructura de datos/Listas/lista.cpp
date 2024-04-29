#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    output;
    list<int> lista; 
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    list<int>::iterator iterador; //Se crea un iterador
    
    iterador = lista.begin(); 
    cout << *iterador << endl; 
    //Dicho iterador irá desde el inicio de la lista definida 
    //hasta el final de la misma
    for (iterador = lista.begin(); iterador != lista.end(); iterador++) {
        cout << *iterador << endl;
    }
    return 0;
}