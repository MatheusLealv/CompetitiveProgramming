#include <bits/stdc++.h>
#define N 100050
using namespace std;

int n, q, save[4*N];

vector< pair<int, int> > v;

vector<int> tree[4*N];

void build(int nod, int a, int b)
{
    if(a == b)
    {
        tree[nod].push_back(v[a].second);
        return;
    }
    
    int mid = (a+b)/2;

    build(2*nod, a, mid);

    build(2*nod + 1, mid + 1, b);

    tree[nod] = vector<int> (b - a + 1);

    merge(tree[2*nod].begin(), tree[2*nod].end(), tree[2*nod + 1].begin(), tree[2*nod + 1].end(), tree[nod].begin());

}

int cont(int nod, int a, int b)
{
    return upper_bound(tree[nod].begin(), tree[nod].end(), b) - lower_bound(tree[nod].begin(), tree[nod].end(), a);
}

int query(int nod, int a, int b, int i, int j, int x)
{
    if(a == b) return save[tree[nod][0]];
    
    int mid = (a+b)/2;

    if(cont(2*nod, i, j) >= x) return query(2*nod, a, mid, i, j, x);

    else return query(2*nod +1, mid + 1, b, i, j, x -  cont(2*nod, i, j));
}

int main()
{

}
