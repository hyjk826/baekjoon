// 2022-12-08
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
	int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt{1};
    for(int i{1}; i < n; ++i){
        if(str[i] != str[i - 1]) cnt++;
    }
    cout << cnt / 2 + 1;
}
	
