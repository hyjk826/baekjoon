// 2022-11-11
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
    vi vec(4);
    for(int i{0}; i < 4; ++i){
        cin >> vec[i];
    }
    int k{MAX};
    for(int i{0}; i < 4; ++i){
        rotate(vec.begin(), vec.begin() + 1, vec.end());
        int sum{0};
        for(auto& j : vec){
            sum = sum * 10 + j;
        }
        k = min(k, sum);
    }
    vi B;
    for(int i{1}; i <= 9; ++i){
        for(int j{1}; j <= 9; ++j){
            for(int a{1}; a <= 9; ++a){
                for(int b{1}; b <= 9; ++b){
                    vi A;
                    A.push_back(i);
                    A.push_back(j);
                    A.push_back(a);
                    A.push_back(b);
                    int mn{MAX};
                    for(int l{0}; l < 4; ++l){
                        rotate(A.begin(), A.begin() + 1, A.end());
                        int sum{0};
                        for(auto& r : A){
                            sum = sum * 10 + r;
                        }
                        mn = min(mn, sum);
                    }               
                    B.push_back(mn);
                }
            }
        }
    }
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    cout << lower_bound(B.begin(), B.end(), k) - B.begin() + 1;
}
	

