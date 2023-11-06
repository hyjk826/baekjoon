// 2022-06-20
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

vi group[200001];

int main(){
    fastio;
	int n, m;
    cin >> n >> m;
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        for(int j{0}; j < a; ++j){
            int k;
            cin >> k;
            k--;
            group[i].push_back(k);
        }
    }
    vi ch(n);
    for(int i{0}; i < n; ++i){
        cin >> ch[i];
    }
    vi copy = ch;
    for(int i{m - 1}; i >= 0; --i){
        bool flag = false;
        for(auto& j : group[i]){
            flag |= (copy[j] == 0);
        }
        if(flag){
            for(auto& j : group[i]){
                copy[j] = 0;
            }
        }
    }
    vi ans = copy;
    for(int i{0}; i < m; ++i){
        bool flag = false;
        for(auto& j : group[i]){
            if(copy[j] == 1){
                flag = true;
                break;
            }
        }
        if(flag){
            for(auto& j : group[i]){
                copy[j] = 1;
            }
        }
    }
    for(int i{0}; i < n; ++i){
        if(copy[i] != ch[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(auto& i : ans) cout << i << " ";
}