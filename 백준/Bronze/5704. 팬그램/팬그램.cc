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
    while(getline(cin, str)){
        if(str == "*") break;
        vi ch(26);
        for(auto& c : str){
            ch[c - 'a'] = 1;
        }
        bool ok = true;
        for(int i{0}; i < 26; ++i){
            ok &= ch[i];
        }
        if(ok) cout << "Y\n";
        else cout << "N\n";
    }
}
