#include <stdio.h>

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int left, right;
        scanf("%d %d", &left, &right);
        int result = left - right;
        if (result > 0) {
            puts(">");
        } else if (result < 0) {
            puts("<");
        } else {
            puts("=");
        }
    }
    return 0;
}
