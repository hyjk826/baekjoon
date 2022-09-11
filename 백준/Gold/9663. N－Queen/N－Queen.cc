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

int n;
vi ch1(40);
vi ch2(40);
vi ch3(40);
int ans{0};

void dfs(int L){
    if(L == n) ans++;
    else{
        for(int i{0}; i < n; ++i){
            if(ch1[i] || ch2[L + i] || ch3[L - i + n]) continue;
            ch1[i] = ch2[L + i] = ch3[L - i + n] = 1;
            dfs(L + 1);
            ch1[i] = ch2[L + i] = ch3[L - i + n] = 0;
        }
    }
}

int main(){
    fastio;
    cin >> n;
    dfs(0);
    cout << ans;
}