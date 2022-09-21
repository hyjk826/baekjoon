// 2022-09-21
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
    int zero{0};
    ll ans{0};
    vi plus, minus;
    map<int, int> A, B;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        if(a > 0){
            A[a]++;
            plus.push_back(a);
        }
        else if(a < 0){
            minus.push_back(a);
            B[a]++;
        }
        else zero++;
    }
    if(zero >= 3){
        ans += 1LL * zero * (zero - 1) * (zero - 2) / 6;
    }
    if(zero){
        for(auto& i : A){
            if(B.count(-i.first)){
                ans += 1LL * zero * i.second * B[-i.first];
            }
        }
    }
    for(int i{0}; i < (int)minus.size(); ++i){
        for(int j{i + 1}; j < (int)minus.size(); ++j){
            int sum = minus[i] + minus[j];
            if(A.count(-sum)) ans += A[-sum];
        }
    }
    for(int i{0}; i < (int)plus.size(); ++i){
        for(int j{i + 1}; j < (int)plus.size(); ++j){
            int sum = plus[i] + plus[j];
            if(B.count(-sum)) ans += B[-sum];
        }
    }
    cout << ans;
}
	

