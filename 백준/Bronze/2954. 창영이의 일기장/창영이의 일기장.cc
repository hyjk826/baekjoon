// 2022-08-31
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
    string a = "aeiou";
    while(cin >> str){
        for(int i{0}; i < (int)str.size(); ++i){
            cout << str[i];
            if(a.find(str[i]) != string::npos) i += 2;
        }
        cout << " ";
    }
}

