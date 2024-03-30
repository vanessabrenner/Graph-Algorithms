#include <iostream>
#include <fstream>

#define dim 100

using namespace std;

ifstream fin("Ciclu_eulerian.in");
ofstream fout("Ciclu_eulerian.out");

int n, m, g[dim][dim], ciclu[dim];
int p = 0;
    
void Euler(int k){
    for(int i = 0; i < n; i++)
        if(g[k][i]){
            g[k][i] = g[i][k] = 0;
            Euler(i);
        }
    ciclu[p] = k;
    p++;
}

int main(){
    int x, y;

    fin >> n >> m;
    for(int i = 1; i <= m; i++){
        fin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }

    Euler(0);
    cout << p;
    for(int i = 0; i < p; i++) 
        fout << ciclu[i] << ' ';
    
}

