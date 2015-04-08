#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

typedef map<long, long> cache_type;

cache_type cache;

long find_next(const long n) {
    if (n % 2 == 0) {
        return n >> 1;
    } else {
        return 3 * n + 1;
    }
}

long find_terminate_length(const long n) {
#ifdef DEBUG
    cout << "find_terminate_length(" << n << ")" << endl;
#endif
    try {
        if (n <= 1) {
            return 1;
        } else {
            cache_type::iterator hit = cache.find(n);
            if (hit != cache.end()) {
                return hit->second;

            } else {
                stack<long> path;
                long current = n;
                path.push(current);
                while (current > 1) {
                    current = find_next(current);
                    path.push(current);
#ifdef DEBUG
                    cout << "Just pushed: " << current << " onto the path stack." << endl;
#endif
                }
                long cycle_length = 1;
                try {
                    while (!path.empty()) {
                        // `path.top()`'s cycle length is `cycle_length`
#ifdef DEBUG
                        cout << "cache[" << path.top() << "] = " << cycle_length << endl;
#endif
                        cache[path.top()] = cycle_length;
                        path.pop();
                        cycle_length++;
                    }
                } catch (out_of_range o) {
                    cout << "out_of_range!! -- " << o.what() << endl;
                    throw;
                }
                return cache.at(n);
            }
        }
    } catch (out_of_range o) {
        cout << "out_of_range outside!! -- " << o.what() << endl;
        throw;
    }
}

int main() {
    //cout << "Initially, the cache vector is: " << endl;
    //for (int i = 0; i < 40; i++)
    //    cout << "cache[" << max_range - i << "] = " << cache[max_range - i] << endl;

    long i, j;
    while (cin >> i >> j) {
        long start = i, end = j;
        if (start > end)
            swap(start, end);
        long max = 0;
        for (long n = start; n <= end; n++) {
            long curr_term_len = find_terminate_length(n);
            if (curr_term_len > max)
                max = curr_term_len;
        }
        cout << i << " " << j << " " << max << endl;
    }
    return 0;
}

