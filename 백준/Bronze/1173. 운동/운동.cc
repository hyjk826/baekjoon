// 2022-09-06
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
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;
    int ans{0};
    int cnt{0};
    int k = m;
    if(m + T > M){
        cout << -1;
        return 0;
    }
    while(cnt < N){
        if(k + T <= M){
            cnt++;
            k += T;
        }
        else{
            k = max(k - R, m);
        }
        ans++;
    }
    cout << ans;
}
	

