// 2022-07-05
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n, m;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i){
        cin >> vec[i];
    }
    set<int> s;
    s.insert(0);
    for(int i{0}; i < n; ++i){
        vi v;
        for(auto& j : s){
            if(j + vec[i] > 40000) continue;
            v.push_back(j + vec[i]);
        }
        for(auto& j : v){
            s.insert(j);
        }
    }
    cin >> m;
    while(m--){
        int k;
        cin >> k;
        if(s.count(k)) cout << "Y ";
        else{
            bool flag = false;
            for(auto& i : s){
                auto it = lower_bound(s.begin(), s.end(), i + k);
                if(it != s.end() && *it == i + k){
                    flag = true;
                    break;
                }
            }
            if(flag) cout << "Y ";
            else cout << "N ";
        }
    }
}