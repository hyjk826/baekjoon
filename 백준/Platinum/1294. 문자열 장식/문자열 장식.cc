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

struct st{
	string str;
	bool operator< (const st& x) const{
		return str + x.str > x.str + str;
	}
};


void solve(){
	int n;
	cin >> n;
	vs vec(n);
	for(int i{0}; i < n; ++i){
		cin >> vec[i];
	}
	priority_queue<st> pQ;
	for(int i{0}; i < n; ++i){
		pQ.push({vec[i]});
	}
	while(!pQ.empty()){
		string s = pQ.top().str;
		pQ.pop();
		cout << s[0];
		if(s.size() >= 2) pQ.push({s.substr(1)});
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
