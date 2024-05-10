#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt", "w", stout)
using namespace std;
 
typedef pair <int, int> pii;


const int inf = numeric_limits<int>::max();

void dijkstra(int start, vector<vector<pii>>&adj, vector<int> &dist){
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    set<pii> pq; //funciona igual que el priority_queue
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()) {
        int current_node=pq.top().second;
        int current_distance=pq.top().first;
        pq.pop();
        //si la distancia actual no
        if (current_distance > dist[current_node]) continue;
        //revisamos los nodos adyacentes
        for(int i = 0; i<adj[current_node].size();i++){
            int next_node=adj[current_node][i].second;
            int weight= adj[current_node][i].first;
            int next_distance= current_distance+weight;
            //Actualizamos la distancia si encontramos un camino mas corto
            //esta parte de llama relajacion
            if(next_distance<dist[next_node]){
                dist[next_node]=next_distance;
                pq.push(make_pair(next_distance,next_node));
            }
        }
    }
}
int main(){
    input;
    int n, m;
    cout<<"ingrese el numero de nodos (n) y aristas (m):";
    cin>>n>>m;

    vector<vector<pii> > adj[n]; //lista de adyacencia para el grafo
    vector<int> dist[n, inf]; //vector de disatncias inicializadas a infinito

    cout<<"ingrese las aristas en formato (inicio fin peso):"<<end;
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(w,v));
    }
    int start;
    cout<<"ingrese el nodo de inicio";
    cin>>start;

    dijkstra(start, adj, dist);
    cout << "distancia mas cortas desde el nodo "<<start<<":"<<endl;
    for(int i )
}