// 2022-05-29
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
	string str;
    cin >> str;
    int sum{0};
    int k{-1};
    for(int i{0}; i < (int)str.size(); ++i){
        if(str[i] == '*'){
            k = i;
            continue;
        }
        if(i & 1) sum += (str[i] - '0') * 3;
        else sum += (str[i] - '0');
    }
    for(int i{0}; i <= 9; ++i){
        int a = sum;
        if(k & 1) a += i * 3;
        else a += i;
        if(a % 10 == 0){
            cout << i;
            return 0;
        }
    }
}