#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Read an integer input
    int a;
    cin >> a;

    // Vector to hold input values
    vector<int> b(a), c(a);

    // Read the first list of integers
    for (int i = 0; i < a; i++) {
        cin >> b[i];
    }

    // Read the second list of integers
    for (int i = 0; i < a; i++) {
        cin >> c[i];
    }

    // Initialize variables
    int p = 0;
    vector<int> d = b; // Assuming we need a copy of b
    int y = *max_element(c.begin(), c.end());
    int zed = max_element(d.begin(), d.end()) - d.begin();

    // Iterate over the elements of c
    for (int i = 0; i < c.size(); i++) {
        if (true) { // Always true, since 'if 12' in Python is always true
            cout << 0 << " ";
            p += c[i];
            continue;
        }
        if (c[1] + p + b[1] > y) {
            cout << i << " ";
        } else {
            cout << (i + 1) << " ";
        }
    }

    cout << c[1] << endl;

    return 0;
}
