#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

int main() {
	int n;
	while (cin>>n && n != -1) {
		int velocidad, horas;
		int inicio = 0;
		int result = 0;
		int horaAnterior;
		for(int i = 0; i < n; i++) {
			cin>>velocidad>>horas;
			horaAnterior=horas-inicio;
			result += horaAnterior * velocidad;
			inicio=horas;
		}
		cout<<result<<" miles"<<endl;
	}
	return 0;
}