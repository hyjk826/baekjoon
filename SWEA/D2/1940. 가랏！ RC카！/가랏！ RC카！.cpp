// 2022-09-24
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
	int T;
	cin >> T;
	for(int t{1}; t <= T; ++t){
		cout << "#" << t << " ";
        int ans{0};
        int cur{0};
        int n;
        cin >> n;
        for(int i{0}; i < n; ++i){
            int q;
            cin >> q;
            if(q == 0) ans += cur;
            else if(q == 1){
                int a;
                cin >> a;
                cur += a;
                ans += cur;                
            }
            else{
                int a;
                cin >> a;
                cur = max(0, cur - a);
                ans += cur;
            }
        }
        cout << ans << "\n";
	}
}
	

