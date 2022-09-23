// 2022-09-23
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
    sort(s.begin(), s.end());
    int ans{0};
    do{
        if(s.front() != '0' && stoi(s) < stoi(t)){
            ans = max(ans, stoi(s));
        }
    }while(next_permutation(s.begin(), s.end()));
    if(ans == 0) cout << -1;
    else cout << ans;
}
	

