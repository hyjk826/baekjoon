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
    string str;
    cin >> str;
    string s = str;
    ll ans{0};
    ans += stoll(str);
    while(1){
        char c= str.back();
        str.pop_back();
        str.insert(str.begin(), c);
        if(str == s) break;
        ans += stoll(str);
    }
    cout << ans;
}
