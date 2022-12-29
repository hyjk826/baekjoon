// 2022-12-30
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
    vi ch(360);
    vi vec;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        vec.push_back(a);
        ch[a] = 1;
    }
    while(1){
        vi v;
        for(int i{0}; i < (int)vec.size(); ++i){
            for(int j{0}; j < (int)vec.size(); ++j){
                int a = (vec[i] + vec[j]) % 360;
                int b = abs(vec[i] - vec[j]);
                if(ch[a] == 0){
                    ch[a] = 1;
                    v.push_back(a);
                }
                if(ch[b] == 0){
                    ch[b] = 1;
                    v.push_back(a);
                }
            }
        }
        if(v.empty()) break;
        for(auto& j : v) vec.push_back(j);
    }
    while(m--){
        int a;
        cin >> a;
        if(ch[a]) cout << "YES\n";
        else cout << "NO\n";
    }
}
