// 2022-07-25
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

int n;

void f(string str){
    for(int i{1}; i <= (int)str.size() / 2; ++i){
        if(str.substr((int)str.size() - 2 * i, i) == str.substr((int)str.size() - i)) return;
    }
    if(str.size() == n){
        cout << str;
        exit(0);
    }
    else{
        f(str + "1");
        f(str + "2");
        f(str + "3");
    }
}

int main() {
	fastio;
    cin >> n;
    f("");    
}

