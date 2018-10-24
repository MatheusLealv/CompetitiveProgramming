#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val, sz, w, sum;

	node *l, *r;

	node(int x){
		val = sum = x, sz = 1, w = rand();

		l = r = NULL;
	}
};

node *root = NULL;

int n, q;

inline int Sum(node *root){
	return (root ? root->sum : 0);
}

inline int Sz(node *root){
	return (root ? root->sz : 0);
}

inline void upd(node *root)
{
	if(!root) return;

	root->sz = 1 + Sz(root->l) + Sz(root->r);

	root->sum = root->val + Sum(root->l) + Sum(root->r);
}

void Merge(node *&root, node *l, node *r)
{
	if(!l or !r) root = (l ? l : r);

	else
	{
		if(l->w > r->w) Merge(l->r, l->r, r), root = l;

		else Merge(r->l, l, r->l), root = r;

		upd(root);
	}
}

void Split(node *root, node *&l, node *&r, int pos)
{
	if(!root) l = r = NULL;

	else
	{
		int p = Sz(root->l) + 1;

		if(p < pos) Split(root->r, root->r, r, pos - p), l = root;

		else Split(root->l, l, root->l, pos), r = root;

		upd(root);
	}
}

void insert(int pos, int val)
{
	node *l = NULL, *r = NULL, *novo = new node(val);

	Split(root, l, r, pos + 1);
	Merge(l, l, novo);
	Merge(root, l, r);
}

inline int query(int a, int b)
{
	node *l = NULL, *r = NULL, *l1 = NULL, *r1 = NULL;

	Split(root, l, r, b + 1);

	Split(l, l1, r1, a);

	int ans = Sum(r1);

	Merge(l, l1, r1);

	Merge(root, l, r);

	return ans;
}

 main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n;

	for(int i = 1, x; i <= n; i++) cin>>x, insert(i, x);

	cin>>q;

	for(int i = 1; i <= q; i++)
	{
		char op; int a, b;

		cin>>op>>a>>b;

		if(op == 'I') insert(a, b);

		else cout<<query(a, b)<<"\n";
	}
}