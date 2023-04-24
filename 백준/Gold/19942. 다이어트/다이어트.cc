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
    vi arr(4);
    for(int i{0}; i < 4; ++i){
        cin >> arr[i];
    }
    vector<vi> board(n, vi(5));
    for(int i{0}; i < n; ++i){
        for(int j{0}; j < 5; ++j){
            cin >> board[i][j];
        }
    }
    int mn{MAX};
    vi ans;
    for(int i{1}; i < (1 << n); ++i){
        int sum{0};
        vi C(4);
        vi temp;
        for(int j{0}; j < n; ++j){
            if((i >> j) & 1){
                sum += board[j][4];
                for(int k{0}; k < 4; ++k){
                    C[k] += board[j][k];
                }
                temp.push_back(j);
            }            
        }
        bool ok = true;
        for(int j{0}; j < 4; ++j){
            ok &= (C[j] >= arr[j]);
        }
        if(ok){
            if(mn >= sum){
                if(mn == sum){
                    if(ans > temp) ans = temp;
                }
                else{
                    mn = sum;
                    ans = temp;
                }
            }
        }
    }
    if(mn == MAX){
        cout << -1; return 0;
    }
    cout << mn << "\n";
    for(auto& i : ans){
        cout << i + 1 << " ";
    }
}
