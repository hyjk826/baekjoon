// 2022-08-31
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
    while(t--){
        string str;
        cin >> str;
        string s = str.substr(0, 3);
        reverse(s.begin(), s.end());
        int a{0};
        int k{1};
        for(int i{0}; i < 3; ++i){
            a += k * (s[i] - 'A');
            k *= 26;
        }
        string t = str.substr(4, 4);
        int b = stoi(t);
        if(abs(a - b) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }
}

