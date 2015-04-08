#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    bool waiting_for_opening = true;
    char c;
    while (cin.get(c)) {
        if (c != '"')
            cout.put(c);
        else {
            cout << (waiting_for_opening ? "``" : "''");
            waiting_for_opening = !waiting_for_opening;
        }
    }
    return 0;
}
