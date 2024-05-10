#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
long long fibo(long long n){
    if(n<=2){
        return 1;
    } else {
        
        return fibo(n-1)+fibo(n-2);
    }
}
int main (){
    long long n = 20;
    cout<<fibo(n)<<endl;
    return 0;
}