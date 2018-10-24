#include <bits/stdc++.h>
#define N 100050
using namespace std;

int n, v[N], pref[N], T;

struct node
{
	node *prox[2];

	node(){
		prox[0] = prox[1] = NULL;
	}
};

inline void insert(node *root, int x)
{
	for(int i = 32; i >= 0; i--)
	{
		int bit = ((x & (1LL<<i)) ? 1 : 0);

		if(!root->prox[bit]) root->prox[bit] = new node();

		root = root->prox[bit];
	}
}

inline int query(node *root, int x)
{
	int ans = 0;

	for(int i = 32; i >= 0; i--)
	{
		if(!root) return ans;

		int bit = ((x & (1LL<<i)) ? 1 : 0);

		if(root->prox[!bit]) ans += (1LL<<i), root = root->prox[!bit];

		else root = root->prox[bit];
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
}