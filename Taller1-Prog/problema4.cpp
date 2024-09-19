#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main(){
    string hello;
    cin>>hello;
    string target = "hello"; 
    int j = 0;
    for (int i = 0; i < hello.length(); i++) {
        if (hello[i] == target[j]) {
            j++;
        }
        if (j == target.length()) {
            break;
        }
    }
    if (j == target.length()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
