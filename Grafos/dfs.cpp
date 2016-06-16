#include <iostream>
#include <vector>

using namespace std;

#define vec vector<vector<pair<int,int> > >

/// 0->no visitado
/// 1->visitando (Primera vez visitado)
/// 2->visitado (Todos sus hijos visitados)

int time=0;

void DFS(vec &graph,const int &a,vector<int> &visitados, vector<int> &padres, vector<int> &distancias, vector<int> &tfin)
{
    ++time;
    visitados[a]=1;
    distancias[a]=time;

    for(int i=0;i<graph[a].size();++i)
    {
        if(!visitados[graph[a][i].first])
        {
            padres[graph[a][i].first]=a;
            DFS(graph,graph[a][i].first,visitados,padres,distancias,tfin);
        }
    }
    visitados[a]=2;
    ++time;
    tfin[a]=time;

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
    vector<int> tfin(n);

    int a,b,p;
    p=1;
    for(int i=0;i<m;++i)
    {
        cin>>a>>b;
        graph[a].push_back(make_pair(b,p));
    }
    for(int i=0; i<n; ++i) {
        visitados[i]=0;
        padres[i]=-1;
    }
    for(int i=0; i<n; ++i){

        if(!visitados[i])
            DFS(graph,i,visitados,padres,distancias,tfin);
    }
    for(int i=0; i<n; ++i) {

        cout<<"Nodo: "<<i<<endl;
        cout<<"  padre: "<<padres[i]<<" distancia: "<<distancias[i]<<" tfin: "<<tfin[i]<<endl;
    }
/// 6 8 0 1 0 3 3 1 1 4 4 3 2 4 2 5 5 5
    //for(int i=0; i<n; ++i){

      //  cout<<"nodo: "<<i<<endl;
       // for(int j=0; j<graph[i].size(); ++j){

 //           cout<<"a nodo "<<graph[i][j].first<<" con peso: "<<graph[i][j].second<<endl;
   //     }
    //    cout<<endl;
    //}

    return 0;
}
