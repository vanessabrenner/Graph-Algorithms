#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("arbore_minim_acoperire.in");
ofstream fout("arbore_minim_acoperire.out");

struct muchie {
    int x, y, w;
};

int V, E, t[101];
muchie m[5000];

int main()
{
    
    int i, j, s = 0, nr = 0, ax, ay;
    bool ok = true;
    muchie aux;

    ///citesc datele
    fin >> V >> E;
    for (i = 0; i < E; i++)
        fin >> m[i].x >> m[i].y >> m[i].w;

    ///sortez muchiile crescator, dupa cost
    do {
        ok = true;
        for (i = 0; i < E - 1; i++)
            if (m[i].w > m[i + 1].w)
            {
                aux.x = m[i].x;      aux.y = m[i].y;      aux.w = m[i].w;
                m[i].x = m[i + 1].x;   m[i].y = m[i + 1].y;   m[i].w = m[i + 1].w;
                m[i + 1].x = aux.x;    m[i + 1].y = aux.y;    m[i + 1].w = aux.w;

                ok = false;
            }
    } while (ok == false);

    ///initializez
    for (i = 0; i < V; i++)
        t[i] = i;

    ///determin arborele minim de acoperire
    for (i = 0; i < E; i++)
        if (t[m[i].x] != t[m[i].y]) /// extremitatile apartin de subarbori diferiti
        {
            s = s + m[i].w;
            nr++;
            fout << m[i].x << " " << m[i].y << endl;
            ///reunesc subarborii
            ax = t[m[i].x];
            ay = t[m[i].y];
            for (j = 0; j < V; j++)
                if (t[j] == ay)
                    t[j] = ax;
        }
    fout << nr << endl << s << endl;
    return 0;
}
