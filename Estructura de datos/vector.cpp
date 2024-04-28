#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string> vectorcito(10,"Sebas");
    vectorcito.push_back("Aprobado");
    // ["Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas","Sebas"]
    cout<<"tamaño del vector: "<< vectorcito.size()<<endl;
    for(int i = 0 ; i < vectorcito.size() ; i++) {
    	cout<<i<<". "<< vectorcito[i]<<endl;
    }
    return 0;
}