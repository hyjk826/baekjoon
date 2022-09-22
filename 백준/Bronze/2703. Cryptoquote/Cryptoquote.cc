// 2022-09-21
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
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--){
        getline(cin, s);
        string str;
        getline(cin, str);
        for(int i{0}; i < (int)s.size(); ++i){
            if(s[i] == ' ') continue;
            s[i] = str[s[i] - 'A'];
        }
        cout << s << "\n";
    }
}
	

