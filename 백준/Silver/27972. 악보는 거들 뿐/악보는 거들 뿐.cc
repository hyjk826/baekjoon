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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int ans{1};
    int cnt{1};
    for(int i{1}; i < n; ++i){
        if(vec[i] > vec[i - 1]) cnt++;
        else if(vec[i] < vec[i - 1]) cnt = 1;
        ans = max(ans, cnt);        
    }
    cnt = 1;
    for(int i{1}; i < n; ++i){
        if(vec[i] < vec[i - 1]) cnt++;
        else if(vec[i] > vec[i - 1]) cnt = 1;
        ans = max(ans, cnt);
    }
    cout << ans;
}
