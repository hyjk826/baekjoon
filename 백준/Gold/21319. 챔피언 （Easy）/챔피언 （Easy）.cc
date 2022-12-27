// 2022-12-27
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
    if(n == 1){
        cout << 1;
        return 0;
    }
    vi A(n);
    for(int i{0}; i < n; ++i){
        A[i] = vec[i] - i;
    }
    for(int i{n - 2}; i >= 0; --i){
        A[i] = max(A[i], A[i + 1]);
    }
    vi ans;
    for(int i{1}; i < n; ++i){
        if(vec[i] == vec[i - 1]) continue;
        if(i == n - 1 || vec[i] - 1 > A[i + 1]) ans.push_back(i + 1);
    }
    if(ans.empty()) cout << -1;
    else{
        for(auto& i : ans) cout << i << " ";
    }
}
