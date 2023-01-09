// 2023-01-09
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
    vector<vi> g(n);
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    for(int i{1}; i < n; ++i){
        int a;
        cin >> a;
        a--;
        g[a].push_back(i);
    }
    ll ans{0};
    vi A(100001);
    vi B(100001);
    function<void(int)> dfs = [&](int cur){
        ans += B[vec[cur]] - A[vec[cur]];
        vi div;
        for(int i{1}; i * i <= vec[cur]; ++i){
            if(vec[cur] % i == 0){
                div.push_back(i);
                if(i * i == vec[cur]){
                    ans += A[i];
                    B[i]++;
                }
                else{
                    ans += A[i] + A[vec[cur] / i];
                    B[i]++;
                    B[vec[cur] / i]++;
                }
            }
        }
        A[vec[cur]]++;
        for(auto& i : g[cur]){
            dfs(i);
        }
        A[vec[cur]]--;
        for(auto& i : div){
            if(i * i == vec[cur]){
                B[i]--;
            }
            else{
                B[i]--;
                B[vec[cur] / i]--;
            }
        }
    };
    dfs(0);
    cout << ans;
}
