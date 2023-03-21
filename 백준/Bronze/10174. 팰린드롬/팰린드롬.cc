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

bool f(string& str){
    for(int i{0}; i < (int)str.size() / 2; ++i){
        if(str[i] != str[(int)str.size() - 1 - i]) return false;
    }
    return true;
}

int main(){
	fastio;
    int t;
    cin >> t;
    string str;
    getline(cin, str);
    while(t--){
        getline(cin, str);
        for(auto& c : str){
            if(c >= 'A' && c <= 'Z') c = tolower(c);
        }
        if(f(str)) cout << "Yes\n";
        else cout << "No\n";
    }
}
