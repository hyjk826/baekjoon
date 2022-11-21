// 2022-11-20
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

int main() {
	fastio;	
	int n, k;
    cin >> n >> k;
    vl vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vl A, B;
    A.push_back(0);
    B.push_back(0);
    for(int i{0}; i < n - 1; ++i){
        A.push_back((vec[i + 1] - vec[i] + k) % k);
    }
    for(int i{0}; i < n - 1; ++i){
        B.push_back((vec[i] - vec[i + 1] + k) % k);
    }
    A.push_back(0);
    B.push_back(0);
    for(int i{(int)A.size() - 2}; i >= 0; --i){
        A[i] += A[i + 1];
    }
    for(int i{1}; i < (int)B.size(); ++i){
        B[i] += B[i - 1];
    }
    for(int i{(int)A.size() - 2}; i >= 0; --i){
        A[i] = max(A[i], A[i + 1]);
    }
    for(int i{1}; i < (int)B.size(); ++i){
        B[i] = max(B[i], B[i - 1]);
    }
    int idx{-1};
    ll mn{LLONG_MAX};
    for(int i{1}; i <= n; ++i){
        if(mn > max(A[i], B[i - 1])){
            mn = max(A[i], B[i - 1]);
            idx = i;
        }
    }
    cout << idx << "\n" << mn;
}

	

