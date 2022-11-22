// 2022-11-21
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

int main() {
	fastio;	
	int n, k;
    cin >> n >> k;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    int l{1}, r{30000};
    int ans{0};
    while(l <= r){
        int m{(l + r) / 2};
        int cnt{1};
        int sum{0};
        bool flag = true;
        for(int i{0}; i < n; ++i){
            if(vec[i] > m){
                flag = false;
                break;
            }
            if(sum + vec[i] > m){
                cnt++;
                sum = vec[i];
            }
            else sum += vec[i];
        }
        if(flag && cnt <= k){
            r = m - 1;
            ans = m;
        }
        else l = m + 1;
    }
    vi A;
    int sum{0};
    int cnt{0};
    for(int i{0}; i < n; ++i){
        if(sum + vec[i] > ans){
            A.push_back(cnt);
            cnt = 1;
            sum = vec[i];
        }
        else {
            cnt++;
            sum += vec[i];
        }
        if(i == n - 1){
            A.push_back(cnt);
        }
    }
    int need = k - (int)A.size();
    cout << ans << "\n";
    for(int i{0}; i < (int)A.size(); ++i){
        int b = min(need, A[i] - 1);
        need -= b;
        A[i] -= b;
        for(int j{0}; j < b; ++j){
            cout << 1 << " ";
        }
        cout << A[i] << " ";
    }
}
	

