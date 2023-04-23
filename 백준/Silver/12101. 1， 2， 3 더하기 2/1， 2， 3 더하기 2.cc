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
    int n, k;
    cin >> n >> k;
    vector<vi> A;
    vi temp;
    function<void(int)> dfs = [&](int sum){
        if(sum > n) return;
        if(sum == n){
            A.push_back(temp);
        }
        else{
            for(int i{1}; i <= 3; ++i){
                temp.push_back(i);
                dfs(sum + i);
                temp.pop_back();
            }
        }
    };
    dfs(0);
    sort(A.begin(), A.end());
    if(k - 1 <= (int)A.size() - 1){
        for(int i{0}; i < (int)A[k - 1].size() - 1; ++i){
            cout << A[k - 1][i] << "+";
        }
        cout << A[k - 1].back();
    }
    else cout << -1;
}
