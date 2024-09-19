#include <bits/stdc++.h>
using namespace std;
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int primo(bool pr[]){
    vector<int> primos;
    for (int i = 2; i*i<pow(10,9); i++){
        if(pr[i]){
            primos.push_back(i);
            for(int j=i+i; i*i<pow(10,9); j=j+i){
                pr[j]=false;
            }
        }
    }
}
int main(){
    int p;
    bool pr[p];
    primo(pr);
    while (cin >> p){
        int div=0,sum=0;
        for (int i=2; i<=p/2; i++){
            if(pr[i]){
                sum+=i;
                div++;

            }
        }
        if(sum==p){
            cout << p << " perfect" << endl;
        } else if(div>2){
            cout << p << " almost perfect" << endl;
        } else {
            cout << p << " not perfect" << endl;
        }
    }
}