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
    string str;
    cin >> str;
    bool ok = (str.find('*') != string::npos);
    if(ok){
        int cnt{0};
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == '*') break;
            else if(str[i] == '(' || str[i] == '?') cnt++;
            else cnt--;
            if(cnt < 0){
                cout << "NO\n"; return;
            }
        }
        cnt = 0;
        for(int i{(int)str.size() - 1}; i >= 0; --i){
            if(str[i] == '*') break;
            if(str[i]== '(') cnt--;
            else cnt++;
            if(cnt < 0){
                cout << "NO\n"; return;
            }
        }
        cout << "YES\n";
    }
    else{
        if((int)str.size() & 1) cout << "NO\n";
        else{
            int a{0};
            int b{0};
            for(int i{0}; i < (int)str.size(); ++i){
                if(str[i] == '(') a++;
                else if(str[i] == ')') b++;
            }
            int n = (int)str.size();
            if(a > n / 2 || b > n / 2) cout << "NO\n";
            else{
                a = n / 2 - a;
                b = n / 2 - b;
                int cnt{0};
                for(int i{0}; i < n; ++i){
                    if(str[i] == '?'){
                        if(a){
                            a--; cnt++;
                        }
                        else{
                            cnt--;
                        }
                    }
                    else if(str[i] == '(') cnt++;
                    else cnt--;
                    if(cnt < 0){
                        cout << "NO\n"; return;
                    }
                }
                if(cnt == 0){
                    cout << "YES\n";
                }
                else cout << "NO\n";
            }
        }
    }
}

int main(){
	fastio;
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
