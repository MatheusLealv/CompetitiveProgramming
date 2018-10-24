// Dynamic Convex Hull Trick O( SQRT(N)*(N + Q) )
#include <bits/stdc++.h>
#define inf 2000000000000000000LL
#define N 100050
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

vector<pii> lines;

ll h[N], sum[N], n, dp[N], raiz;

struct Convex_Hull_Structure
{
    vector<pii> lines;

    double intersect(pii r, pii s)
    {
      return ((double)(r.s - s.s))/((double)(s.f - r.f));
    }

    bool bad(pii A, pii B, pii C)
    {
      return intersect(A, C) <= intersect(B, A);
    }

    void addline(pii line, bool flag)
    {
      if(flag)
      {
          while(lines.size() >= 2 && bad(lines[lines.size() - 2], lines[lines.size() - 1], line) ) lines.pop_back();

          if(lines.size() == 1 && lines[0].f == line.f) lines.pop_back();

          lines.push_back(line);
      }

      else
      {
        lines.push_back(line);

        for(int i = lines.size() - 1; i >= 0; i--)
        {
           if(i != 0 && lines[i - 1] <= lines[i]) swap(lines[i], lines[i - 1]);

           else break;
        }
      }
    }

    ll query_Hull(ll x) 
    {
        int ini = 0, fim = lines.size() - 1, mid, best = -1;

        while(fim >= ini)
        {
            mid = (ini + fim)/2;

            double pos = mid > 0? intersect(lines[mid], lines[mid - 1]) : - inf;

            if(pos <= x) best = mid, ini = mid + 1;

            else fim = mid - 1; 
        }

        return (best == -1 ? inf : lines[best].f*x + lines[best].s);
    }

} oficial, aux, pilha;

void Clear_Stack()
{
  aux.lines.clear();

  int esq = 0, dir = 0;

  while(esq < oficial.lines.size() && dir < pilha.lines.size())
  {
    if(oficial.lines[esq] >= pilha.lines[dir]) aux.addline(oficial.lines[esq], 1), esq ++;

    else aux.addline(pilha.lines[dir], 1), dir ++;
  }

  while(esq < oficial.lines.size()) aux.addline(oficial.lines[esq], 1), esq ++;

  while(dir < pilha.lines.size()) aux.addline(pilha.lines[dir], 1), dir ++;

  oficial.lines = aux.lines, pilha.lines.clear(), aux.lines.clear();
}

int main()
{

}