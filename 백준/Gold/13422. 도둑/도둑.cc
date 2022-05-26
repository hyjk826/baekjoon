// 2022-05-27
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vi vec(2 * n + 1);
        for(int i{1}; i <= n; ++i){
            cin >> vec[i];
            vec[i + n] = vec[i];
        }
        for(int i{1}; i <= 2 * n; ++i){
            vec[i] += vec[i - 1];
        }
        int ans{0};
        if(n == m){
            if(vec[n] < k) cout << 1 << "\n";
            else cout << 0 << "\n";
            continue;
        }
        for(int i{0}; i < n; ++i){
            if(vec[i + m] - vec[i] < k) ans++;
        }
        cout << ans << "\n";
    }
}