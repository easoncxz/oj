#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> cache;

long next_three_n(long n) {
    if (n % 2 == 0) {
        return n >> 1;
    } else {
        return 3 * n + 1;
    }
}

int find_terminate_length(int arg) {
    map<int, int>::iterator hit = cache.find(arg);
    if (hit != cache.end())
        return hit->second;
    long n = arg;
    int count = 1;
    while (n > 1) {
        n = next_three_n(n);
        count++;
    }
    cache[arg] = count;
    return count;
}

int main() {
    int i, j;
    while (cin >> i >> j) {
        int start = i, end = j;
        if (start > end)
            swap(start, end);
        int max = 0;
        for (int n = start; n <= end; n++) {
            int curr_term_len = find_terminate_length(n);
            if (curr_term_len > max)
                max = curr_term_len;
        }
        cout << i << " " << j << " " << max << endl;
    }
    return 0;
}
