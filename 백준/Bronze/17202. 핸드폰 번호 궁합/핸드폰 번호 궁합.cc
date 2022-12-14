// 2022-12-14
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
    string str;
    for(int i{0}; i < (int)s.size(); ++i){
        str += s[i];
        str += t[i];
    }
    while(str.size() > 2){
        string s;
        for(int i{0}; i < (int)str.size() - 1; ++i){
            int a = 0;
            a += (str[i] - '0');
            a += (str[i + 1] - '0');
            s += char('0' + (a % 10));
        }
        swap(s, str);
    }
    cout << str;
}
	
