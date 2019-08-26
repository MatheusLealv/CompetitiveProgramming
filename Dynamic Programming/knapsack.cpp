#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii v [2040];

int n, m, dp[2040][2040];

int solve(int i, int w)
{
	if(i > n) return 0;

	if(dp[i][w] != -1) return dp[i][w];

	int nadd = solve(i + 1, w), add = 0;

	if(w - v[i].first >= 0) add = solve(i + 1, w - v[i].first) + v[i].second;

	return dp[i][w] = max(add, nadd);
}

int main()
{
	cin>>m>>n;

	for(int i = 1; i <= n; i++)
	{
		int a, b;
		cin>>a>>b;
		v[i] = pii(a, b);
	}

	memset(dp, -1, sizeof dp);

	cout<<solve(1, m)<<"\n";
}
