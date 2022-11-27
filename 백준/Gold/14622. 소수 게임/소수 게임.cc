// 2022-11-26
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

vi prime((int)5e6 + 1);
vi ch((int)5e6 + 1);

int main() {
    prime[1] = 1;
    prime[0] = 1;
    for(ll i{2}; i <= (int)5e6; ++i){
        if(prime[i]) continue;
        for(ll j{i * i}; j <= (int)5e6; j += i){
            prime[j] = 1;
        }
    }
	fastio;
    int n;
    cin >> n;
    ll A, B;
    A = B = 0;
    priority_queue<ll, vector<ll>, greater<ll> > AQ, BQ;
    for(int i{0}; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        if(prime[a]){
            if(BQ.size() < 3) B += 1000;
            else B += BQ.top();
        } 
        else{
            if(ch[a]) A -= 1000;
            else if(AQ.size() < 3) AQ.push(a);
            else{
                if(AQ.top() < a){
                    AQ.pop();
                    AQ.push(a);
                }
            }
            ch[a] = 1;
        }
        if(prime[b]){
            if(AQ.size() < 3) A += 1000;
            else A += AQ.top();
        } 
        else{
            if(ch[b]) B -= 1000;
            else if(BQ.size() < 3) BQ.push(b);
            else{
                if(BQ.top() < b){
                    BQ.pop();
                    BQ.push(b);
                }
            }
            ch[b] = 1;
        }
    }    
    if(A > B) cout << "소수의 신 갓대웅";
    else if(A < B) cout << "소수 마스터 갓규성";
    else cout << "우열을 가릴 수 없음";
}
	
