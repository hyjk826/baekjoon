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
    int n, k, s;
    cin >> n >> k >> s;
    vp A, B;
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        if(a < s) A.push_back({a, b});
        else if(a > s) B.push_back({a, b});
    }
    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    ll ans{0};
    while(!A.empty()){
        int a = k;
        if(A.back().second > a){
            ans += 1LL * A.back().second / k * 2 * (s - A.back().first);
            A.back().second %= k;
            if(A.back().second == 0) A.pop_back();
        }
        else{
            ans += 1LL * 2 * (s - A.back().first);
            while(a && !A.empty()){
                int q = min(a, A.back().second);
                A.back().second -= q;
                a -= q;
                if(A.back().second == 0) A.pop_back();
            }
        }
    }
    while(!B.empty()){
        int a = k;
        if(B.back().second > a){
            ans += 1LL * B.back().second / k * 2 * abs(s - B.back().first);
            B.back().second %= k;
            if(B.back().second == 0) B.pop_back();
        }
        else{
            ans += 1LL * 2 * abs(s - B.back().first);
            while(a && !B.empty()){
                int q = min(a, B.back().second);
                B.back().second -= q;
                a -= q;
                if(B.back().second == 0) B.pop_back();
            }
        }
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
