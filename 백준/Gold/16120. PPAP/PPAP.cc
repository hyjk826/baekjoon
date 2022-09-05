// 2022-09-05
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
    string str;
    cin >> str;
    string s;
    for(int i{0}; i < (int)str.size(); ++i){
        s += str[i];
        if(s.size() >= 4){
            int n = (int)s.size();
            if(s[n - 1] == 'P' && s[n - 2] == 'A' && s[n - 3] == 'P' && s[n - 4] == 'P'){
                for(int j{0}; j < 3; ++j) s.pop_back();
            }
        }
    }
    if(s == "P") cout << "PPAP";
    else cout << "NP";
}
	

