// 2022-07-16
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
	string s, t;
    cin >> s >> t;
    int n = max((int)s.size(), (int)t.size());
    if((int)s.size() > (int)t.size()){
        t = string((int)s.size() - (int)t.size(), '0') + t;
    }
    else{
        s = string((int)t.size() - (int)s.size(), '0') + s;
    }
    vi vec(n + 1);
    for(int i{n}; i >= 1; --i){
        vec[i] += s[i - 1] - '0' + t[i - 1] - '0';
        if(vec[i] >= 10){
            vec[i] -= 10;
            vec[i - 1]++;
        }
    }
    if(vec.front() != 0) cout << vec.front();
    for(int i{1}; i <= n; ++i){
        cout << vec[i];
    }
}
