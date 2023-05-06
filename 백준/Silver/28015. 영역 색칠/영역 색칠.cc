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
	int n, m;
    cin >> n >> m;
    int ans{0};
    for(int i{0}; i < n; ++i){
        vi A;
        for(int j{0}; j < m; ++j){
            int a;
            cin >> a;
            if(a == 0){
                if(A.empty()) continue;
                int cnt{1};
                for(int k{0}; k < (int)A.size() - 1; ++k){
                    if(A[k] != A[k + 1]) cnt++;
                }
                ans += cnt / 2 + 1;
                A.clear();
            }
            else A.push_back(a);
        }
        if(!A.empty()){
            int cnt{1};
            for(int k{0}; k < (int)A.size() - 1; ++k){
                if(A[k] != A[k + 1]) cnt++;
            }
            ans += cnt / 2 + 1;
        }
    }
    // 1 -> 1
    // 2 -> 2
    // 3 -> 2
    // 4 -> 3
    // 5 -> 3
    cout << ans;
}
