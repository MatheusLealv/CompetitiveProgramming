#include <bits/stdc++.h>
#define N 200050
#define l (2*nod)
#define r (2*nod + 1)
#define mid ((a + b)/2)
using namespace std;
typedef long long ll;

int n, m;

ll k, d;

struct segtree
{
	struct node
	{
		ll sum, best, bestL, bestR;

		node(ll x = 0)
		{
			sum = best = bestL = bestR = x;
		}

	} tree[4*N], nulo;

	void build(int nod, int a, int b)
	{
		if(a == b) tree[nod] = -k;

		else
		{
			build(l, a, mid), build(r, mid + 1, b);

			join(tree[nod], tree[l], tree[r]);
		}
	}

	inline void join(node &root, node &L, node &R)
	{
		root.sum = L.sum + R.sum;

		root.bestL = max(L.bestL, L.sum + R.bestL);

		root.bestR = max(R.bestR, R.sum + L.bestR);

		root.best = max({L.best, R.best, L.bestR + R.bestL});
	}

	void upd(int nod, int a, int b, int i, ll x)
	{
		if(a == b)
		{
			ll val = tree[nod].sum + x;

			tree[nod] = node(val);

			return;
		}

		if(i <= mid) upd(l, a, mid, i, x);

		else upd(r, mid + 1, b, i, x);

		join(tree[nod], tree[l], tree[r]);
	}

} T;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n>>m>>k>>d;

	T.build(1, 1, n);
  
	for(int i = 1; i <= m; i++)
	{
		ll rr, x;

		cin>>rr>>x;

		T.upd(1, 1, n, rr, x);

		if(T.tree[1].best > k*d) cout<<"NIE\n";

		else cout<<"TAK\n";
	}
}
