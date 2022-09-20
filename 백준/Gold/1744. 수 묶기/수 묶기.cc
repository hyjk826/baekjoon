// 2022-01-12
#include <bits/stdc++.h>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353LL
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> plus, minus, zero, one;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a == 1) one.push_back(a);
        else if(a > 0) plus.push_back(a);
        else if(a < 0) minus.push_back(a);
        else zero.push_back(a);
    }
    sort(plus.begin(), plus.end(), greater<int>());
    sort(minus.begin(), minus.end());
    int ans{0};
    for(int i{0}; i < (int)minus.size() / 2 * 2; i += 2){
        ans += minus[i] * minus[i+1];
    }
    if((int)zero.size() == 0 && (int)minus.size() % 2 == 1){
        ans += minus.back();
    }
    for(int i{0}; i < (int)plus.size() / 2 * 2;  i += 2){
        ans += plus[i] * plus[i+1];
    }
    if((int)plus.size() % 2 == 1) ans += plus.back();
    ans += (int)one.size();
    cout << ans;
}
