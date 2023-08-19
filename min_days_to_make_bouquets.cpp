#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool possible(vector<int>& v, int mid, int m, int k) {
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= mid)
            cnt++;
        else {
            ans += (cnt / k);
            cnt = 0;  
        }
    }
    ans += (cnt / k);
    return ans >= m;
}

int min_days(vector<int>& v, int n, int m, int k) {
    int low = *min_element(v.begin(), v.end());
    int high = *max_element(v.begin(), v.end());
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate mid to avoid overflow
        if (possible(v, mid, m, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k;
    cin >> k;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    cout << min_days(v, n, m, k);
    return 0;
}
