// parcurgere in adancime
// Depth-First-Search

#include <list>
#include <fstream>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

#define dim 100
#define infinity 9999

struct Varf{
    int color; // 0- alb, 1 - gri, 2 - negru
    int predecesor;
    int explorat;
    int descoperit;
} v[dim];

void DFS_VISIT(int g[dim][dim], Varf v[dim], int i, int time, int n){
    time++;
    v[i].descoperit = time;
    v[i].color = 1;
    fout << i << ' ';

    for(int j = 1; j <= n; j++){
        if(g[i][j] != 0 && v[j].color == 0){
            v[j].predecesor = i;
            DFS_VISIT(g, v, j, time, n);
        }
    }

    v[i].color = 2;
    time++;
    v[i].explorat = time;
}

void DFS(int g[dim][dim], int n, int s){

    for(int i = 1; i <= n; i++){
        v[i].color = 0;
        v[i].predecesor = -1;
    }
    int time = 0;
    DFS_VISIT(g, v, s, time, n);
}

int main(){

    int n, m, a[dim][dim], s, d, sursa;

    fin >> n >> m >> sursa;
    for(int i = 1; i <= m; i++){
        fin >> s >> d;
        a[s][d] = 1;
    }

    DFS(a, n, sursa);
}