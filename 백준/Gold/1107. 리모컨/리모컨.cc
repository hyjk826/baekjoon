// 2022-09-11
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
    int n, m;
    cin >> n >> m;
    vi ch(10);
    for(int i{0}; i < m; ++i){
        int a;
        cin >> a;
        ch[a]++;
    }
    int mn = abs(100 - n);
    for(int i{0}; i <= 1000000; ++i){
        string str = to_string(i);
        bool flag = true;
        for(int j{0}; j < (int)str.size(); ++j){
            if(ch[str[j] - '0']){
                flag = false;
                break;
            }
        }
        if(flag){
            mn = min(mn, (int)str.size() + abs(i - n));
        }
    }
    cout << mn;
}