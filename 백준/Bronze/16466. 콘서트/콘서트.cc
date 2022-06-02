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

vi ch(1000001);

int main(){
    fastio;
    int n;
    cin >> n;
    for(int i{0}; i < n; ++i){
        int a;
        cin >> a;
        ch[a]++;
    }
    for(int i{1}; i <= 1000000; ++i){
        if(ch[i] == 0){
            cout << i;
            return 0;
        }
    }
}