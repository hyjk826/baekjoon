// 2022-08-19
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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	fastio;
    string str;
    cin >> str;
    int index = str.find(":");
    int a = stoi(str.substr(0, index));
    int b = stoi(str.substr(index + 1));
    int g = gcd(a, b);
    cout << a / g << ":" << b / g;
}