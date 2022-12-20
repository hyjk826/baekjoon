// 2022-05-14
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n;
    cin >> n;
    vi vec(n);
    int ans{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        if(i % 2 == 0) ans += vec[i];
    }
    vi pre(n), post(n);
    for(int i{n - 3}; i >= 0; i -= 2){
        post[i] = post[i + 2] + vec[i];
    }
    pre[0] = vec[0];
    for(int i{2}; i < n - 1; i += 2){
        pre[i] = pre[i - 2] + vec[i];
    }
    for(int i{0}; i < n; i += 2){
        if(i == 0){
            ans = max(ans, vec.back() + post[i + 1]);
        }
        else{
            ans = max(ans, vec.back() + pre[i - 2] + post[i + 1]);
        }
    }
    for(int i{1}; i < n - 1; i += 2){
        ans = max(ans, pre[i - 1] + post[i]);
    }
    cout << ans;
}