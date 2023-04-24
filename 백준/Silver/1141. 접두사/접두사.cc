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
    vs vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int ans{0};
    for(int i{0}; i < n; ++i){
        bool ok = true;
        for(int j{i + 1}; j < n; ++j){
            if(i == j) continue;
            if(vec[j].size() >= vec[i].size() && vec[j].substr(0, (int)vec[i].size()) == vec[i]) {
                ok = false;
            }
        }
        if(ok) ans++;
    }
    cout << ans;

}
