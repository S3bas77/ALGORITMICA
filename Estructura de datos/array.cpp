#include<bits/stdc++.h>
using namespace std;
int main() {
    int array[10];//X  // array [0,0,0,0,0,0,0,0,0,0]
    // cuidado no siempre se inicializa en 0 
    memset(array, 0, 10);
    for(int i = 0; i< 10; i++) {
        array[i] = 0;
    }
    return 0;
}