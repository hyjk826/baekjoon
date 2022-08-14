// 2022-08-14
#include <bits/stdc++.h>
#include <regex>
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
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        if(regex_match(str, regex("(100+1+|01)+"))) cout << "YES\n";
        else cout << "NO\n";
    }
}