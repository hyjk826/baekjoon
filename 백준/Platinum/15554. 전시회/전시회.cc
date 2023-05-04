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
    vpl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i].first >> vec[i].second;
    }
    sort(vec.begin(), vec.end());
    vpl C;
    C.push_back(vec[0]);
    for(int i{1}; i < n; ++i){
        if(vec[i].first == C.back().first) C.back().second += vec[i].second;
        else C.push_back(vec[i]);
    }
    vl A;
    vl B;
    A.push_back(0); B.push_back(0);
    for(auto& i : C){
        A.push_back(i.first);
        B.push_back(i.second);
    }
    for(int i{1}; i <= (int)C.size(); ++i){
        B[i] += B[i - 1];
    }
    vl smx = B;
    for(int i{0}; i < (int)smx.size(); ++i){
        smx[i] -= A[i];
    }
    for(int i{(int)smx.size() - 2}; i >= 0; --i){
        smx[i] = max(smx[i], smx[i + 1]);
    }
    ll ans{0};
    for(int i{0}; i < (int)smx.size() - 1; ++i){
        ans = max(ans, smx[i + 1] - B[i] + A[i + 1]);
    }
    cout << ans;
}
