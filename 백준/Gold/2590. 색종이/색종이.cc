// 2022-09-21
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    vi cnt(7);
    for(int i{1}; i <= 6; ++i){
        cin >> cnt[i];
    }
    int ans{0};
    ans += cnt[6];
    ans += cnt[5];
    int k = min(cnt[1], cnt[5] * 11);
    cnt[1] -= k;
    ans += cnt[4];
    k = min(cnt[2], cnt[4] * 5);
    int one = 36 * cnt[4] - 16 * cnt[4] - k * 4;
    cnt[1] -= min(cnt[1], one);
    cnt[2] -= k;
    ans += cnt[3] / 4;
    cnt[3] %= 4;
    vi arr = {5, 3, 1};
    if(cnt[3]){
        ans++;
        int k = min(cnt[2], arr[cnt[3] - 1]);
        int one = 36 - cnt[3] * 9 - k * 4;
        cnt[2] -= k;
        cnt[1] -= min(cnt[1], one);
    }
    if(cnt[1] > 0 || cnt[2] > 0){
        ans += (cnt[1] + cnt[2] * 4 + 35) / 36; 
    }
    cout << ans;
}
	

