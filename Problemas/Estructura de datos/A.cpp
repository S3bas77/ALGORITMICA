#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    input;
    output;
    int numCar;
    while (cin >> numCar && numCar) { // Mientras haya datos y `numCar` sea positivo
        vector<int> positions(numCar, 0); // Vector para la parrilla de salida
        bool noSolution = false; // Bandera para indicar si hay solución

        for (int i = 0; i < numCar; i++) {
            int car, relativePos; // Leer número del auto y posición relativa
            cin >> car >> relativePos;

            // Calcular la posición final
            int finalPos = i + relativePos;

            // Verificar límites de posición
            if (finalPos >= numCar || finalPos < 0) {
                noSolution = true; // Posición fuera de rango
                break; // Salir si no es válido
            }

            // Verificar superposiciones
            if (positions[finalPos] != 0) {
                noSolution = true; // Ya está ocupada
                break;
            }

            positions[finalPos] = car; // Asignar el auto a la posición correcta
        }

        // Imprimir el resultado
        if (noSolution) {
            cout << -1 << endl; // No es posible reconstruir
        } else {
            cout << positions[0]; // Primer auto
            for (int i = 1; i < numCar; i++) {
                cout << " " << positions[i]; // Autos restantes
            }
            cout << endl; // Salto de línea al final
        }
    }

    return 0; // Termina el programa
}