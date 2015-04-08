#include "100.cpp"
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2)
        return 42;
    int n = atoi(argv[1]);
    if (!n)
        return 13;
    else
        cout << find_terminate_length(n) << endl;
    return 0;
}
