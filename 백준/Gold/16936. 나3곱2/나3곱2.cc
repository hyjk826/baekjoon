// 2022-08-31
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
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int n;
vl vec(100);
vl ch;
map<ll, ll> mp;

void dfs(int L, ll k){
    if(L == n){
        for(auto& i : ch){
            cout << i << " ";
        }
        exit(0);
    }
    else{
        if(k == -1){
            for(int i{0}; i < n; ++i){
                mp[vec[i]]--;
                ch.push_back(vec[i]);
                dfs(L + 1, vec[i]);
                ch.pop_back();
                mp[vec[i]]++;
            }
        }
        else{
            if(k % 3 == 0){
                if(mp[k / 3]){
                    ch.push_back(k / 3);
                    dfs(L + 1, k / 3);
                    ch.pop_back();
                }
            }
            if(mp[k * 2]){
                ch.push_back(k * 2);
                dfs(L + 1, k * 2);
                ch.pop_back();
            }
        }
    }
}

int main() {
	fastio;
    cin >> n;
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
        mp[vec[i]]++;
    }
    dfs(0, -1);
}

