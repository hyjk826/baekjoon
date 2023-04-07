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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vi two(n), five(n);
        for(int i{0}; i < n; ++i){
            int a;
            cin >> a;
            while(a % 2 == 0){
                two[i]++;
                a /= 2;
            }
            while(a % 5 == 0){
                five[i]++;
                a /= 5;
            }
        }
        for(int i{1}; i < n; ++i){
            int mn2{MAX};
            int mn5{MAX};
            for(int j{i - 1}; j >= max(0, i - k); --j){
                mn2 = min(mn2, two[j]);
                mn5 = min(mn5, five[j]);
            }
            two[i] += mn2;
            five[i] += mn5;
        }
        cout << min(two[n - 1], five[n - 1]) << "\n";
    }
}
