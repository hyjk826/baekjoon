// 2022-09-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n, m;
vi ch(8);

void dfs(int L, int k){
    if(L == m){
        for(int i{0}; i < m; ++i){
            cout << ch[i] + 1 << " ";
        }
        cout << "\n";
    }
    else{
        for(int i{k + 1}; i < n; ++i){
            ch[L] = i;
            dfs(L + 1, i);
        }
    }
}

int main(){
    fastio;
    cin >> n >> m;
    dfs(0, -1);
}