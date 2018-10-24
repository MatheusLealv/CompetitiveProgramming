#include <bits/stdc++.h>
#define N 1000050
#define S 26
using namespace std;

int n, id;

struct node
{
	node *prox[S];

	node()
	{
		for(int i = 0; i < S; i++) prox[i] = NULL;
	}
};

node *tree[N];

void Insert(node *root, string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		int id = s[i] - 'a';

		if(!root->prox[id]) root->prox[id] = new node();

		root = root->prox[id];
	}
}

bool query(node *root, string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		int id = s[i] - 'a';

		if(!root->prox[id]) return false;

		root = root->prox[id];
	}

	return true;
}

int main()
{

}