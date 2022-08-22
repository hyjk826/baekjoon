// 2022-08-21
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
    int n = (int)str.size();
    int a;
    for(int i{1}; i * i <= n; ++i){
        if(n % i == 0){
            a = i;
        }
    }
    for(int i{0}; i < a; ++i){
        for(int j{i}; j < n; j += a){
            cout << str[j];
        }
    }
}