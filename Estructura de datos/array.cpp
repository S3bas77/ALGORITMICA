#include<bits/stdc++.h>
using namespace std;
int main() {
    int array[10];//X  // Se genera un array como este: [0,0,0,0,0,0,0,0,0,0]
    // cuidado no siempre se inicializa en 0. entonces se utiliza un for ahora
    memset(array, 0, 10);
    for(int i = 0; i< 10; i++) {
        array[i] = 0;
    }
    return 0;
}