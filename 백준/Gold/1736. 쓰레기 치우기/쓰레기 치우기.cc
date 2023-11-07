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

int LIS(vi& A){
    vi v;
    for(int i{0}; i < (int)A.size(); ++i){
        if(v.empty() || v.back() < A[i]) v.push_back(A[i]);
        else{
            int idx = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            v[idx] = A[i];
        }
    }
    return v.size();
}

void solve(){
	int n, m;
    cin >> n >> m;
    vp vec;
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            if(a) vec.push_back({i, j});
        }
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    vi tmp;   
    for(auto& i : vec) tmp.push_back(i.second);
    cout << LIS(tmp) << "\n";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
