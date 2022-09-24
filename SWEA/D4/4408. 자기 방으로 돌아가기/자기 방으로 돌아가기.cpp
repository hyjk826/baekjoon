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
        vi ch(402);
        int n;
        cin >> n;
        for(int i{0}; i < n; ++i){
            int a, b;
            cin >> a >> b;
            a = (a - 1) / 2;
            b = (b - 1) / 2;
            if(a > b) swap(a, b);
            ch[a]++;
            ch[b + 1]--;
        }
        for(int i{1}; i < 400; ++i){
            ch[i] += ch[i - 1];
        }
        int ans{0};
        for(int i{0}; i < 400; ++i){
            ans = max(ans, ch[i]);
        }
        cout << ans << "\n";
	}
}
	