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
    int L, k, c;
    cin >> L >> k >> c;
    vi vec(k);
    for(int i{0}; i < k; ++i){
        cin >> vec[i];
    }
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    int l{1}, r{L};
    int mn{L};
    while(l <= r){
        int mid{(l + r) >> 1};
        int a{0};
        int cnt{0};
        while(L - a > mid){
            int idx = upper_bound(vec.begin(), vec.end(), a + mid) - vec.begin();
            idx--;
            if(vec[idx] == a){
                cnt = MAX; break;
            }
            a = vec[idx]; cnt++;
        }
        if(cnt <= c){
            mn = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    vec.push_back(L);
    int first = L;
    for(int i{1}; i < (int)vec.size(); ++i){
        int cnt{1};
        int a{vec[i]};
        while(L - a > mn){
            int idx = upper_bound(vec.begin(), vec.end(), a + mn) - vec.begin();
            idx--;
            if(vec[idx] == a){
                cnt = MAX; break;
            }
            a = vec[idx]; cnt++;
        }
        if(cnt <= c){
            first = vec[i];
            break;
        }
    }
    cout << mn << " " << first;
}
