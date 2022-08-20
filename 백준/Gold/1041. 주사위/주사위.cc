// 2022-08-20
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	ll n;
    cin >> n;
    ll mn{MAX};
    ll mx{0};
    vl vec(6);
    ll sum{0};
    for(int i{0}; i < 6; ++i){
        cin >> vec[i];
        mn = min(mn, vec[i]);
        mx = max(mx, vec[i]);
        sum += vec[i];
    }
    if(n == 1){
        cout << sum - mx;
        return 0;
    }
    swap(vec[3], vec[4]);
    ll mm{MAX};
    ll mm2{MAX};
    for(int i{1}; i <= 4; ++i){
        if(i < 4){
            mm = min(mm, vec[0] + vec[i] + vec[i + 1]);
            mm = min(mm, vec[5] + vec[i] + vec[i + 1]);
            mm2 = min(mm2, vec[i] + vec[i + 1]);
            mm2  = min(mm2, vec[0] + vec[i]);
            mm2  = min(mm2, vec[5] + vec[i]);
        }
        else{
            mm = min(mm, vec[0] + vec[i] + vec[1]);
            mm = min(mm, vec[5] + vec[i] + vec[1]);
            mm2  = min(mm2, vec[0] + vec[i]);
            mm2  = min(mm2, vec[5] + vec[i]);
            mm2 = min(mm2, vec[i] + vec[1]);
        }
    }
    ll k = (n - 2) * 4 + (n - 2) * 4 + 4;
    cout << mm * 4 + mm2 * k + (n * n * 5 - 4 * 3 - k * 2) * mn;
}