//agrupar nodos sin usar dfs ni bfs
#include<bits/stdc++.h>

#define input freopen ("in.txt","r",stdin)
#define output freopen ("out.txt","w",stdout)
using namespace std;

vector<int> parents(10);
int n = 10;

void init(){
    for(int i = 0; i < n; i++){
        parents[i]=i;
    }
}

int find (int node) {
    int father=parents[node];
    if(node == find(node)){
        return node;
    } else {
        return find(father);
    }
}

//tratar de unir el nodo A con el nodo B
void union_ (int a, int b){
    int fatherIzq = find(a);
    int fatherDer = find(b);
    parents[fatherDer] = fatherIzq;
}

void print(){
    for(int i = 0; i < 10; i++){
        cout<<"["<<parents[i]<<"]";
    }
}

int belongTo(int a){
    int fatherA=find(a);
    int count=0;
    for(int i = 0; i < n; i++){
        //count += (fatherA) == find(i);
        if(fatherA==find(i)){
            count++;
        }
    }
}

bool juntos(int a, int b){
    return find(a) == find(b);
}

int main ( ) {
    init();
    int cases = 4;
    while (cases--){
        int a,b;
        cin>>a>>b;
        union_(a,b);
        print();
        belongTo(a);
    }
}