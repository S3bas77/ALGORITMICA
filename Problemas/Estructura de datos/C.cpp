#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main () {
    int n;
    vector<int> numeros(n);
    for(int i=0;i<n;i++){
        cin>>numeros[i];
    }
    vector<bool> vis(n);
    for (int i = 1; i <  n; i++){
        int diferencia = abs(numeros[i-1]-numeros[i]);
        if(diferencia<n){
            vis[diferencia]=1;
        }
    }
    bool Sol=true;
    for(int i=1;i<n;i++){
        if(vis[i]==false) {
            Sol=false;
        }
    }
    if(Sol) {
        cout<<"si";
    }else{
        cout<<"no";
    }
}