// 2022-12-12
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

int main() {
	fastio;
    string s, t;
    cin >> s >> t;
    int a, b;
    a = b = 0;
    for(int i{0}; i < (int)s.size(); ++i) if(s[i]== '1') a++;
    for(int i{0}; i < (int)t.size(); ++i) if(t[i]== '1') b++;
    if(a & 1) a++;
    if(b > a) cout << "DEFEAT";
    else cout << "VICTORY";
}
	
