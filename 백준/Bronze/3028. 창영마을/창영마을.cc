// 2022-08-23
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
    vi ch(3);
    ch[0] = 1;
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == 'A') swap(ch[0], ch[1]);
        else if(str[i] == 'B') swap(ch[1], ch[2]);
        else swap(ch[0], ch[2]);
    }
    cout << find(ch.begin(), ch.end(), 1) - ch.begin() + 1;
}

