#include <bits/stdc++.h>
#define N 5020
#define int long long
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

int n, inf = 200000000000000000;

pii v[N];

// Exchange argument
// The optimal way to sort them
bool cmp(pii A, pii B)
{
	return A.f - B.s > B.f - A.s;
}

int dp[N][N];

int solve(int i, int qtd)
{
	if(i > n)
	{
		if(!qtd) return 0;

		return inf;
	}

	if(dp[i][qtd] != -1) return dp[i][qtd];

	int sum = solve(i + 1, qtd - 1), ans = inf;

	if(sum <= v[i].f) ans = sum + v[i].s;

	ans = min(ans, solve(i + 1, qtd));

	return dp[i][qtd] = ans;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n;

	for(int i = 1; i <= n; i++) cin>>v[i].f>>v[i].s;

	sort(v + 1, v + n + 1, cmp);

	int opt = 0;

	memset(dp, -1, sizeof dp);

	for(int i = 0; i < N; i++)
		if(solve(1, i) < inf) opt = i;

	cout<<opt<<"\n";
}
