// 2022-09-20
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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string c = s;
    int cnt1{0}, cnt2{0};
    for(int i{0}; i < n - 1; ++i){
        if(c[i] != t[i]){
            for(int j{i}; j < i + 3 && j < n; ++j){
                if(c[j] == '1' ) c[j] = '0';
                else c[j] = '1';
            }
            cnt1++;
        }
    }
    if(c.back() != t.back()) cnt1 = MAX;
    if(s[0] == '1') s[0] = '0';
    else s[0] = '1';
    if(s[1] == '1') s[1] = '0';
    else s[1] = '1';
    cnt2++;
    for(int i{0}; i < n - 1; ++i){
        if(s[i] != t[i]){
            for(int j{i}; j < i + 3 && j < n; ++j){
                if(s[j] == '1' ) s[j] = '0';
                else s[j] = '1';
            }
            cnt2++;
        }
    }
    if(s.back() != t.back()) cnt2 = MAX;
    int ans = min(cnt1, cnt2);
    if(ans == MAX) cout << -1;
    else cout << ans;
}
	

