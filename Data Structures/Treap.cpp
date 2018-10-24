#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

struct node
{
    int v, w, sz, sum;

    node *l, *r;

    node(int x)
    {
        v = sum = x;

        l = r = NULL;

        sz = 1;

        w = rand();
    }
};

int tam(node *root)
{
	return root ? root->sz : 0;
}

int stot(node *root)
{
	return root ? root->sum : 0;
}

void upd(node *root)
{
    if(root == NULL) return;
}

void Merge(node *&root, node *l, node *r)
{
	if(!l || !r) root = l ? l : r;
	else
	{
		if(l-> w > r->w)
		{
			Merge(l->r, l->r, r);

			root = l;
		}
		else
		{
			Merge(r->l, l, r->l);

			root = r;
		}
	}

	upd(root);
}

void Split(node *root, node *&l, node *&r, int idx)
{
	if(!root) l = r = NULL;

	else
	{
		int p = tam(root->l) + 1;

		if(p < idx)
		{
			Split(root->r, root->r, r, idx - p);
			l = root;
		}
		else
		{
			Split(root->l, l, root->l, idx);
			r = root;
		}
	}

	upd(root);
}

node *root = NULL;

void Insert(int idx, int val)
{
	node *l = NULL, *r = NULL, *novo = new node(val);

	Split(root, l, r, idx + 1);

	Merge(l, l, novo);

	Merge(root, l, r);
}

void replace(node *&root, int pos, int val)
{
	int p = tam(root->l) + 1;

	if(p == pos) root->v = val;

	else if(p < pos) replace(root->r, pos - p, val);

	else replace(root->l, pos, val);

	upd(root);
}

void Remove(node *&root, int pos)
{
	int p = tam(root->l) + 1;

	if(p == pos) Merge(root, root->l, root->r);

	else if(p < pos) Remove(root->r, pos - p);

	else Remove(root->l, pos);

	upd(root);
}

int query(int a, int b)
{
	node *l = NULL, *r = NULL, *l1 = NULL, *r1 = NULL;

	Split(root, l, r, b + 1);

	Split(l, l1, r1, a);

	int ans = stot(r1);

	Merge(l, l1, r1);

	Merge(root, l, r);

	return ans;
}

int n, q;

int main()
{

}