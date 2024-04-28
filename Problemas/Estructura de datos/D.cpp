#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    int N;
    while (cin >> N && N != 0) {
        vector<string> circle(N, ""); // Círculo de cartas
        int currentIndex = 0; // Índice para la posición actual

        // Leer las cartas y las palabras
        vector<pair<string, string>> cards(N);
        for (int i = 0; i < N; i++) {
            cin >> cards[i].first >> cards[i].second; // Carta y palabra
        }

        // Colocar las cartas en el círculo
        for (int i = 0; i < N; i++) {
            const string& card = cards[i].first;
            const string& word = cards[i].second;

            // Número de movimientos a contar
            int moveCount = word.length();

            // Mover en el círculo para encontrar la posición vacía
            while (moveCount > 0) {
                if (circle[currentIndex] == "") { // Si la posición está vacía
                    moveCount--; // Reducir el número de movimientos restantes
                }

                if (moveCount > 0) { // Sólo avanzar si aún hay movimientos por hacer
                    currentIndex = (currentIndex + 1) % N; // Mover al siguiente
                }
            }

            // Colocar la carta en la posición encontrada
            circle[currentIndex] = card;

            // Mover al siguiente para la siguiente cuenta
            currentIndex = (currentIndex + 1) % N;
        }

        // Imprimir el resultado
        for (int i = 0; i < N; i++) {
            if (i > 0) {
                cout << " "; // Espacio entre cartas
            }
            cout << circle[i]; // Imprimir la carta en la posición
        }
        cout << endl;
    }

    return 0;
}
