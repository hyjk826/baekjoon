#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define vpl vector<pl>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int cnt[200001];
int p[200001];
ll ans{0};

int find(int a){
	if(a == p[a]) return a;
	return p[a] = find(p[a]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a != b){			
		int x = cnt[a];
		int y = cnt[b];
		p[a] = b;
		cnt[b] += cnt[a];
		ans -= 1LL * x * (x - 1) / 2;
		ans -= 1LL * y * (y - 1) / 2;
		ans += 1LL * (x + y - 1) * (x + y) / 2;
	}
}

void solve(){
	int n, m;
	cin >> n >> m;
	ans = n;
	for(int i{1}; i <= n; ++i){
		p[i] = i;
		cnt[i] = 1;
	}
	for(int i{0}; i < m; ++i){
		int a, b;
		cin >> a >> b;
		Union(a, b);
		cout << ans << "\n";
	}
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
