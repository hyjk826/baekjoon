// 2022-07-28
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vector<char> vec;
    for(int i{0}; i < n; ++i){
        while(k && !vec.empty() && vec.back() < str[i]){
            vec.pop_back();
            k--;
        }
        vec.push_back(str[i]);
    }
    for(int i{0}; i < (int)vec.size() - k; ++i){
        cout << vec[i];
    }
}

