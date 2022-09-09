// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1234567891
using namespace std;

int main(){
    fastio;
    int n;
    cin >> n;
    string str;
    cin >> str;
    ll ans{0};
    ll k{1};
    for(int i{0}; i < (int)str.size(); ++i){
        ans += k * (str[i] - 'a' + 1);
        k *= 31;
        k %= MOD;
        ans %= MOD;
    }
    cout << ans;
}