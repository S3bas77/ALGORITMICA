//agrupar nodos sin usar dfs ni bfs
#include<bits/stdc++.h>

#define input freopen ("in.txt","r",stdin)
#define output freopen ("out.txt","w",stdout)
using namespace std;

string word = "pala";
vector<char> abecedario(10);
vector<bool> visitados(10);

int f(int pos_word){
    if(pos_word==word.size()){
        return 1;
    }
    for(int i = 0; i < 10; i++){
        if(visitados[i]==false){
            if(abecedario[i] == word[pos_word]){
                visitados[i] = 1;
                return f(pos_word+1);
            }
        }
    }
    return 0;
}

int main(){
    input;
    //output;
    for(int i = 0; i < 5; i++){
        cin>>abecedario[i];
    }
    cout<<f(0)<<endl;
}