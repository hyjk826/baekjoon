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
    string A = "-\\(@?>&%/";
    while(cin >> str){
        if(str == "#") break;
        reverse(str.begin(), str.end());
        ll ans{0};
        ll k{1};
        for(int i{0}; i < (int)str.size(); ++i){
            int idx = A.find(str[i]);
            if(idx == 8) idx = -1;
            ans += k * idx;
            k *= 8;
        }
        cout << ans << "\n";
    }
}
