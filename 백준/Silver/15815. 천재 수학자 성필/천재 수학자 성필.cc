// 2022-11-21
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

ll f(ll a, ll b, char c){
    if(c == '*') return a * b;
    else if(c == '/') return a/ b;
    else if(c == '+') return a + b;
    else if(c == '-') return a - b;
}


int main() {
	fastio;	
	string str;
    cin >> str;
    vl A;
    for(int i{0}; i < (int)str.size(); ++i){
        if('0' <= str[i] && str[i] <= '9'){
            A.push_back(str[i] - '0');
        }
        else{
            ll a, b;
            b = A.back();
            A.pop_back();
            a = A.back();
            A.pop_back();
            A.push_back(f(a, b, str[i]));
        }
    }
    cout << A.back();
}
	

