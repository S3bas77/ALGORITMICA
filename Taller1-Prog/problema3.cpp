#include <bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main(){
    int T;
    cin>>T;
    for(int i=1; i<=T; i++){
        int L,W,H;
        cin>>L>>W>>H;
        if(L<=20 && W<=20 && H<=20){
            cout<<"Case "<<i<<": good"<<endl;
        } else {
            cout<<"Case "<<i<<": bad"<<endl;
        }
    } 
}