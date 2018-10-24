#include <bits/stdc++.h>
#define N 100050
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

int T, n, q, v[N], a, b, c, d, id;

vector < pii > bit[N];

inline void update(int x, int v)
{
	for(int i = x; i < N; i += (i&-i))
	{
		if(bit[i].empty()) bit[i].push_back({id, v});

		else bit[i].push_back({id, bit[i].back().s + v}); 
	}
}

inline int query(int x, int id)
{
	int sum = 0;

	for(int i = x; i > 0; i -= (i&-i))
	{
		int ini = 0, fim = bit[i].size() - 1, mid, best = -1;

		while(fim >= ini)
		{
			mid = (ini + fim)/2;

			if(bit[i][mid].f <= id) best = mid, ini = mid + 1;

			else fim = mid - 1;
		}

		if(best != -1) sum += bit[i][best].s;
	}

	return sum;
}

int main()
{
}