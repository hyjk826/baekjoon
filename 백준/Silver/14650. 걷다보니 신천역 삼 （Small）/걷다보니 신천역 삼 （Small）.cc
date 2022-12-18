// 2022-12-18
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


int n;
int ans{0};

void dfs(int L, int sum){
    if(L == n){
        if(sum % 3 == 0) ans++;
    }
    else{
        int k{0};
        if(L == 0) k = 1;
        for(int i{k}; i <= 2; ++i){
            dfs(L + 1, sum + i);
        }
    }
}

int main(){
	fastio;
	cin >> n;
    dfs(0, 0);
    cout << ans;
}
	
