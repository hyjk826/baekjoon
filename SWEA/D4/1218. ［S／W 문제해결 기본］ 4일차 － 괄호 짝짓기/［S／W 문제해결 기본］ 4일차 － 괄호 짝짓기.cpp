// 2022-09-24
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
	int T;
	T = 10;
	for(int t{1}; t <= T; ++t){
		cout << "#" << t << " ";
        int n;
        cin >> n;
        string str;
        cin >> str;
        vc vec;
        bool ok = true;
        for(int i{0}; i < n; ++i){
            if(str[i] == '[' || str[i] == '(' || str[i] == '{' || str[i] == '<') vec.push_back(str[i]);
            else{
                if(str[i] == ']'){
                    if(vec.empty() || vec.back() != '['){
                        ok = false;
                    }
                    else vec.pop_back();
                }
                else if(str[i] == ')'){
                    if(vec.empty() || vec.back() != '('){
                        ok = false;
                    }
                    else vec.pop_back();
                }
                else if(str[i] == '}'){
                    if(vec.empty() || vec.back() != '{'){
                        ok = false;
                    }
                    else vec.pop_back();
                }
                else if(str[i] == '>'){
                    if(vec.empty() || vec.back() != '<'){
                        ok = false;
                    }
                    else vec.pop_back();
                }
            }
        }
        if(ok && vec.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
	}
}
	