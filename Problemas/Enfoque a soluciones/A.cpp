#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    cout << fixed << setprecision(2);
    int n;
    while (cin >> n && n >= 1 && n <= 100) {
        double valor, result = 0;
        for (int i = 0; i < 12; i++) {
            cin >> valor;
            result += valor;
        }
        cout.imbue(locale(""));
        cout << n << " $" << result / 12 << endl;
    }
    return 0;
}