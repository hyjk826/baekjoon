// 2022-08-31
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
    string str;
    cin >> str;
    int n{0};
    for(int i{0}; i < (int)str.size(); ++i){
        if('A' <= str[i] && str[i] <= 'Z'){
            n += str[i] - 'A' + 27;
        }
        else{
            n += str[i] - 'a' + 1;
        }
    }
    for(int i{2}; i * i <= n; ++i){
        if(n % i == 0){
            cout << "It is not a prime word.";
            return 0;
        }
    }
    cout << "It is a prime word.";
}

