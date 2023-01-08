// 2023-01-08
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

vi manachers(string str){
    int n = (int)str.size();
    int r{0}, p{0};
    vi A(n);
    for(int i{0}; i < n; ++i){
        if(i <= r) A[i] = min(r - i, A[2 * p - i]);
        else A[i] = 0;
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && str[i - A[i] - 1] ==str[i + A[i] + 1]) A[i]++;
        if(r < i + A[i]){
            r = i + A[i];
            p = i;
        }
    }
    return A;
}

int main(){
	fastio;
    string str;
    cin >> str;
    string s;
    for(int i{0}; i < (int)str.size(); ++i){
        s += '#';
        s += str[i];
    }
    s += '#';
    vi man = manachers(s);
    ll ans{0};
    for(int i{0}; i < (int)man.size(); ++i){
        if(i & 1) ans += (man[i] + 1) / 2;
        else ans += man[i] / 2;
    }
    cout << ans;
}
