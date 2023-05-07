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
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vl cnt(10);
    vi ch(10);
    for(int i{0}; i < n; ++i){
        ll k{1};
        ch[vec[i][0] - 'A'] = 1;
        for(int j{(int)vec[i].size() - 1}; j >= 0; --j){
            cnt[vec[i][j] - 'A'] += k;
            k *= 10;
        }
    }
    ll ans{0};
    for(int i{0}; i < 10; ++i){
        if(ch[i]) continue;
        ll sum{0};
        vl A;
        for(int j{0}; j < 10; ++j){
            if(i == j) continue;
            A.push_back(cnt[j]);
        }
        sort(A.rbegin(), A.rend());
        for(int i{0}; i < (int)A.size(); ++i){
            sum += A[i] * (9 - i);
        }
        ans = max(ans, sum);
    }
    cout << ans;
}
