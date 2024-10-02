//agrupar nodos sin usar dfs ni bfs
#include<bits/stdc++.h>

#define input freopen ("in.txt","r",stdin)
#define output freopen ("out.txt","w",stdout)
using namespace std;

vector<int> numbers(5);


int f(int suma, int pos){
    if(suma == 7) {
        return 1;
    }
    if(pos >= 4) {
        return 0;
    }
    //este es mas rapido
    int sol= f(suma,pos+1);
    if(suma+numbers[pos]<=7){
        sol+=f(suma+numbers[pos], pos+1);
    }
    return sol;
    //return f(suma + numbers[pos], pos + 1) + f(suma, pos + 1);
}

int main(){
    input;
    output;
    for(int i = 0; i < 5; i++){
        cin>>numbers[i];
    }
    cout<<f(0,0)<<endl;
}