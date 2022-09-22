// 2022-09-22
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
    while(1){
        char c;
        cin >> c;
        if(c == '#') break;
        string s;
        getline(cin, s);
        int ans{0};
        for(int i{0}; i < (int)s.size(); ++i){
            if(tolower(s[i]) == c || toupper(s[i]) == c) ans++;
        }
        cout << c << " " << ans << "\n";
    }
}
	

