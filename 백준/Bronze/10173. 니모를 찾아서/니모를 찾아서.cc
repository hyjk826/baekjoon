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
    string str;
    while(getline(cin, str)){
        if(str == "EOI") break;
        for(auto& c : str) c = tolower(c);
        bool ok = false;
        if(str.find("nemo") != string::npos) ok = true;
        if(ok) cout << "Found\n";
        else cout << "Missing\n";
    }
}
