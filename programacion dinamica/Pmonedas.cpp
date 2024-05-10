#include<bits/stdc++.h>
using namespace std;
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
int coins[3] = {2, 3, 5};
int dp[4][1000];
int f(int n){
    dp[0][0]=1;
    for(int i = 1; i <= 3; i++){
        dp[i][0]=1;
        for(int j = 1; j <= n;j++){
            dp[i][j]=dp[i-1][j];
            if(j-coins[i-1] >= 0){
                dp[i][j] += dp[i][j - coins[i-1]];
            }
        }
    }
    return dp[3][n];
}
int dp3[1000];
int f3(int n){
    dp3[0]=1;
    for(int i = 1; i<=n; i++){
        dp3[i]=0;
        for(int j = 0; i<3; j++){
            if(i-coins[j]>=0){
                dp3[i]+=dp3[i-coins[j]];
            }
        }
    }
    return dp3[n];
}