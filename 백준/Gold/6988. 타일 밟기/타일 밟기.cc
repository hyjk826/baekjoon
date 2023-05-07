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

int ch[3000][3000];


int main(){
	fastio;
	int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    ll ans{0};
    for(int i{0}; i < n; ++i){
        for(int j{i + 1}; j < n; ++j){
            if(ch[i][j]) continue;
            int dif = vec[j] - vec[i];
            int idx = j;
            int cnt{2};
            ll sum{vec[i] + vec[j]};
            ch[i][j] = 1;
            while(1){
                auto it = lower_bound(vec.begin(), vec.end(), vec[idx] + dif);
                if(it == vec.end() || *it != vec[idx] + dif) break;
                cnt++;
                ch[idx][it - vec.begin()] = 1;
                idx = it - vec.begin();
                sum += vec[idx];
            }
            if(cnt >= 3) ans = max(ans, sum);
        }
    }
    cout << ans;
}
