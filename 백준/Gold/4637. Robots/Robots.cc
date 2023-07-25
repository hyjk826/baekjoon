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

bool solve(){
    vp A;
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        if(a == -1) return false;
        A.push_back({a, b});
    }
    sort(A.begin(), A.end());
    vi ch((int)A.size());
    int ans{0};
    while(1){
        int k{-1};
        for(int i{0}; i < (int)A.size(); ++i){
            if(ch[i] == 0){
                k = i; break;
            }
        }
        if(k == -1) break;
        int pre{-1};
        for(int i{k}; i < (int)A.size(); ++i){
            if(ch[i]) continue;
            if(pre <= A[i].second){
                pre = A[i].second;
                ch[i] = 1;
            }
        }
        ans++;
    }
    cout << ans << "\n";
    return 1;
}

int main(){
	fastio;
    while(1){
        if(!solve()) break;
    }
}