// 2022-09-09
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

bool f(string str){
    for(int i{0}; i < (int)str.size() / 2; ++i){
        if(str[i] != str[(int)str.size() - 1 - i]) return false;
    }
    return true;
}

int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        string c = str;
        reverse(c.begin(), c.end());
        int k = stoi(str) + stoi(c);
        if(f(to_string(k))) cout << "YES\n";
        else cout << "NO\n";
    }
}