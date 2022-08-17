// 2022-08-16
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
        vi ch(26);
        string str;
        cin >> str;
        for(int i{0}; i <(int)str.size(); ++i){
            if('a' <= str[i] && str[i] <= 'z') ch[str[i] - 'a']++;
            else if('A' <= str[i] && str[i] <= 'Z') ch[str[i] - 'A']++;
        }
        bool flag = true;
        for(int i{0}; i < 13; ++i){
            flag &= (ch[i] == ch[25 - i]);
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
}

