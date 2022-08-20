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
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

bool f(string str){
    for(int i{0}; i < (int)str.size() / 2; ++i){
        if(str[i] != str[(int)str.size() - 1 - i]) return false;
    }
    return true;
}

int main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = false;
        for(int i{2}; i <= 64; ++i){
            string s;
            int a = n;
            while(a){
                s += char('0' + a % i);
                a /= i;
            }
            if(f(s)){
                flag = true;
                break;
            }
        }
        if(flag) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}