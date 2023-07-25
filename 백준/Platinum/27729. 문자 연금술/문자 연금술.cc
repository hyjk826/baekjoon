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

vs vec;

int score(string& s){
    int n = (int)s.size();
    int ret{0};
    for(int i{1}; i <= n - 1; ++i){
        for(int j{0}; j + i <= n - 1; ++j){
            if(s[j] == s[j + i]){
                ret += i; break;
            }
        }
    }
    return ret;
}

int f(int a, int b){
    string s = string(a, 'a') + string(b, 'b');
    vec.clear();
    int mx{0};
    do{
        int k = score(s);
        if(k > mx){
            vec.clear();
            mx = k;
            vec.push_back(s);
        }
        else if(k == mx){
            vec.push_back(s);
        }
    }while(next_permutation(s.begin(), s.end()));
    return mx;
}


void flip(string& s){
    for(auto& c : s) {
        if(c == 'a') c = 'b';
        else c = 'a';
    }
}

void solve(){
    int a, b;
    cin >> a >> b;
    bool ff = false;
    if(a < b) {
        ff = true; swap(a, b);
    }
	string ans;
    if(a > b + 1){
        ans = string(1, 'a') + string(b, 'b') + string(a - 1, 'a');
        if(ff) flip(ans);
        cout << (a + b) * (a + b - 1) / 2 << "\n";
        cout << ans << "\n";
    }
    else{
        if(a >= 4){
            if(a == b) ans = "aabbbaba";
            else ans = "aabbaba";
            for(int i{0}; i < a - 4; ++i) ans += "ba";
            if(ff) flip(ans);
            cout << (a + b) * (a + b - 1) / 2 << "\n";
            cout << ans << "\n";
        }
        else{
            cout << f(a, b) << "\n";
            string ans = vec.front();
            if(ff) flip(ans);
            cout << ans << "\n";
        }
    }
    
}

// aabbaba
// aabbbaba

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
