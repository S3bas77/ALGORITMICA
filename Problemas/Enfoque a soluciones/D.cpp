#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

vector<int> acumulativo(int MaxGrupo) {
    vector<int> acumulativo(MaxGrupo + 1);
    acumulativo[0] = 0;  
    for (int i = 1; i <= MaxGrupo; i++) {
        acumulativo[i] = acumulativo[i - 1] + i;
    }
    return acumulativo;
}


int TotalMonedas(int dias) {
    int grupo = 1;  
    int acumulativo = 1; 
    while (acumulativo < dias) {
        grupo++;
        acumulativo += grupo;
    }
    
    int previo_acumulativo = acumulativo - grupo;
    
    int TotalMonedas = 0;
    for (int i = 1; i < grupo; i++) {
        TotalMonedas += i * i;  
    }
    
    int diasAdicionales = dias - previo_acumulativo;
    TotalMonedas += diasAdicionales * grupo;
    return TotalMonedas;
}
int main() {
    int testBloques;
    cin >> testBloques;  
    for (int bloque = 0; bloque < testBloques; bloque++) {
        int contadorDias;
        bool isFirstCase = true; 
        while (cin >> contadorDias && contadorDias != 0) {
            int monedas = TotalMonedas(contadorDias);  
            cout << contadorDias << " " << monedas << endl;
            isFirstCase = false;  
        }
        if (bloque < testBloques - 1) {
            cout << endl;
        }
    }
    return 0;
}
