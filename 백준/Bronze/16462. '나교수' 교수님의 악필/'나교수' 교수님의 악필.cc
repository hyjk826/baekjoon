// 2022-06-03
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main(){
    fastio;
	int n;
    cin >> n;
    int sum{0};
    for(int i{0}; i < n; ++i){
        string str;
        cin >> str;
        for(auto& c : str){
            if(c == '0' || c == '6' || c == '9') c = '9';
        }
        if(str.size() >= 3) str = "100";
        sum += stoi(str);
    }
    int k = sum / n;
    if((k + 0.5) * n <= sum) cout << k + 1;
    else cout << k;
}