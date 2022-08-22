// 2022-08-22
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
    for(int i{0}; i < 3; ++i){
        string str;
        cin >> str;
        str += 'a';
        int mx{1};
        int cnt{1};
        for(int j{1}; j < (int)str.size(); ++j){
            if(str[j] != str[j - 1]){
                mx = max(mx, cnt);
                cnt = 1;
            }
            else cnt++;
        }
        cout << mx << "\n";
    }
}

