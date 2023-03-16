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

int main(){
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    int ans{0};
    function<void(int, int)> dfs = [&](int L, int cnt){
        ans = max(ans, cnt);
        if(L >= n) return;
        else{
            if(vec[L].first <= 0) {
                dfs(L + 1, cnt);
                return;
            }
            for(int i{0}; i < n; ++i){
                if(L == i || vec[i].first <= 0) continue;
                vec[L].first -= vec[i].second;
                vec[i].first -= vec[L].second;
                int sum{0};
                if(vec[L].first <= 0) sum++;
                if(vec[i].first <= 0) sum++;
                dfs(L + 1, cnt + sum);
                vec[L].first += vec[i].second;
                vec[i].first += vec[L].second;                
            }
        }
    };
    dfs(0, 0);
    cout << ans;
}
