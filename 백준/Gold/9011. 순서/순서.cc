// 2022-09-19
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        vi ans(n, -1);
        vi ch(n + 1);
        bool flag = true;
        for(int i{n - 1}; i >= 0; --i){
            int k = vec[i] + 1;
            for(int j{k}; j <= n; ++j){
                if(ch[j]) continue;
                int cnt{0};
                for(int a{1}; a < j; ++a){
                    if(ch[a] == 0) cnt++;
                }
                if(cnt == vec[i]){
                    ans[i] = j;
                    ch[j] = 1;
                    break;
                }
            }
            if(ans[i] == -1){
                flag = false;
                break;
            }
        }
        if(flag){
            for(auto& i : ans) cout << i << " ";
            cout << "\n";
        }
        else cout << "IMPOSSIBLE\n";
    }
}
	

