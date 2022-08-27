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
    int n, k;
    cin >> n >> k;
    vi ch(n);
    string str;
    cin >> str;
    int ans{0};
    for(int i{0}; i < n; ++i){
        if(str[i] == 'P'){
            for(int j{max(0, i - k)}; j <= min(i + k, n - 1); ++j){
                if(ch[j] == 0 && str[j] == 'H'){
                    ch[j] = 1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}

