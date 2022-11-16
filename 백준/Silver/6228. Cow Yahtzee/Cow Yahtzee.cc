// 2022-11-16
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

int n, m, e;
vs vec(20);
int ans{0};
vi ch(20);
vector<vp> A;



void dfs(int L){
    if(L == n){
        bool flag = false;
        for(auto& i : A){
            bool flag2 = true;
            for(auto& j : i){
                flag2 &= (ch[j.second] >= j.first);
            }
            if(flag2) flag = true;
        }
        if(flag) ans++;
    }
    else{
        for(int i{1}; i <= m; ++i){
            ch[i]++;
            dfs(L + 1);
            ch[i]--;
        }
    }
}

int main() {
	fastio;
    cin >> n >> m >> e;
    for(int i{0}; i < e; ++i){
        cin >> vec[i];
        vec[i] += '+';
        vp B;
        for(int j{0}; j < (int)vec[i].size(); ++j){
            if(vec[i][j] == '+'){
                B.push_back({vec[i][j - 3] - '0', vec[i][j - 1] - '0'});
            }
        }
        A.push_back(B);
    }
    dfs(0);
    cout << ans;
}
	

