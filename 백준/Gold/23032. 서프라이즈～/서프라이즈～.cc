// 2022-12-21
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
    vi vec(n + 1);
    for(int i{1}; i <= n; ++i){
        cin >> vec[i];
        vec[i] += vec[i - 1];
    }
    int ans{0};
    int mn{MAX};
    for(int i{1}; i < n; ++i){
        for(int j{i + 1}; j <= n; ++j){
            int sum = vec[j] - vec[i - 1];            
            int idx = lower_bound(vec.begin(), vec.end(), vec[i - 1] + sum / 2) - vec.begin();
            if(idx != j){
                int a = vec[idx] - vec[i - 1];
                int b = vec[j] - vec[idx];
                int dif = abs(a - b);
                if (mn > dif)
                {
                    mn = dif;
                    ans = sum;
                }
                else if (mn == dif) ans = max(ans, sum);
            }
            idx--;
            if(idx >= i){
                int a = vec[idx] - vec[i - 1];
                int b = vec[j] - vec[idx];
                int dif = abs(a - b);
                if (mn > dif)
                {
                    mn = dif;
                    ans = sum;
                }
                else if(mn == dif) ans = max(ans, sum);
            }
        }
    }
    cout << ans;
}
	
