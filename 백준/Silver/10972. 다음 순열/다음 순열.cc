// 2022-07-16
#include <bits/stdc++.h>
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define vi vector<int>
#define vl vector<long long>
#define vc vector<char>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vp vector<pi>
#define ll long long
#define MAX 2147000000
#define MOD 1000000007
using namespace std;

int main() {
	fastio;
    int n;
    cin >> n;
    vi vec(n);
    for(int i{0}; i < n; ++i) cin >> vec[i];
    int index{-1};
    for(int i{n - 2}; i >= 0; --i){
        if(vec[i] < vec[i + 1]){
            index = i;
            break;
        }
    }
    if(index == -1) cout << -1;
    else{
        vi ch(n + 1);
        for(int i{0}; i < index; ++i){
            ch[vec[i]]++;
            cout << vec[i] << " ";
        }
        int k = vec[index] + 1;
        while(1){
            if(ch[k] == 0){
                ch[k] = 1;
                cout << k << " ";
                break;
            }
            k++;
        }
        for(int i{1}; i <= n; ++i){
            if(ch[i] == 0) cout << i << " ";
        }
    }
}
