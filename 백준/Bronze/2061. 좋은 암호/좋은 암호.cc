// 2022-12-07
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
	string str;
    cin >> str;
    int k; cin >> k;
    for(int i{2}; i < k; ++i){
        int a{0};
        for(int j{0}; j < (int)str.size(); ++j){
            a = a * 10 + (str[j] - '0');
            a %= i;
        }
        if(a == 0){
            cout << "BAD " << i;
            return 0;
        }
    }
    cout << "GOOD";
}
	
