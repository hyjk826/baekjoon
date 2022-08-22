// 2022-08-22
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
    int ans{1};
    string str;
    cin >> str;
    if(str[0] == 'c') ans *= 26;
    else ans *= 10;
    for(int i{1}; i < (int)str.size(); ++i){
        if(str[i] == str[i - 1]){
            if(str[i] == 'c') ans *= 25;
            else ans *= 9;
        }
        else{
            if(str[i] == 'c') ans *= 26;
            else ans *= 10;
        }
    }
    cout << ans;
}

