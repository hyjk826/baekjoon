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
#define MAX 2147000000
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct st{
    int a, b;
    bool operator< (const st& x) const{
        return make_pair(a, b) > make_pair(x.a, x.b);
    }
};

struct st2{
    int a, b, c;
};


void solve(){
    int n, k;
    cin >> n >> k;
    priority_queue<st> pQ;
    for(int i{0}; i < k; ++i){
        pQ.push({0, i});
    }
    ll ans{0};
    vector<vp> ch(k);
    for(int i{0}; i < n; ++i){
        int a, b;
        cin >> a >> b;
        auto x = pQ.top();
        ch[x.b].push_back({a, x.a + b});
        pQ.pop();
        pQ.push({x.a + b, x.b});
    }
    vector<st2> tmp;
    for(int i{0}; i < k; ++i){
        for(auto& j : ch[i]){
            tmp.push_back({j.second, i, j.first});
        }
    }
    sort(tmp.begin(), tmp.end(), [&](st2& x, st2& y){
        if(x.a == y.a) return x.b > y.b;
        else return x.a < y.a;
    });
    for(int i{0}; i < n; ++i){
        ans += 1LL * (i + 1) * tmp[i].c;
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
