// 2022-11-25
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

int cnt{0};
string s;

int recursion(int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(l+1, r-1);
}

int main() {
	fastio;	
    int t;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> s;
        cout << recursion(0, (int)s.size() - 1) << " ";
        cout << cnt << "\n";
    }
}
	
