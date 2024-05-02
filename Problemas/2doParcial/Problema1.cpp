#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
int main(){
    queue<int> vip;
    queue<int> general;
    queue<int> preferencial;
    int q;
    vector<int> cancelados (1000,0);
    cin>>q;
    string tipo;
    while(q--) {
        cin>>tipo;
        if(tipo=="ARRIVE"){
            //logica cuando llegan
            int id;
            string type;
            cin>>id>>type;
            if(type=="VIP"){
                vip.push(id);
            }else if(type=="Preferencial") {
                preferencial.push(id);
            }else{
                general.push(id);
            }
        } else if(tipo=="ENTER"){
            //logica cuando entran
            //empezar por vip luego preferencial y por ultimo general
            bool entro = false;
            while(!vip.empty()){
                int persona=vip.front();
                vip.pop();
                if(cancelados[persona]){
                    cout<<persona<<endl;
                    entro=true;
                    break;
                }
            }
            while(!preferencial.empty() && !entro){
                int persona=preferencial.front();
                preferencial.pop();
                if(cancelados[persona]){
                    cout<<persona<<endl;
                    entro=true;
                    break;
                }
            }
            while(!general.empty() && !entro){
                int persona=general.front();
                general.pop();
                if(cancelados[persona]){
                    cout<<persona<<endl;
                    entro=true;
                    break;
                }
            }
            if(!entro){
                cout<<"NONE"<<endl;
            }
        } else {
            //logica cuando cancelan
            int id;
            cin>>id;
            cancelados[id]=true;
        }
    }
}