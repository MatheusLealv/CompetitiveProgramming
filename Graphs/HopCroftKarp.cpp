#include <bits/stdc++.h>
#define N 50050
using namespace std;

const int NIL = 0, inf = 20000000;

int L, R, m, matchL[N], matchR[N], dist[N];

vector<int> grafo[N];

bool bfs()
{
	queue<int> fila;

	for(int i = 1; i <= L; i++)
	{
		// Se I é for um vertice livre
		if(matchL[i] == NIL)
		{
			dist[i] = 0; // Indica que i está livre

			fila.push(i); 
		}

		else dist[i] = inf; // Já possui match
	}

	dist[NIL] = inf;

	while(!fila.empty())
	{
		// Vertice atual
		int x = fila.front();

		fila.pop();

		if(dist[x] >= dist[NIL]) continue; // Se "x" já estiver sido pareado com alguém

		for(auto v: grafo[x])
		{
			// Garantir que estou acessando caminho aumentante
			// Checa se a aresta não está sendo utilizada no matching atual
			if(dist[matchR[v]] == inf) 
			{
				dist[matchR[v]] = dist[x] + 1;

				fila.push(matchR[v]);
			}
		}
	}

	return ((dist[NIL] == inf ? false: true));
}

bool dfs(int x)
{
	if(x != NIL)
	{
		for(auto v: grafo[x])
		{
			// Se essa aresta pertence a algum caminho aumentante
			if(dist[matchR[v]] == dist[x] + 1)
			{
				if(dfs(matchR[v]))
				{
					matchL[x] = v;

					matchR[v] = x;

					return true;
				}
			}
		}

		// Se não existe nenhum caminho aumentante começando no vertice X

		dist[x] = inf;

		return false;
	}

	return true;
}

int HopCroft()
{
	for(int i = 1; i <= L; i++) matchL[i] = NIL;

	for(int i = 1; i <= R; i++) matchR[i] = NIL;

	int answer = 0;

	while(bfs())
	{
		for(int i = 1; i <= L; i++)
			if(matchL[i] == NIL and dfs(i))
				answer ++;
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	//L, R  representam a quantidade de vertices em cada uma das partições
	// m = número de arestas
	cin>>L>>R>>m;

	for(int i = 1, a, b; i <= m; i++)
	{
		cin>>a>>b;

		// Tenho uma aresta entre os vertices a e b. Onde a pertence a L e b pertence a R

		grafo[a].push_back(b);

		//grafo[b].push_back(a);
	}

	cout<<HopCroft()<<"\n";
}
