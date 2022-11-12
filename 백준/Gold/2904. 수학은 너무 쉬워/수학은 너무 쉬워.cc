// 2022-11-13
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
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    vector<map<int, int> > A(n);
    map<int, int> sum;
    for(int i{0}; i < n; ++i){
        int a = vec[i];
        for(int j{2}; j * j <= vec[i]; ++j){
            while(a % j == 0){
                a /= j;
                A[i][j]++;
                sum[j]++;
            }
        }
        if(a != 1){
            A[i][a]++;
            sum[a]++;
        }
    }
    ll ans{1}, cnt{0};
    for(auto& i : sum){
        int a = i.second / n;
        for(int j{0}; j < n; ++j){
            if(A[j][i.first] < a) {
                cnt += a - A[j][i.first];
            }
        }
        for(int j{0}; j < a; ++j) ans *= i.first;
    }
    cout << ans << " " << cnt;
}
	

