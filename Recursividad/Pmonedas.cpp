#include<bits/stdc++.h>

using namespace std;
//usando recursividad
int coins[3] = { 2, 3 , 5};
int dp[100000];
int f(int n) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    if(dp[n] == -1) { // alguna vez no he calculado el valor de f(n)
        int ans = 0;
        for(int i = 0; i < 3; i++) {
            ans += f(n - coins[i]); 
        }
        dp[n] = ans;
    }
    return dp[n];
}
int dp2[4][1000];
int f2(int n) {
    for(int i = 0; i <= 3; i++) {// 2, 3, 5
        dp2[i][0] = 1;
        for(int j = 1; j <= n; j++) { // 1 ==> 15
            dp2[i][j] = dp2[i-1][j];
            if(j - coins[i-1] >= 0) {
                dp2[i][j] += dp2[i][j - coins[i-1]];
            }
        }
    }
    return dp2[3][n];
}

int main() {
    int n = 15;
    memset(dp2, -1, sizeof(dp2));
    cout<<f2(n)<<endl;
}