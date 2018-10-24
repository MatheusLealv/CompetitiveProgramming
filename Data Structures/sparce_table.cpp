#include <bits/stdc++.h>
#define N 100050
#define mid ((a + b)/2)
using namespace std;
typedef long long ll;

int A, B, n, v[N], tree[4*N];

int dp[N*10][30];

inline void build()
{
  for(int i = 0; i < n; i++) dp[i][0] = v[i];

  for(int j = 1; j <= 19; j++)
      for(int i = 0; i < n; i++)
           dp[i][j] = min(dp[i][j - 1], dp[ i + (1<<(j - 1)) ][j - 1]);
}

inline int query(int l, int r)
{
	if(l == r) return v[l];

	int exp = 31-__builtin_clz(r-l);

	return min(dp[l][exp], dp[r - (1<<exp) + 1][exp]);
}

int main()
{

}