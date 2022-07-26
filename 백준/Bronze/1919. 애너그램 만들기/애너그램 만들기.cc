// 2022-07-26
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
    string s, t;
    cin >> s >> t;
    vi A(26), B(26);
    for(int i{0}; i < (int)s.size(); ++i){
        A[s[i] - 'a']++;
    }
    for(int i{0}; i < (int)t.size(); ++i){
        B[t[i] - 'a']++;
    }
    int cnt{0};
    for(int i{0}; i < 26; ++i){
        cnt += min(A[i], B[i]) * 2;
    }
    cout << (int)s.size() + (int)t.size() - cnt;
}

