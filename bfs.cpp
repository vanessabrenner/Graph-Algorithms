// parcurgere in latime
// Breadth-First-Search

#include <queue>
#include <fstream>

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

#define dim 100
#define infinity 9999

struct Varf{
    int color; // 0- alb, 1 - gri, 2 - negru
    int predecesor;
    int distanta;
};

void BFS(int g[dim][dim], int n, int s){
    Varf v[dim];
    queue <int> Q;

    for(int i = 1; i <= n; i++){
        v[i].color = 0;
        v[i].distanta = infinity;
        v[i].predecesor = -1;
    }

    v[s].color = 1;
    v[s].distanta = 0;
    v[s].predecesor = -1;

    Q.push(s);
    while(!Q.empty()){
        int nod = Q.front();
        fout << nod << ' ';
        Q.pop();
        for(int i = 1; i <= n; i++){
            if(i != nod && g[nod][i] != 0){
                if(v[i].color == 0){
                    v[i].color = 1;
                    v[i].predecesor = nod;
                    v[i].distanta = v[nod].distanta + 1;
                    Q.push(i);
                }            
            }
        }
        v[nod].color = 2;
    }
    fout << endl;
    for(int i = 1; i <= n; i++){
        fout << i << ' ' << v[i].distanta << "  ";
    }
}

int main(){

    int n, m, a[dim][dim], s, d, sursa;

    fin >> n >> m >> sursa;
    for(int i = 1; i <= m; i++){
        fin >> s >> d;
        a[s][d] = 1;
    }

    BFS(a, n, sursa);
}