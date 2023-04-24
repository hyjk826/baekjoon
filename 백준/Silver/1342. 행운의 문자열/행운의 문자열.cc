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
    cin >> str;
    int ans{0};
    sort(str.begin(), str.end());
    do{
        bool ok = true;
        for(int i{0}; i < (int)str.size() - 1; ++i){
             ok &= (str[i] != str[i + 1]);
        }
        if(ok) ans++;
    }while(next_permutation(str.begin(), str.end()));
    cout << ans;
}
