#include <bits/stdc++.h>
#define N 100050
using namespace std;

int n, Q, tree[4*N], lazy[4*N];

void upd(int nod, int a, int b, int i, int j, int v)
{
    if(lazy[nod] != 0)
    {
        tree[nod] = (b - a + 1)*lazy[nod];

        if(a != b)
        {
            lazy[2*nod] = lazy[nod];

            lazy[2*nod + 1] = lazy[nod];
        }

        lazy[nod] = 0;
    }
    if(j < a || i > b) return;

    if(i<=a && j>=b)
    {
        tree[nod] = (b - a + 1)*v;

        if(a != b)
        {
            lazy[2*nod] = v;

            lazy[2*nod + 1] = v;
        }
        return;
    }

    int mid = (a+b)/2;

    upd(2*nod, a, mid, i, j, v);

    upd(2*nod + 1, mid + 1, b, i, j, v);

    tree[nod] = tree[2*nod] + tree[2*nod + 1];
}
int query(int nod, int a, int b, int i, int j)
{
    if(lazy[nod] != 0)
    {
        tree[nod] = (b - a + 1)*lazy[nod];

        if(a != b)
        {
            lazy[2*nod] = lazy[nod];

            lazy[2*nod + 1] = lazy[nod];
        }

        lazy[nod] = 0;
    }
    if(j < a || i > b) return 0;

    if(i<=a && j>=b) return tree[nod];

    int mid = (a+b)/2;

    return query(2*nod, a, mid, i, j) + query(2*nod + 1, mid + 1, b, i, j);
}

int main()
{

}