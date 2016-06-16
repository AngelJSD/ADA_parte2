#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vec vector<vector<pair<int,int> > >

/// 0->no visitado
/// 1->visitando (Primera vez visitado)
/// 2->visitado (Todos sus hijos visitados)

void BFS(vec &graph,const int &a,vector<int> &visitados, vector<int> &padres, vector<int> &distancias)
{
    visitados[a]=1;
    distancias[a]=0;
    queue<int> pila;
    pila.push(a);

    while(!pila.empty()){

	int u=pila.front();
	pila.pop();
	for(int i=0; i<graph[u].size(); ++i){
	    if(!visitados[graph[u][i].first]){

            visitados[graph[u][i].first]=1;
            distancias[graph[u][i].first]=distancias[u]+1;
            padres[graph[u][i].first]=u;
            pila.push(graph[u][i].first);
	    }
	}
	visitados[u]=2;
    }

    return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vec graph(n);
    vector<int> visitados(n);
    vector<int> padres(n);
    vector<int> distancias(n);

    int a,b,p;
    p=1;
    for(int i=0;i<m;++i)
    {
        cin>>a>>b;
        graph[a].push_back(make_pair(b,p));
        graph[b].push_back(make_pair(a,p));
    }
    for(int i=0; i<n; ++i) {

        visitados[i]=0;
        padres[i]=-1;

    }

    BFS(graph,1,visitados,padres,distancias);

    for(int i=0; i<n; ++i) {

        cout<<"Nodo: "<<i<<endl;
        cout<<"  padre: "<<padres[i]<<" distancia: "<<distancias[i]<<endl;
    }
///8 10 0 1 0 4 1 5 2 5 5 6 2 6 2 3 3 6 3 7 6 7

    //for(int i=0; i<n; ++i){

      //  cout<<"nodo: "<<i<<endl;
       // for(int j=0; j<graph[i].size(); ++j){

 //           cout<<"a nodo "<<graph[i][j].first<<" con peso: "<<graph[i][j].second<<endl;
   //     }
    //    cout<<endl;
    //}
    return 0;
}
