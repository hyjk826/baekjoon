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
        int j, n;
        cin >> j >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            int a, b;
            cin >> a >> b;
            vec[i] = a * b;
        }
        sort(vec.rbegin(), vec.rend());
        int sum{0};
        for(int i{0}; i < n; ++i){
            sum += vec[i];
            if(sum >= j){
                cout << i + 1 << "\n"; break;
            }
        }
    }
}
