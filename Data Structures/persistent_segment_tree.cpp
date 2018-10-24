#include <bits/stdc++.h>
#define N 100050
#define mid ((a + b)/2)
using namespace std;

struct node
{
	int sum;

	node *l, *r;

	node(int x = 0) { sum = x, l = r = NULL; }
};

node *version[N];

int v[N], n, q, cnt, ini[N];

vector<int> val;

void build(node *root, int a, int b)
{
	if(a == b)
	{
		root->sum = 0;

		return;
	}

	root->l = new node(), root->r = new node();

	build(root->l, a, mid), build(root->r, mid + 1, b);

	root->sum = root->l->sum + root->r->sum;
}

void update(node *prev, node *root, int a, int b, int i)
{
	if(a == b)
	{
		root->sum ++;

		return;
	}

	if(i <= mid)
	{
		root->r = prev->r;

		if(!root->l) root->l = new node();

		update(prev->l, root->l, a, mid, i);
	}

	else
	{
		root->l = prev->l;

		if(!root->r) root->r = new node();

		update(prev->r, root->r, mid + 1, b, i);
	}

	root->sum = root->l->sum + root->r->sum;
}

int query(node *L, node *R, int a, int b, int k)
{
	if(a == b) return a;

	int esq = R->l->sum - L->l->sum;

	if(k <= esq) return query(L->l, R->l, a, mid, k);

	return query(L->r, R->r, mid + 1, b, k - esq);
}

int cont(node *root, int a, int b, int i)
{
	if(i < a || i > b) return 0;

	if(a == b) return root->sum;

	return cont(root->l, a, mid, i) + cont(root->r, mid + 1, b, i);
}

int main()
{
}