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

const int sz = 300000;
int pmn[sz];
int pmx[sz];
int smn[sz];
int smx[sz];
int X[sz];
int Y[sz];

int main(){
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    for(int i{0}; i < n; ++i){
        X[i] = vec[i].first;
        Y[i] = vec[i].second;
        pmn[i] = pmx[i] = smn[i] = smx[i] = Y[i];
    }
    for(int i{1}; i < n; ++i){
        pmn[i] = min(pmn[i], pmn[i - 1]);
        pmx[i] = max(pmx[i], pmx[i - 1]);
    }
    for(int i{n - 2}; i >= 0; --i){
        smn[i] = min(smn[i], smn[i + 1]);
        smx[i] = max(smx[i], smx[i + 1]);
    }
    ll l{0}, r{(int)2e9};
    ll ans{-1};
    while(l <= r){
        ll mid{(l + r) >> 1};
        int j{0};
        bool ok = false;
        for(int i{0}; i < n; ++i){
            while(j < n && X[j] - X[i] <= mid) j++;
            ll a{LLONG_MAX}, b{-LLONG_MAX};
            if(i){
                a = min(a, (ll)pmn[i - 1]);
                b = max(b, (ll)pmx[i - 1]);
            }
            if(j < n){
                a = min(a, (ll)smn[j]);
                b = max(b, (ll)smx[j]);
            }
            if(a == LLONG_MAX || b - a <= mid){
                ok = true; break;
            }
        }
        if(ok){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << fixed << setprecision(1);
    cout << ans * 0.5;
}
