#include <bits/stdc++.h>
using namespace std;

// Estructura para almacenar resultados de subproblemas (memoization)
vector<int> memo;

// Recursión para encontrar la cantidad mínima de monedas
int minCoinsRec(int n, const vector<int>& coins) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        return INT_MAX;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int minCoins = INT_MAX; 
    for (int coin : coins) {
        int subResult = minCoinsRec(n - coin, coins);

        if (subResult != INT_MAX) {
            minCoins = min(minCoins, 1 + subResult); 
        }
    }
    memo[n] = minCoins;
    return minCoins;
}

int main() {
    vector<int> denominations = {2,3,5};
    int amount = 15;
    memo.assign(amount + 1, -1);
    int minimumCoins = minCoinsRec(amount, denominations);
    if (minimumCoins == INT_MAX) {
        cout << "ERROR, cantidad negativa" << endl;
    } else {
        cout << "Cantidad mínima de monedas requeridas: " << minimumCoins << endl;
    }

    return 0;
}

