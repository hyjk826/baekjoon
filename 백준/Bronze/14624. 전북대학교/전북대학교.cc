// 2022-05-28
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
    if(n & 1){
        for(int i{0}; i < n; ++i) cout << '*';
        cout << "\n";
        for(int i{0}; i < n / 2; ++i) cout << " ";
        cout << "*\n";
        for(int i{0}; i < n / 2; ++i){
            for(int j{0}; j < n / 2 - i - 1; ++j) cout << " ";
            cout << "*";
            for(int j{0}; j < i * 2 + 1; ++j) cout << " ";
            cout << "*\n";
        }
    }
    else cout << "I LOVE CBNU";
}