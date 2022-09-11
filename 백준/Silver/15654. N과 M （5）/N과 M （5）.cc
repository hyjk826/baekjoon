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
vi vec;
vi ch(8);

void dfs(int L, vi& r){
    if(L == m){
        for(auto& i : r){
            cout << i << " ";
        }
        cout << "\n";
    }
    else{
        for(int i{0}; i < n; ++i){
            if(ch[i] == 0){
                ch[i] = 1;
                r.push_back(vec[i]);
                dfs(L + 1, r);
                r.pop_back();
                ch[i] = 0;
            }
        }
    }
}
int main(){
    fastio;
    cin >> n >> m;
    vec.resize(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    vi r;
    dfs(0, r);
}