#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    int n;
    cin >> n;
    while(n <= pow(10,3) && n >= 1) {
        for (int i = 1; i <= n; i++)
        {
            cout<<i;
        }
    }
}