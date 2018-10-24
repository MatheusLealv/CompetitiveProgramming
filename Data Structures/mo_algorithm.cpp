#include <bits/stdc++.h>
#define N 100010
using namespace std;

int n, q, v[N], raiz = 330, L, R, best;

struct query
{
	int l, r, id;
};

bool compi(query A, query B)
{
	if(A.l/raiz != B.l/raiz) return A.l/raiz < B.l/raiz;

	return A.r < B.r;
}

query Q[N];

void add(int i)
{
}

void remove(int i)
{
}

int query(int i)
{
	while(L < Q[i].l)
	{
		remove(L);
		L++;
	}

	while(L > Q[i].l)
	{
		L--;
		add(L);
	}

	while(R < Q[i].r)
	{
		R++;

		add(R);
	}

	while(R > Q[i].r)
	{
		remove(R);
		R--;
	}

	return best;
}

int main()
{

}