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

int main(){
	fastio;
    string str;
    cin >> str;
    vi vec((int)str.size());
    int mn{MAX};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '(') vec[i] = 1;
        else vec[i] = -1;
        if(i) vec[i] += vec[i - 1];
        mn = min(mn, vec[i]);
    }
    if(mn < -2){
        cout << 0 << "\n"; return 0;
    }
    if(vec.back() == 2){
        vi B = vec;
        for(int i{(int)str.size() - 2}; i >= 0; --i){
            B[i] = min(B[i], B[i + 1]);
        }
        int ans{0};
        for(int i{0}; i < (int)str.size(); ++i){            
            if(str[i] == '('){                
                if(B[i] >= 2) ans++;
            }
        }
        cout << ans;
    }
    else if(vec.back() == -2){
        int ans{0};
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == ')') ans++;
            if(vec[i] < 0) break;
        }
        cout << ans;
    }
    else cout << 0 << "\n";
}
