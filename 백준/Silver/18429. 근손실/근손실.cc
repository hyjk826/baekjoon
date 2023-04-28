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
    int n, k;
    cin >> n >> k;
    vi A(n);
    for(auto& i : A) cin >> i;
    vi vec(n);
    iota(vec.begin(), vec.end(), 0);
    int ans{0};
    do{
        bool ok = true;
        int sum{500};
        for(int i{0}; i < n; ++i){
            sum += A[vec[i]];
            sum -= k;
            if(sum < 500) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(vec.begin(), vec.end()));
    cout << ans;
}
