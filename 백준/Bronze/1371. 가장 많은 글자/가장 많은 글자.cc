// 2022-08-14
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
    string str;
    vi cnt(26);
    while(getline(cin, str)){
        for(int i{0}; i < (int)str.size(); ++i){
            cnt[str[i] - 'a']++;
        }
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    string ans;
    for(int i{0}; i < 26; ++i){
        if(cnt[i] == mx){
            ans += char('a' + i);
        }
    }
    cout << ans;
}

