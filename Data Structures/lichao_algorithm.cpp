#include <bits/stdc++.h>
#define mid ((l + r)/2)
#define esq (2*nod)
#define dir (2*(nod + 1))
#define inf 0x3f3f3f3f
#define N 100005 
using namespace std;
typedef long long ll;

int n, m, a, b, vis[4*N], op;

struct line
{
    int a, b;

    int query(int x)
    {
        return a * x + b;
    }

} tree[4*N];

void update(int nod, int l, int r, line v)
{
    if(!vis[nod])
    {
    	vis[nod] = 1, tree[nod] = v;

    	return;
    }

    if (tree[nod].query(l) > v.query(l) && tree[nod].query(r) > v.query(r)) return;

    if (tree[nod].query(l) < v.query(l) && tree[nod].query(r) < v.query(r)) tree[nod] = v;

    else
    {

	    if (tree[nod].query(l) < v.query(l)) swap(tree[nod], v);

	    if (tree[nod].query(mid) > v.query(mid)) update(dir, mid + 1, r, v);

	    else swap(tree[nod], v), update(esq, l, mid, v);
	}
}

int query(int nod, int l, int r, int pos)
{
    if(l == r) return tree[nod].query(l);

    int ans = tree[nod].query(pos);

    if(pos <= mid) ans = max(ans, query(esq, l, mid, pos));

    else ans = max(ans, query(dir, mid + 1, r, pos));

    return ans;
}

int main()
{

}