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
    int n, m;
    cin >> n >> m;
    vi ch(n + 1);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        ch[a] = 1;
    }
    vi vec;
    for(int i{1}; i <= n; ++i){
        if(ch[i] == 0) vec.push_back(i);
    }
    if(vec.size() == 0) cout << 0;
    else if(vec.size() == 1) cout << 7;
    else{
        int ans{0};
        int cnt{1};
        for(int i{1}; i < (int)vec.size(); ++i){
            if(vec[i] - vec[i - 1] <= 3){
                cnt += vec[i] - vec[i - 1];
            }
            else{
                ans += 5 + cnt * 2;
                cnt = 1;
            }
            if(i == (int)vec.size() - 1) ans += 5 + cnt * 2;
        }
        cout << ans;
    }
}
