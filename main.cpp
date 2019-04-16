#include <iostream>
#include <list>
#include<bits/stdc++.h>
#include<iomanip>
#include <queue>
#define INFINITO -1
//dijkstra - encontra o menor caminho entre um ponto x ate todas as outras vetices
using namespace std;

class Grafo
{
private:
    int V; // número de vértices
    list<pair<int, double> > *adj; // ponteiro para um array contendo as listas de adjacências

public:

    // construtor
    Grafo(int V)
    {
        this->V = V; // atribui o número de vértices

        /*
            cria as listas onde cada lista é uma lista de pairs
            onde cada pair é formado pelo vértice destino e o custo
        */
        adj = new list<pair<int, double> >[V];
    }

    // adiciona uma aresta ao grafo de v1 à v2
    void addAresta(int v1, int v2, double custo)
    {
        adj[v1].push_back(make_pair(v2, custo));
        adj[v2].push_back(make_pair(v1, custo));
    }


    // algoritmo de Dijkstra
    void dijkstra(int orig, int dest)
    {
    //    for (int j = 0; j < V; ++j) sort(adj[j].begin(),adj[j].end(),sortbysec);
        // vetor de distâncias
        double dist [V];

        /*
           vetor de visitados serve para caso o vértice já tenha sido
           expandido (visitado), não expandir mais
        */
        int visitados[V];

        // fila de prioridades de pair (distancia, vértice)
        priority_queue < pair<double , int>, vector<pair<double , int> >> pq;

        // inicia o vetor de distâncias e visitados
        for(int i = 0; i < V; i++)
        {
            dist[i] = INFINITO;
            visitados[i] = false;
        }

        // a distância de orig para orig é 0
        dist[orig] = 1;

        // insere na fila
        pq.push(make_pair(dist[orig], orig));

        // loop do algoritmo
        while(!pq.empty())
        {
            pair<double , int> p = pq.top(); // extrai o pair do topo
            int u = p.second; // obtém o vértice do pair
            pq.pop(); // remove da fila

            // verifica se o vértice não foi expandido
            if(visitados[u] == false)
            {
                // marca como visitado
                visitados[u] = true;

                list<pair<int , double > >::iterator it;

                // percorre os vértices "v" adjacentes de "u"
                for(it = adj[u].begin(); it != adj[u].end(); it++)
                {
                    // obtém o vértice adjacente e o custo da aresta
                    int v = it->first;
                    double custo_aresta = it->second;

                    // relaxamento (u, v)
                    if(dist[v] < (dist[u] * custo_aresta))
                    {
//                        cout<<"dist["<<v<<"] = "<<dist[u]<<" * "<<custo_aresta<<" = "<<dist[u] * custo_aresta<<endl;
                        // atualiza a distância de "v" e insere na fila
                        dist[v] = dist[u] * custo_aresta;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }

        }

        // retorna a distância mínima até o destino
        //return dist[dest]*100;
        cout<<fixed<<setprecision(6)<<dist[dest]*100<<" percent"<<endl;

       // return dist[dest];

    }
};

int main(int argc, char *argv[])
{

    int n ,m ,a,b;
    double c;
    cin>>n;
    while(n!=0) {
        cin >> m;
        Grafo g(n);
    for (int i = 0; i < m; ++i) {
        cin>>a>>b>>c;
        g.addAresta(a-1,b-1,c/100);
    }

//        g.addAresta(4, 1, 100.00 / 100);
//        g.addAresta(2, 4, 8.00 / 100);
//        g.addAresta(1, 2, 70.00 / 100);
//        g.addAresta(1, 0, 50.00 / 100);
//        g.addAresta(2, 3, 90.00 / 100);
//        g.addAresta(3, 0, 8.00 / 100);
//        g.addAresta(2, 0, 70.00 / 100);

        //   double rest = g.dijkstra(0, n-1) ;

        //   cout << setprecision(5) <<rest << endl;
//    double * X;
        g.dijkstra(0, n - 1);
        cin>>n;
    }
//    for (int i = 0; i < n; ++i) {
//        cout<<i<<" "<<X[i]<<endl;
//    }

    return 0;
}
