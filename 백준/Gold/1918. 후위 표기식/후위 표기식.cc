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

int main() {
    fastio;
    string str;
    cin >> str;
    vc vec;
    string ans;
    for (int i{ 0 }; i < (int)str.size(); ++i) {;
        if ('A' <= str[i] && str[i] <= 'Z') {
            ans += str[i];
            continue;
        }
        if (str[i] == '(') vec.push_back(str[i]);
        else if (str[i] == ')') {
            while (vec.back() != '(') {
                ans += vec.back();
                vec.pop_back();
            }
            vec.pop_back();
        }
        else {
            if (str[i] == '*' || str[i] == '/') {
                while (!vec.empty() && vec.back() != '(' && (vec.back() == '*' || vec.back() == '/')) {
                    ans += vec.back();
                    vec.pop_back();
                }
                vec.push_back(str[i]);
            }
            else {
                while (!vec.empty() && vec.back() != '(') {
                    ans += vec.back();
                    vec.pop_back();
                }
                vec.push_back(str[i]);
            }
        }
    }
    while (!vec.empty()) {
        ans += vec.back();
        vec.pop_back();
    }
    cout << ans;
}

