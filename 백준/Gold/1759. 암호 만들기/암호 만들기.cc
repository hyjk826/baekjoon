// 2022-09-06
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

int l, c;
vs ans;

void dfs(int L, int k, string str, vc& vec){
    if(L == l){
        int a{0}, b{0};
        string t = "aeiou";
        for(int i{0}; i < (int)str.size(); ++i){
            if(t.find(str[i]) != string::npos) a++;
            else b++;
        }
        if(a < 1 || b < 2) return;
        string c = str;
        sort(c.begin(), c.end());
        ans.push_back(c);
    }
    else{
        for(int i{k + 1}; i < c; ++i){            
            str += vec[i];
            dfs(L + 1, i, str, vec);
            str.pop_back();
        }
    }
}

int main() {
	fastio;
    cin >> l >> c;
    vc vec(c);
    for(int i{0}; i < c; ++i){
        cin >> vec[i];
    }    
    string s;
    dfs(0, -1, s, vec);
    sort(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << "\n";
}
	

