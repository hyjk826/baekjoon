// 2022-09-16
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
    string str;
    cin >> str;
    vi vec((int)str.size());
    int a{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '(') a++;
        else a--;
        vec[i] = a;
    }
    int ans{0};
    if(a == 1){
        for(int i{(int)str.size() - 1}; i >= 0; --i){
            if(vec[i] == 0) break;
            if(str[i] == '(') ans++;
        }
    }
    else{
        for(int i{0}; i < (int)str.size(); ++i){
            if(str[i] == ')') ans++;
            if(vec[i] == -1) break;
        }
    }
    cout << ans;
}
	

