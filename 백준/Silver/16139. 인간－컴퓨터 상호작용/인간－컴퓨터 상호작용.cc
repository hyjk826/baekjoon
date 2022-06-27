// 2022-06-28
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
    string s;
    cin >> s;
    vector<vi> vec(s.size(), vi(26));
    for(int i{0}; i < (int)s.size(); ++i){
        vec[i][s[i] - 'a']++;
        if(i){
            for(int j{0}; j < 26; ++j){
                vec[i][j] += vec[i - 1][j];
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        if(a == 0) cout << vec[b][c - 'a'];
        else cout << vec[b][c - 'a'] - vec[a - 1][c - 'a'];
        cout << "\n";
    }
}
