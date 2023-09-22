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


void solve(){
	int n;
    cin >> n;
    string str;
    cin >> str;
    int d, m;
    cin >> d >> m;
    int cnt{0};
    int h,y,u;
    int ans{0};
    h = y = u = 0;
    for(int i{0}; i < n; ++i){
        if(str[i]== 'H') h++;
        else if(str[i] == 'Y') y++;
        else if(str[i] == 'U') u++;
        else{
            cnt++; continue;
        }
        if(cnt){
            ans += min(d * cnt, d + m);
        }
        cnt = 0;
    }
    if(cnt){
        ans += min(d * cnt, d + m);
    }
    if(ans == 0) cout << "Nalmeok\n";
    else cout << ans << "\n";
    if(min({h, y, u}) == 0) cout << "I love HanYang University\n";
    else cout << min({h, y, u});
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
