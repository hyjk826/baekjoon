// 2022-09-18
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
	int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    vp A;
    A.push_back({vec[0].first, vec[0].second});
    for(int i{1}; i < (int)vec.size(); ++i){
        if(A.back().second < vec[i].first){
            A.push_back({vec[i].first, vec[i].second});
        }
        else A.back().second = max(A.back().second, vec[i].second);
    }
    int k{0};
    int ans{0};
    for(int i{0}; i < (int)A.size(); ++i){
        if(A[i].first <= k){
            ans = max(ans, A[i].second);
            k = max(k, A[i].second + A[i].second - A[i].first);
        }
    }
    cout << ans;
}
	

