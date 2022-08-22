// 2022-08-23
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
    int n, c;
    cin >> n >> c;
    vi ch(c + 1);
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        for(int j{a}; j <= c; j += a){
            ch[j] = 1;
        }
    }
    cout << count(ch.begin(), ch.end(), 1);
}

