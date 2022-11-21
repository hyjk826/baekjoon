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

int main() {
	fastio;	
	bool flag = false;
    string str;
    cin >> str;
    int a{0}, b{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '('){
            flag = true;
            continue;
        }
        if(str[i] == '@'){
        if(!flag) a++;
            else b++;
        }
    }
    cout << a << " " << b;
}
	

