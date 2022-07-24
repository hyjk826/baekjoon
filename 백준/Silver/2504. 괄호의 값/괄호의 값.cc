// 2022-07-24
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
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
    vector<char> vec;
    int ans{0};
    int k{1};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '('){
            k *= 2;
            vec.push_back(str[i]);
        }
        else if(str[i] == ')'){
            if(vec.empty() || vec.back() != '('){
                ans = 0;
                break;
            }
            if(str[i - 1] == '(') ans += k;
            k /= 2;
            vec.pop_back();
        }
        else if(str[i] == '['){
            k *= 3;
            vec.push_back(str[i]);
        }
        else if(str[i] == ']'){
            if(vec.empty() || vec.back() != '['){
                ans = 0;
                break;
            }
            if(str[i - 1] == '[') ans += k;
            k /= 3;
            vec.pop_back();
        }
    }
    if(vec.size()) ans = 0;
    cout << ans;
}

