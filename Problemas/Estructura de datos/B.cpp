#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    int S, B;
    while (true) {
        cin >> S >> B;
        if (S == 0 && B == 0) break;
        vector<int> izq(S + 1), der(S + 1);
        for (int i = 1; i <= S; ++i) {
            izq[i] = i - 1;
            der[i] = i + 1;
        }
        der[S] = 0;
        for (int i = 0; i < B; ++i) {
            int L, R;
            cin >> L >> R;
            int newIzq = izq[L];
            int newDer = der[R];
            if (newIzq == 0) {
                cout << "* ";
            } else {
                cout << newIzq << " ";
            }
            if (newDer == 0) {
                cout << "*" << endl;
            } else {
                cout << newDer << endl;
            }
            der[newIzq] = newDer;
            izq[newDer] = newIzq;
        }
        cout << "-" << endl;
    }

    return 0;
}