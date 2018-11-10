/*
http://codeforces.com/gym/100851/attachments

 Category: Ad Hoc / Arrays
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)

#define MAX 1000001
bool empty[2][MAX];
ll decrease[2];
ll countNonEmpty[2];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    ll n, q;
    cin >> n >> q;
    ll total = n * (n + 1) / 2;
    ll rc, index;
    char ch;
    countNonEmpty[0] = n;
    countNonEmpty[1] = n;
    FOR(i, 0, q) {
        cin >> ch >> index;
        if (ch == 'R') {
            rc = 0;
        } else {
            rc = 1;
        }
        if (empty[rc][index]) {
            cout << 0;
        } else {
//            cout << "index = " << index << endl;
//            cout << "jdex = " << jdex << endl;
//            cout << "decrease by " << decrease[index] << endl;
            cout << total - decrease[rc] + (ll) (index * countNonEmpty[rc]);
            empty[rc][index] = true;
            rc = (rc + 1) % 2;
            decrease[rc] += index;
            countNonEmpty[rc]--;
        }
        cout << endl;
    }

    return 0;
}
