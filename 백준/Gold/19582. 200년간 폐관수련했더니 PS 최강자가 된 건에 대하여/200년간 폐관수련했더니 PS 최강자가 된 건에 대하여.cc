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
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    ll sum{0};
    int idx{-1};
    for(int i{0}; i < n; ++i){
        if(sum > vec[i].first){
            idx = i;
            break;
        }
        sum += vec[i].second;
    }
    if(idx == -1) cout << "Kkeo-eok";
    else{
        bool ok = true;
        sum = 0;
        for(int i{0}; i < n; ++i){
            if(idx == i) continue;
            if(sum > vec[i].first){
                ok = false;
                break;
            }
            sum += vec[i].second;
        }
        if(ok) cout << "Kkeo-eok";
        else{
            int mx{0};
            int a = -1;
            for(int i{0}; i < idx; ++i){
                if(mx < vec[i].second){
                    mx = vec[i].second;
                    a = i;
                }
            }
            ok = true;
            sum = 0;
            for(int i{0}; i < n; ++i){
                if(a == i) continue;
                if(sum > vec[i].first){
                    ok = false;
                    break;
                }
                sum += vec[i].second;
            }
            if(ok) cout << "Kkeo-eok";
            else cout << "Zzz";
        }
    }
}
