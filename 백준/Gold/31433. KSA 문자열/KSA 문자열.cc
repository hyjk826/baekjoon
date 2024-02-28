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
#define MOD 998244353
using namespace std; 


void solve(){
	string ksa = "KSA";
	int idx{0};
	string str;
	cin >> str;
	int cnt{0};
	for(int i{0}; i < (int)str.size(); ++i){
		if(str[i]== ksa[idx]){
			idx = (idx + 1) % 3;
			cnt++;
		}
	}
	cout << ((int)str.size() - cnt)  * 2<< "\n";
}


int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}