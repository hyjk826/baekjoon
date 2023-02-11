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
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi ch(d + 1);
    int cnt{0};
    for(int i{0}; i < k; ++i){
        ch[vec[i]]++;
        if(ch[vec[i]] == 1) cnt++;
    }
    int ans{0};
    if(ch[c] == 0){
        ans = max(ans, cnt + 1);
    }
    else ans = max(ans, cnt);
    for(int i{0}; i < n; ++i){
        ch[vec[i]]--;
        if(ch[vec[i]] == 0) cnt--;
        ch[vec[(i + k) % n]]++;
        if(ch[vec[(i + k) % n]] == 1) cnt++;
        if(ch[c] == 0){
            ans = max(ans, cnt + 1);
        }
        else ans = max(ans, cnt);
    }
    cout << ans;
}
