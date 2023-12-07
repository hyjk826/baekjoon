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

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<vi> g(n + 1);
	for(int i{0}; i < m; ++i){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vi ch(n + 1);
	queue<int> Q;
	for(int i{0}; i < k; ++i){
		int a;
		cin >> a;
		ch[a] = 1;
		Q.push(a);
	}
	while(!Q.empty()){
		int x{Q.front()};
		Q.pop();
		for(auto& i : g[x]){
			if(ch[i]== 0){
				ch[i] = ch[x] + 1;
				Q.push(i);
			}
		}
	}
	int mx = *max_element(ch.begin(), ch.end());
	vector<vi> tmp(mx + 1);
	for(int i{1}; i <= n; ++i){
		tmp[ch[i]].push_back(i);
	}
	vi p(n + 1);
	iota(p.begin(), p.end(), 0);
	function<int(int)> find = [&](int a){
		if(a == p[a]) return a;
		return p[a] = find(p[a]);
	};
	function<bool(int,int)> merge = [&](int a, int b){
		a = find(a);
		b = find(b);
		if(a != b){
			p[a] = b;
			return true;
		}
		return false;
	};
	int l{1}, r{mx};
	int ans{-1};
	while(l <= r){
		int mid{(l + r) >> 1};
		iota(p.begin(), p.end(), 0);
		bool cycle = false;
		for(int i{1}; i <= n; ++i){
			if(ch[i] > mid){
				for(auto& j : g[i]){
					if(ch[j] <= mid) continue;
					if(i > j) continue;
					if(!merge(i, j)){						
						cycle = true; break;
					}
				}
			}
			if(cycle) break;
		}
		if(!cycle){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
