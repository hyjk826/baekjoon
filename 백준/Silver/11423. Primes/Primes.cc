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

int p[10000001];

void init(){
    p[1] = 1;
    for(ll i{2}; i <= 10000000; ++i){
        if(p[i]) continue;
        for(ll j{i * i}; j <= 10000000; j += i){
            p[j] = 1;
        }
    }
    for(int i{1}; i <= 10000000; ++i) p[i] += p[i - 1];
}

void solve(int a, int b){
    cout << (b - a + 1) - (p[b] - p[a - 1]) << "\n\n";
}

int main(){
	fastio;
    init();
    int l, r;
	while(cin >> l >> r){
		solve(l, r);
	}
}
