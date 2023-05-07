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

int main(){
	fastio;
	int n;
    cin >> n;
    string str;
    cin >> str;
    string temp = str;
    while(!temp.empty() && temp.back() == 'R') temp.pop_back();
    int ans{MAX};
    ans = min(ans, (int)count(temp.begin(), temp.end(), 'R'));
    temp = str;
    while(!temp.empty() && temp.back() == 'B') temp.pop_back();
    ans = min(ans, (int)count(temp.begin(), temp.end(), 'B'));
    cout << ans;
}
