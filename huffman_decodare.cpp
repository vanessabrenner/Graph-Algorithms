#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("decodare_huffman.in");
ofstream fout("decodare_huffman.out");
string s, linie;



struct Nod {
	int lt, rt, nr_ap;
	char c;
}arbore[255];


char decodare(int a, int& k)
{
	Nod& nod = arbore[a];
	if (nod.lt == -1 && nod.rt == -1)
		return nod.c;
	else
	{
		char ch = s[k];
		k++;
		if (ch == '0') return decodare(nod.lt, k);
		else if (ch == '1') return decodare(nod.rt, k);
		else return 0;
	}
}


int main()
{
	auto cmp = [](int lhs, int rhs) { return arbore[lhs].nr_ap > arbore[rhs].nr_ap || (arbore[lhs].nr_ap == arbore[rhs].nr_ap && arbore[lhs].c > arbore[rhs].c); };
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
	int n, k = 0, q = 0;
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		Nod& nod = arbore[q];
		nod.lt = nod.rt = -1;
		getline(fin, linie);
		nod.c = fin.get();
		fin.get();
		fin >> nod.nr_ap;
		pq.push(q); q++;
	}
	//construim arborele
	while (pq.size() >= 2)
	{
		auto lt = pq.top(); pq.pop();
		auto rt = pq.top(); pq.pop();

		Nod& nod = arbore[q];
		nod.nr_ap = arbore[lt].nr_ap + arbore[rt].nr_ap;
		nod.c = min(arbore[lt].c, arbore[rt].c);
		nod.lt = lt;
		nod.rt = rt;
		pq.push(q); q++;
	}
	fin >> s;
	while (k < s.size())
		fout << decodare(q - 1, k);
	fin.close();
	fout.close();
	return 0;
}