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
	int n;
    cin >> n;
    vi vec(n);
    for(auto& i : vec) cin >> i;
    sort(vec.begin(), vec.end());
    for(int i{0}; i < n - 1; ++i){
        if(vec[i] + 1 != vec[i + 1]) continue;
        int k{-1};
        for(int j{i + 1}; j < n; ++j){
            if(vec[j] >= vec[i] + 2){
                k = j; break;
            }
        }
        if(k == -1){
            int cnt{0};
            int idx{i};
            while(idx >= 0 && vec[i] == vec[idx]){
                cnt++;
                idx--;
            }
            int a = vec[i];
            int b = vec[i + 1];
            for(int j{idx + 1}; j < n - cnt; ++j) vec[j] = b;
            for(int j{n - cnt}; j < n; ++j) vec[j] = a;
            break;
        }
        else{
            swap(vec[i + 1], vec[k]);
        }
    }
    for(auto& i : vec) cout << i << " ";
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
