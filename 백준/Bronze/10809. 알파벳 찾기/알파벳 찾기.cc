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

int main(){
    fastio;
	string str;
    cin >> str;
    vi ch(26, -1);
    for(int i{0}; i < (int)str.size(); ++i){
        if(ch[str[i] - 'a'] != -1) continue;
        ch[str[i] - 'a'] = i;
    }
    for(auto& i : ch) cout << i << " ";
}