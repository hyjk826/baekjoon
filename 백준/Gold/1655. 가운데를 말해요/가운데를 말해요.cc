#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
#include <unordered_set>
#include <map>
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define MAX 2147000000
#define MOD 998244353
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    for (int i{ 0 }; i < n; ++i) {
        int a;
        cin >> a;
        if (max_heap.size() == min_heap.size()) {
            max_heap.push(a);
        }
        else {
            min_heap.push(a);
        }
        if (!max_heap.empty() && !min_heap.empty()) {
            if (max_heap.top() > min_heap.top()) {
                int a = max_heap.top();
                int b = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(b);
                min_heap.push(a);
            }
        }
        cout << max_heap.top() << "\n";
    }
}