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

void solve(){
    int n, q;
    cin >> n >> q;
    vi vec(n);
    string str;
    for(char i{'a'}; i <= 'z'; ++i){
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') continue;
        str += i;
    }
    for(int i{0}; i < n; ++i){
        int a{0};
        string s;
        cin >> s;
        for(int j{0}; j < (int)s.size(); ++j){
            int idx = str.find(s[j]);
            if(idx == -1) continue;
            a |= (1 << idx);
        }
        vec[i] = a;
    }
    int a{(1 << 21) - 1};
    while(q--){
        int op;
        char c;
        cin >> op >> c;
        int idx = str.find(c);
        if(op == 1) a ^= (1 << idx);        
        else a |= (1 << idx);
        int cnt{0};
        for(int i{0}; i < n; ++i){
            if((a & vec[i]) == vec[i]) cnt++;
        }
        cout << cnt << "\n";
    }
}

int main(){
	fastio;
	int t;
	t = 1;
	while(t--){
		solve();
	}
}
