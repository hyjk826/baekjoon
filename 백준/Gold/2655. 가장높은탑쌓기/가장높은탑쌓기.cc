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
    int a, b, h, idx;
};

int main(){
	fastio;
	int n;
    cin >> n;
    vector<st> vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i].a >> vec[i].h >> vec[i].b;
        vec[i].idx = i;
    }
    sort(vec.begin(), vec.end(), [&](st& x, st& y){
        return x.a < y.a;
    });
    vp dp(n + 1);
    int mmx{0}, iidx{0};
    for(int i{1}; i <= n; ++i){
        int mx{0}, idx{0};
        for(int j{0}; j < i; ++j){
            if(vec[j].a < vec[i].a && vec[j].b < vec[i].b){
                if(mx < dp[j].first){
                    mx = dp[j].first;
                    idx = j;
                }
            }
        }
        dp[i] = {mx + vec[i].h, idx};
        if(mmx < dp[i].first){
            mmx = dp[i].first;
            iidx = i;
        }
    }
    vi ans;
    while(iidx){
        ans.push_back(vec[iidx].idx);
        iidx = dp[iidx].second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto& i : ans) cout << i << "\n";
}
