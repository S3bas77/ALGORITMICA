//Una secuencia de n>0 enteros se llama "jolly jumper" si los valores absolutos de las 
//diferencias entre elementos sucesivos toman todos los valores desde 1 hasta n−1. 
//Por ejemplo:
//1 4 2 3
//es un jolly jumper, porque las diferencias absolutas son 3, 2 y 1 respectivamente. 
//La definición implica que cualquier secuencia de un solo entero es un jolly jumper. 
//Debes escribir un programa para determinar si una secuencia dada es un jolly jumper.

//Entrada
//Cada línea de entrada contiene un entero n ≤ 3000, seguido de n enteros que representan 
//la secuencia. Los valores en la secuencia tienen como máximo un valor absoluto de 300,000. 
//La entrada contiene como máximo 10 líneas.

//Salida
//Para cada línea de entrada, genera una línea de salida que diga “Jolly” o “Not jolly”.

#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    input;
    output;
    int n;//longitud de la secuencia
    while (cin >> n) {
        vector<int> sequencia(n);
        vector<bool> difExiste(n - 1, false);
        for (int i = 0; i < n; ++i) {
            cin >> sequencia[i];
        }
        for (int i = 1; i < n; ++i) {
            int dif = abs(sequencia[i] - sequencia[i - 1]);
            if (dif >= 1 && dif <= n - 1) {
                difExiste[dif - 1] = true;
            }
        }
        bool Jolly = true;
        for (bool existe : difExiste) {
            if (!existe) {
                Jolly = false;
                break;
            }
        }
        if (Jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}