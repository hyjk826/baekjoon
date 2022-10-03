// 2022-10-02
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

int main() {
	fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vi ch(n);
        int ans{0};
        for(int i{0}; i < n; ++i){
            if(t[i] == '*') ch[i] = 1;
        }
        for(int i{0}; i < n; ++i){
            if(ch[i]){
                ans++;
                for(int j{-1}; j <= 1; ++j){
                    int nx = i + j;
                    if(nx >= 0 && nx < n){
                        s[nx]--;
                    }
                }
            }
        }
        for(int i{0}; i < n; ++i){
            if(ch[i] == 0){
                bool flag = true;
                for(int j{-1}; j <= 1; ++j){
                    int nx = i + j;
                    if(nx >= 0 && nx < n){
                        flag &= (s[nx] > '0');
                    }
                }
                if(flag){
                    ans++;
                    for(int j{-1}; j <= 1; ++j){
                        int nx = i + j;
                        if(nx >= 0 && nx < n){
                            s[nx]--;
                        }
                    }   
                }
            }
        }
        cout << ans << "\n";
    }
}
	

