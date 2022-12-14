// 2022-12-14
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
    vector<vi> A(5, vi(5));
    vector<vi> B(5, vi(5));
    for(int i{0}; i < 5; ++i){
        for(int j{0}; j < 5; ++j){
            cin >> A[i][j];
        }
    }
    for(int i{0}; i < 5; ++i){
        for(int j{0}; j < 5; ++j){
            cin >> B[i][j];
        }
    }
    vi C(5);
    for(int i{0}; i < 5; ++i){
        for(int j{0}; j < 5; ++j){
            for(int k{0}; k < 5; ++k){
                C[i] += A[i][k] * B[k][j];
            }
        }
    }
    string ans;
    vs name = {"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"};
    int mn = *min_element(C.begin(), C.end());
    for(int i{0}; i < 5; ++i){
        if(mn == C[i]){
            ans = name[i];
        }
    }
    cout << ans;
}
	
