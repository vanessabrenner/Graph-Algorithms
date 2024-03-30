#include <iostream>
#include <fstream>
#include <queue>
#include <climits>
#include <cstring>

#define dim 1000

using namespace std;

ifstream fin("lab5.in");
ofstream fout("lab5.out");

int n, p[dim], radacina, i;
priority_queue<int> T;

void codare_prufer()
{
    queue<int> K;
    queue<int> scoase;

    while (!T.empty())
    {
        bool gasit = true;
        int nod = -T.top();
        scoase.push(nod);
        T.pop();
        for (i = 0; i < n; i++)
        {
            if (p[i] == nod && i != radacina)
            {
                gasit = false;
            }
        }
        if (gasit)
        {
            K.push(p[nod]);
            // punem nodurile inapoi in afara de nod
            while (!scoase.empty())
            {

                if (scoase.front() != nod)
                    T.push(-scoase.front());

                scoase.pop();
            }
            p[nod] = -1;
        }
    }

    // afisare
    fout << K.size() << endl;
    while (!K.empty())
    {
        fout << K.front() << ' ';
        K.pop();
    }
    fout << endl;
}

int m, k, MAX = INT_MIN;
int frecventa[dim];
queue<int> Kk;

void decodare_prufer()
{
    int t[dim];
    //int nrt = 0;
    memset(t, -1, sizeof(t));    

    for (int i = 0; i < m; i++)
    {
        int x = Kk.front();
        Kk.pop();
        int y = 0, j = 0;

        while (j <= MAX)
        {
            if (frecventa[j] == 0)
                break;
            j++;
        }
        if (j > MAX)
            MAX = j;

        Kk.push(j);
        frecventa[j]++;

        y = j;
        t[y] = x;
        frecventa[x]--;
    }
    int noduri = MAX + 1;

    fout << noduri << endl;
    for (int i = 0; i < noduri; i++)
    {
        fout << t[i] << ' ';
    }
}

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> p[i];
        if (p[i] == -1)
            radacina = i;
        else
        {
            T.push(-i);
        }
    }
    fout << "Codare Prufer:\n";
    codare_prufer();

    fin >> m;
    for (int i = 0; i < m; i++)
    {
        fin >> k;
        Kk.push(k);
        frecventa[k]++;
        if (MAX < k)
            MAX = k;
    }

    fout << "Decodare Prufer:\n";
    decodare_prufer();
}
