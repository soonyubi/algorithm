
/*
*   Time :
*   Subject :
*
*   Coded by soonyubing
*/

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii  pair<int, int>
#define pld pair<ld, ld>
// INT_MAX INT_MIN ldONG_MAX ldONG_MIN
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }

ld floyd[101][101]; // 내일로 티켓 안 살 경우
ld floyd2[101][101]; // 내일로 티켓 살 경우
map<string, int> mp;
const ld inf = 1e9;

void solve()
{
	int n, r; cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		string city; cin >> city;
		mp[city] = i;
	}
	int m; cin >> m;
	vector<int> toVisit;
	for (int i = 0; i < m; i++)
	{
		string city; cin >> city;
		toVisit.push_back(mp[city]);
	}
	int k; cin >> k; 
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) if(i!=j)floyd[i][j] = floyd2[i][j] = inf;
	for (int i = 0; i < k; i++)
	{
		string type, city1, city2; ld cost;
		cin >> type >> city1 >> city2 >> cost;
		floyd[mp[city1]][mp[city2]] = min(floyd[mp[city1]][mp[city2]],cost);
		floyd[mp[city2]][mp[city1]] = min(floyd[mp[city2]][mp[city1]],cost);

		if (type == "ITX-Saemaeul" || type == "ITX-Cheongchun" || type == "Mugunghwa")
		{
			cost = 0;
		}
		else if (type == "S-Train" || type == "V-Train")
		{
			cost /= 2;
		}
		
		floyd2[mp[city1]][mp[city2]] = min(floyd2[mp[city1]][mp[city2]], cost);
		floyd2[mp[city2]][mp[city1]] = min(floyd2[mp[city2]][mp[city1]], cost);
		
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k]);
				floyd2[j][k] = min(floyd2[j][k], floyd2[j][i] + floyd2[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) floyd[i][i] = floyd2[i][i] = 0;

	

	ld ans1 = 0;
	ld ans2 = r;
	for (int i = 0; i < m; i++)
	{
		// toVisit[i] -> toVisit[(i+1)%m]
		ans1 += floyd[toVisit[i]][toVisit[(i + 1) % m]];
		//cout << floyd[toVisit[i]][toVisit[(i + 1) % m]] << " ";
		ans2 += floyd2[toVisit[i]][toVisit[(i + 1) % m]];
		//cout << floyd2[toVisit[i]][toVisit[(i + 1) % m]] << "\n--------------\n";
	}
	
	if (ans1 <= ans2) cout << "No\n";
	else cout << "Yes\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}


