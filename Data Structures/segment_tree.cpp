#include <bits/stdc++.h>
using namespace std;

int n, Q, tree[4*100050];

void upd(int nod, int a, int b, int i, int v)
{
    if(a == b)
    {
        tree[nod] = v;
        return;
    }

    int mid = (a+b)/2;

    if(a <= i && i<=mid) upd(2*nod, a, mid, i, v);

    else upd(2*nod + 1, mid + 1, b, i, v);

    tree[nod] = tree[2*nod]*tree[2*nod + 1];
}

int query(int nod, int a, int b, int i, int j)
{
    if(j < a || i>b) return 1;

    if(i<=a && j>= b) return tree[nod];

    int mid = (a+b)/2;

    return query(2*nod, a , mid, i, j)*query(2*nod + 1, mid + 1, b, i, j );
}
int main()
{

}