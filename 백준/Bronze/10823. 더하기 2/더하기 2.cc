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
    string str, s;
    while(getline(cin, s)){
        str += s;
    }
    str += ',';
    string t;
    int ans{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == ','){
            ans += stoi(t);
            t.clear();
        }
        else t += str[i];
    }
    cout << ans;
}