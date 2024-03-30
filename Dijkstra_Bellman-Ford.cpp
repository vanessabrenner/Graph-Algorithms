#include <iostream>
#include <fstream>
#include <limits>
#include <queue>
#include <vector>

#define infinity 9999
#define max 100

using namespace std;

ifstream fin("lab3.in");
ofstream fout("lab3.out");

void dijkstra(int g[max][max], int n, int s){

    int distanta[max], pred[max];

    priority_queue <int> Q;
    vector <int> v;

    for(int i = 0; i < n; i++){
        Q.push(-i);
        distanta[i] = infinity;
        pred[i] = s;
    }

    distanta[s] = 0;
    while(!Q.empty()){
        int nod = -Q.top();
        Q.pop();
        v.push_back(nod);
        for(int j = 0; j < n; j++){
            if(g[nod][j] != 0 && distanta[j] > distanta[nod] + g[nod][j])
                distanta[j] = distanta[nod] + g[nod][j], pred[j] = nod;
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         if(g[i][j] == 0)
    //             cost[i][j] = infinity;
    //         else
    //             cost[i][j] = g[i][j];
    //     }
    // }

    // for(int i = 0; i < n; i++){
    //     distanta[i] = cost[sursa][i];
    //     //pred[i] = sursa;
    //     vizitat[i] = 0;
    // }

    // distanta[sursa] = 0;
    // vizitat[sursa] = 1;
    // count = 1;

    // while(count < n - 1){
    //     mindistanta = infinity;

    //     for(int i = 0; i < n; i++)
    //         if(distanta[i] < mindistanta && vizitat[i] == 0){
    //             mindistanta = distanta[i];
    //             urmator = i;
    //         }
        
    //     vizitat[urmator] = 1;

    //     for(int i = 0; i < n; i++)
    //         if(vizitat[i] == 0)
    //             if(mindistanta + cost[urmator][i] < distanta[i]){
    //                 distanta[i] = mindistanta + cost[urmator][i];
    //                 //pred[i] = urmator;
    //             }
    //     count++;
    // }

    for(int i = 0; i < n; i++)
        fout << "Distanta minima din nodul sursa in " << i << " este " << distanta[i] << endl;
    
}

void bellman_ford(int g[max][max], int n, int s){

    int distanta[infinity], pred[max];
    int drum[max];

    for(int i = 0; i < n; i++)
        distanta[i] = infinity, pred[i] = s;
    distanta[s] = 0;

    for(int k = 1; k <= n - 1; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] != 0 && distanta[j] > distanta[i] + g[i][j]){
                    distanta[j] = distanta[i] + g[i][j], pred[j] = i;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        fout << "Distanta minima din nodul sursa in " << i << " este " << distanta[i] << endl;

    // drum invers, de la un nod oarecare la sursa
    // for(int i = 0; i < n; i++){
    //     fout << "Drumul de noduri de la nodul " << i << " pana la sursa este: ";
    //     int dc = pred[i];
    //     while(dc != s){
    //         fout << dc << ' ';
    //         dc = pred[dc];
    //     }        
    //     fout << dc << "\n";
    // }

}

int main(){
    int g[max][max];
    int n, m, s;

    fin >> n >> m >> s;
    
    for(int i = 0; i < m; i++){
        int n1, n2, cost;
        fin >> n1 >> n2 >> cost;
        g[n1][n2] = cost;
    }

    fout << "Dijkstra:\n";
    dijkstra(g, n, s);
    fout << "\n";
    //..................................

    fout << "Bellman-Ford:\n";
    bellman_ford(g, n, s);
    fout << "\n";
    //..................................
    
    
}