// 2022-08-21
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	string str;
    cin >> str;
    for(int i{0}; i < (int)str.size() - 1; ++i){
        string s = str.substr(0, i + 1);
        string t = str.substr(i + 1);
        ll a{1}, b{1};
        for(auto& j : s){
            a *= (j - '0');
        }
        for(auto& j : t){
            b *= (j - '0');
        }
        if(a == b){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO";
}