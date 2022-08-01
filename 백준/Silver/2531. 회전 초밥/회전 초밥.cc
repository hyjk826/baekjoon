// 2022-07-31
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
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vi vec(n * 2);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        vec[i + n] = vec[i];
    }
    map<int, int> m;
    for(int i{0}; i < k; ++i){
        m[vec[i]]++;
    }
    int ans;
    if(m.count(c)) ans = m.size();
    else ans = m.size() + 1;
    int cnt = m.size();
    for(int i{k}; i < n * 2; ++i){
        if(!m.count(vec[i])){
            cnt++;
        }
        else{
            if(m[vec[i]] == 0) cnt++; 
        }
        m[vec[i]]++;
        m[vec[i - k]]--;
        if(m[vec[i - k]] == 0){
           cnt--; 
        }
        if(m.count(c) == 0){
            ans = max(ans, cnt + 1);
        }
        else{
            if(m[c] == 0) ans = max(ans, cnt + 1);
            else ans = max(ans, cnt);
        }
    }
    cout << ans;
}

