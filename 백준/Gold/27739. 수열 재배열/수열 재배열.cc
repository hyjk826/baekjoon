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
    int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vi pre(n, 1), post(n, 1);
    for(int i{1}; i < n; ++i){
        if(vec[i - 1] < vec[i]) pre[i] = pre[i - 1] + 1;
    }
    for(int i{n - 2}; i >= 0; --i){
        if(vec[i] < vec[i + 1]) post[i] = post[i + 1] + 1;
    }
    int ans{k};
    for(int i{0}; i <= n - k; ++i){
        vi A;
        for(int j{i}; j < i + k; ++j) A.push_back(vec[j]);
        sort(A.begin(), A.end());
        if(i) ans = max(ans, (int)(A.end() - lower_bound(A.begin(), A.end(), vec[i - 1])) + pre[i - 1]);
        if(i + k < n) ans = max(ans, (int)(lower_bound(A.begin(), A.end(), vec[i + k]) - A.begin()) + post[i + k]);
        if(i && i + k < n && vec[i - 1] < A[0] && A.back() < vec[i + k]) ans = max(ans, pre[i - 1] + post[i + k] + k);
    }
    cout << ans;
}
