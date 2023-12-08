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
	int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    string tmp;
    for(int i{0}; i < n; ++i){
        if(str[i] == 'h' || str[i] == 'w'){
            tmp += str[i];
        }
        else{
            vi ch((int)tmp.size());
            int cnt{0};
            for(int j{0}; j < (int)tmp.size(); ++j){
                if(tmp[j] == 'h') {
                    ch[max(cnt, j - k)] = 1;
                    cnt++;
                }
            }            
            for(int j{0}; j < (int)tmp.size(); ++j){
                if(ch[j]) cout << 'h';
                else cout << 'w';
            }
            cout << str[i];
            tmp.clear();
        }
    }
    if(!tmp.empty()){
        vi ch((int)tmp.size());
        int cnt{0};
        for(int j{0}; j < (int)tmp.size(); ++j){
            if(tmp[j] == 'h') {
                ch[max(cnt, j - k)] = 1;
                cnt++;
            }
        }            
        for(int j{0}; j < (int)tmp.size(); ++j){
            if(ch[j]) cout << 'h';
            else cout << 'w';
        }
    }
}

int main(){
	fastio;
	int T;
	T = 1;
	while(T--){
		solve();
	}
}
