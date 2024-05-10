#include <bits/stdc++.h>
using namespace std;

int w[4] = { 1, 3, 3, 10 };  // Pesos de los objetos
int g[4] = { 1000, 1500, 500, 3000 };  // Valores de los objetos
int n = 4;  // Número de objetos
int maxWeight = 15;  // Peso máximo permitido en la mochila

void bu() {
    // Crear la matriz de DP para almacenar valores máximos para cada peso
    vector<vector<int>> dp2(n + 1, vector<int>(maxWeight + 1, 0));

    // Implementación de la solución para el problema de la mochila 0/1
    for (int i = 1; i <= n; i++) {  // Recorrer objetos
        for (int j = 0; j <= maxWeight; j++) {  // Recorrer pesos
            if (w[i - 1] <= j) {  // Si el peso del objeto cabe en la mochila
                dp2[i][j] = max(g[i - 1] + dp2[i - 1][j - w[i - 1]], dp2[i - 1][j]);
            } else {  // Si no cabe
                dp2[i][j] = dp2[i - 1][j];
            }
        }
    }

    // Imprimir la matriz de DP
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            cout << "[" << dp2[i][j] << "]";
        }
        cout << endl;
    }
}

int main() {
    bu();  // Llamada a la función para resolver el problema de la mochila
    return 0;
}
