#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    int n;
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