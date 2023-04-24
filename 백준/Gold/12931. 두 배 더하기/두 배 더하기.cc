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
    vi vec(n);
    int sum{0};
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        sum += vec[i];
    }
    int ans{0};
    while(sum){
        int cnt{0};
        sum = 0;
        for(int i{0}; i < n; ++i){
            if(vec[i]& 1){
                ans++;
                vec[i]--;
            }
            sum += vec[i];
        }
        if(sum){
            sum = 0;
            ans++;
            for(int i{0}; i < n; ++i){
                vec[i] /= 2;
                sum += vec[i];
            }
        }
    }
    cout << ans;
}
