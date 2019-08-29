#include <bits/stdc++.h>
#define N 1000050
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define l (2*nod)
#define r (2*nod + 1)
#define mid ((a + b)/2)
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 20000000000000000;

int n, m, q, k, v[N], T;

struct node
{
	int max1, max2, sum, cnt;

	node(int x = 0)
	{
		max1 = sum = x;

		cnt = 1, max2 = -inf;
	}
} tree[4*N];

inline void merge(int nod)
{
	tree[nod].max1 = max(tree[l].max1, tree[r].max1);

	tree[nod].max2 = -inf;
	tree[nod].cnt = 0;

	if(tree[l].max1 != tree[nod].max1) tree[nod].max2 = max(tree[nod].max2, tree[l].max1);
	if(tree[l].max2 != tree[nod].max1) tree[nod].max2 = max(tree[nod].max2, tree[l].max2);
	if(tree[r].max1 != tree[nod].max1) tree[nod].max2 = max(tree[nod].max2, tree[r].max1);
	if(tree[r].max2 != tree[nod].max1) tree[nod].max2 = max(tree[nod].max2, tree[r].max2);

	if(tree[l].max1 == tree[nod].max1) tree[nod].cnt += tree[l].cnt;
	if(tree[r].max1 == tree[nod].max1) tree[nod].cnt += tree[r].cnt;

	tree[nod].sum = tree[l].sum + tree[r].sum;
}

void build(int nod, int a, int b)
{
	if(a == b)
	{
		tree[nod] = node(v[a]);

		return;
	}

	build(l, a, mid), build(r, mid + 1, b);

	merge(nod);
}

void propaga(int nod, int a, int b)
{	
	if(a == b) return;

	if(tree[l].max1 > tree[nod].max1)
	{
		tree[l].sum -= tree[l].cnt*(tree[l].max1 - tree[nod].max1);

		tree[l].max1 = tree[nod].max1;
	}

	if(tree[r].max1 > tree[nod].max1)
	{
		tree[r].sum -= tree[r].cnt*(tree[r].max1 - tree[nod].max1);
		
		tree[r].max1 = tree[nod].max1;
	}
}

void upd(int nod, int a, int b, int i, int j, int x)
{
	propaga(nod, a, b);

	if(j < a or i > b or tree[nod].max1 <= x) return;

	if(i <= a and j >= b and tree[nod].max1 > x and x > tree[nod].max2)
	{
		tree[nod].sum -= tree[nod].cnt*(tree[nod].max1 - x);

		tree[nod].max1 = x;

		return;
	}

	upd(l, a, mid, i, j, x), upd(r, mid + 1, b, i, j, x);

	merge(nod);
}

int query(int nod, int a, int b, int i, int j, int f)
{
	propaga(nod, a, b);

	if(j < a or i > b) return 0;

	if(i <= a and j >= b) return (!f ? tree[nod].sum : tree[nod].max1);

	if(!f) return query(l, a, mid, i, j, f) + query(r, mid + 1, b, i, j, f);

	return max(query(l, a, mid, i, j, f), query(r, mid + 1, b, i, j, f));
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>T;

	while(T--)
	{
		cin>>n>>q;
		for(int i = 0; i < 4*n; i++) tree[i] = node(0);

		for(int i = 1; i <= n; i++) cin>>v[i];

		build(1, 1, n);

		for(int i = 1; i <= q; i++)
		{
			int t, a, b, c;

			cin>>t>>a>>b;

			if(t == 0)
			{
				cin>>c;

				upd(1, 1, n, a, b, c);
			}

			else if(t == 1) cout<<query(1, 1, n, a, b, 1)<<"\n";

			else cout<<query(1, 1 ,n, a, b, 0)<<"\n";
		}
	}
}
