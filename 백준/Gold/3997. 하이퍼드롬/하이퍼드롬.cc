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
    int n;
    cin >> n;
    string str;
    cin >> str;
    vl vec(n + 1);
    map<ll, int> mp;
    ll ans{0};
    mp[0]++;
    for(int i{1}; i <= n; ++i){
        int a;
        if(str[i - 1] >= 'a' && str[i - 1] <= 'z') a = str[i - 1] - 'a';
        else a = str[i - 1] - 'A' + 26;
        vec[i] = vec[i - 1] ^ (1LL << a);
        if(mp.count(vec[i])) ans += mp[vec[i]];
        for(int j{0}; j < 52; ++j){
            if(mp.count(vec[i] ^ (1LL << j))) ans += mp[vec[i] ^ (1LL << j)];
        }
        mp[vec[i]]++;
    }
    cout << ans;
}
