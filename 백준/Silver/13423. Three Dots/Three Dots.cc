// 2022-05-27
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi vec(n);
        for(int i{0}; i < n; ++i){
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        int ans{0};
        for(int i{0}; i < n; ++i){
            for(int j{i + 1}; j < n; ++j){
                int k = vec[j] + vec[j] - vec[i];
                auto it = lower_bound(vec.begin(), vec.end(), k);
                if(it != vec.end() && *it == k) ans++;
            }
        }
        cout << ans << "\n";
    }
}