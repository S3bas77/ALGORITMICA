#include<bits/stdc++.h>
using namespace std;
//en este codigo se genera un vector de tamaño 10, y tambien se ve la funcionalidad de push_back
int main() {
    vector<string> vector(10,"Sebas");
    vector.push_back("Esta es la ultima fila");
    // ["Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas"]
    cout<<"tamaño del vector: "<< vector.size()<<endl;
    for(int i = 0 ; i < vector.size() ; i++) {
    	cout<<i<<". "<< vector[i]<<endl;
    }
    return 0;
}