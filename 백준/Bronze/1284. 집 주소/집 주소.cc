// 2022-08-27
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
    while(cin >> str){
        if(str == "0") break;
        int ans{0};
        ans += (int)str.size() + 1;
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == '1') ans += 2;
            else if(str[i] == '0') ans += 4;
            else ans += 3;
        }
        cout << ans << "\n";
    }
}

