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

int LIS(vi& A){
    vi v;
    for(int i{0}; i < (int)A.size(); ++i){
        if(v.empty() || v.back() <= A[i]) v.push_back(A[i]);
        else{
            int idx = upper_bound(v.begin(), v.end(), A[i]) - v.begin();
            v[idx] = A[i];
        }
    }
    return v.size();
}

int main(){
	fastio;
    int n;
    cin >> n;
    vp vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end(), [&](pi& x, pi& y){
        if(x.first == y.first) return x.second > y.second;
        return x.first < y.first;
    });
    vi A;
    for(int i{0}; i < (int)vec.size(); ++i){
        if(i && vec[i] == vec[i - 1]) continue;
        A.push_back(vec[i].second);
    }
    reverse(A.begin(), A.end());
    cout << LIS(A);
}
