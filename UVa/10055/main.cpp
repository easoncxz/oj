#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    long int left, right;
    while (cin >> left >> right)
        //cout << (right > left ? right - left : left - right) << endl;
        cout << labs(left - right) << endl;
    return 0;
}
