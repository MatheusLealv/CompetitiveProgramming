#include <bits/stdc++.h>
#define N 100050
using namespace std;

int n, block[N], sz[N], qtd_vertice, pai[N];

vector<int> grafo[N];

vector<int> lista;

void get_size(int x, int p)
{
	pai[x] = p;

	lista.push_back(x);

	sz[x] = 1;

	for(auto v: grafo[x])
	{
		if(block[v] or v == p) continue;

		get_size(v, x);

		sz[x] += sz[v];
	}
}

int Find_Centroid(int x)
{
	lista.clear();

	get_size(x, x);

	qtd_vertice = sz[x];

	int centro = x;

	for(auto x: lista)
	{
		bool ok = true;

		if(qtd_vertice - sz[x] > qtd_vertice/2) ok = false;

		for(auto v: grafo[x])
		{
			if(v == pai[x] or block[v]) continue;

			if(sz[v] > qtd_vertice/2) ok = false;
		}

		if(ok) centro = x;
	}

	return centro;
}

vector<int> tree[N];

char ans[N];

int cnt = 20;

int solve(int x, int deep)
{
	x = Find_Centroid(x);

	ans[x] = 'A' + deep;

	block[x] = true;

	for(auto v: grafo[x])
	{
		if(block[v]) continue;

		int u = solve(v, deep + 1);

		tree[x].push_back(u);

		tree[u].push_back(x);
	}

	return x;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n;

	for(int i = 1, a, b; i < n; i++)
	{
		cin>>a>>b;

		grafo[a].push_back(b);

		grafo[b].push_back(a);
	}

	solve(1, 0);

	for(int i = 1; i <= n; i++) cout<<ans[i]<<" \n"[i == n];
}