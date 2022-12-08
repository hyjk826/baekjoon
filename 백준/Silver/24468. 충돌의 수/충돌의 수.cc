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
	int L, n, t;
    cin >> L >> n >> t;
    vp A(n);
    for(int i{0}; i < n; ++i){
        char c;
        cin >> A[i].first >> c;
        if(c == 'R') A[i].second = 1;
        else A[i].second = -1;
    }
    int ans{0};
    for(int i{0}; i < t; ++i){
        vector<vi> B(L + 1);
        for(int j{0}; j < n; ++j){
            if(A[j].second == 1){
                if(A[j].first == L){
                    A[j].first = L - 1;
                    A[j].second = -1;
                }
                else A[j].first++;
            }
            else if(A[j].second == -1){
                if(A[j].first == 0){
                    A[j].first = 1;
                    A[j].second = 1;
                }
                else A[j].first--;
            }
            B[A[j].first].push_back(j);
        }
        for(int j{0}; j <= L; ++j){
            if(B[j].size() == 2){
                ans++;
                A[B[j][0]].second *= -1;
                A[B[j][1]].second *= -1;
            }
        }
    }
    cout << ans;
}
	
