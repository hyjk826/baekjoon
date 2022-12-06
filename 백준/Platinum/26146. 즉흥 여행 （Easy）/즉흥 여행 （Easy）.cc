// 2022-12-03
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


int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<vi> g1(n + 1);
	vector<vi> g2(n + 1);
	for(int i{0}; i < m; ++i){
		int a, b;
		cin >> a >> b;
		g1[a].push_back(b);
		g2[b].push_back(a);
	}
	vi ch1(n + 1);
	ch1[1] = 1;
	int cnt1{0};
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int v{Q.front()};
		Q.pop();
		cnt1++;
		for(auto& i : g1[v]){
			if(ch1[i] == 0){
				ch1[i] = 1;
				Q.push(i);
			}
		}
	}
	int cnt2{0};
	vi ch2(n + 1);
	ch2[1] = 1;
	Q.push(1);
	while(!Q.empty()){
		int v{Q.front()};
		Q.pop();
		cnt2++;
		for(auto& i : g2[v]){
			if(ch2[i] == 0){
				ch2[i] = 1;
				Q.push(i);
			}
		}
	}
	if(cnt1 == n && cnt2 == n) cout << "Yes";
	else cout << "No";
}
	
