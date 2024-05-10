#include <bits/stdc++.h>
using namespace std;

std::vector<int> minCoinsAndCoinsUsed(int objeto, const std::vector<int>& denominaciones) {
    std::vector<int> dp(objeto + 1, INT_MAX);
    std::vector<int> moneda_usada(objeto + 1, -1);
    dp[0] = 0;
    for (int coin : denominaciones) {
        for (int j = coin; j <= objeto; j++) {
            if (dp[j - coin] != INT_MAX && dp[j - coin] + 1 < dp[j]) {
                dp[j] = dp[j - coin] + 1; 
                moneda_usada[j] = coin; 
            }
        }
    }

    if (dp[objeto] == INT_MAX) {
        return {};
    }
    std::vector<int> coins;
    int current = objeto;
    while (current > 0) {
        coins.push_back(moneda_usada[current]);
        current -= moneda_usada[current];
    }

    return coins;
}

int main() {
    std::vector<int> denominaciones = {2, 3, 5};
    int objeto = 15;
    std::vector<int> coins = minCoinsAndCoinsUsed(objeto, denominaciones);

    if (coins.empty()) {
        std::cout << "no hay monedas" << std::endl;
    } else {
        std::cout << "Las monedas utilizadas para formar el monto son: ";
        for (int coin : coins) {
            std::cout << coin << " ";
        }
        std::cout << std::endl;
        std::cout << "El mínimo número de monedas necesarias es: " << coins.size() << std::endl;
    }
    return 0;
}
