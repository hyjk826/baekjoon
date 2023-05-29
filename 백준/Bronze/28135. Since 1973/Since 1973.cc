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
	int n;
    cin >> n;
    int cnt{1};
    for(int i{1}; i <= n; ++i){
        if(i == n) {
            cout << cnt; return 0;
        }
        string str = to_string(i);
        bool ok = false;
        for(int j{0}; j < (int)str.size() - 1; ++j){
            if(str[j] == '5' && str[j + 1] == '0') ok = true;
        }
        if(ok) cnt += 2;
        else cnt++;
    }
}
