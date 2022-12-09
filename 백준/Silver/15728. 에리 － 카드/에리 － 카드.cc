// 2022-12-08
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
    vi A(n), B(n);
    set<int> st;
    for(int i{0}; i < n; ++i){
        cin >> A[i];
    }
    for(int i{0}; i < n; ++i){
        cin >> B[i];
    }
    for(int i{0}; i <= k; ++i){
        int mx{-MAX};
        int idx{-1};
        for(int j{0}; j < n; ++j){
            for(int a{0}; a < (int)B.size(); ++a){
                if(A[j] * B[a] > mx){
                    mx = A[j] * B[a];
                    idx = a;
                }
            }
        }
        if(i == k){
            cout << mx;
            return 0;
        }
        B.erase(B.begin() + idx);
    }
}
	
