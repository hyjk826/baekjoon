// 2022-12-08
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

int main() {
	fastio;
    string str;
    cin >> str;
    int idx{-1};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == 'x'){
            idx = i;
        }
    }
    if(idx == -1) cout << 0;
    else{
        if(idx == 0) cout << 1;
        else if(idx == 1 && str[0] == '-') cout << -1;
        else{
            cout << stoi(str.substr(0, idx));
        }
    }
}   
	
