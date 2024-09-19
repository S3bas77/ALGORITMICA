#include <bits/stdc++.h>
using namespace std;
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
    string usuario;
    cin >> usuario;
    
    set<char> hero;
    
    for (char c : usuario) {
        hero.insert(c);
    }
    
    if (hero.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;
    } else {
        cout << "IGNORE HIM!" << endl;
    }
    
    return 0;
}