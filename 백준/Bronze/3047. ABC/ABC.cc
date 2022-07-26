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
    vi v(3);
    for(int i{0}; i < 3; ++i) cin >> v[i];
    string str;
    cin >> str;
    sort(v.begin(), v.end());
    for(int i{0}; i < 3; ++i){
        if(str[i] == 'A') cout << v[0];
        else if(str[i] == 'B') cout << v[1];
        else cout << v[2];
        cout << " ";
    }
}

