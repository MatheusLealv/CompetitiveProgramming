#include <bits/stdc++.h>
using namespace std;

int n, k;

struct node
{
    int a, b, v;
    node *l, *r;

    node(int a_, int b_, int v_ = 1)
    {
        a = a_, b = b_, v = v_;

        l = r = NULL;
    }

    void upd(int p, int x)
    {
        if(p < a || p > b) return;

        if(a == b)
        {
            v = x;
            return;
        }

        int mid = (a+b)/2;

        if(p <= mid)
        {
            if(l == NULL) l = new node(a, mid);

            l->upd(p, x);
        }
        else
        {
            if(r == NULL) r = new node(mid + 1, b);

             r ->upd(p, x);
        }

        v = ( (l == NULL)?1:l->v ) * ( (r == NULL)?1: r-> v );
    }
    
    int query(int i, int j)
    {
        if(i > b || j < a) return 1;

        if(i <= a && j >= b) return v;

        int A = (l == NULL)?1:l->query(i, j);

        int B = (r == NULL)?1:r->query(i, j);

        return A * B;
    }
};
int main()
{
 
}