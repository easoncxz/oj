
import sys

def step(n):
    if n % 2 == 0:
        return n // 2
    else:
        return 3 * n + 1

threshold = 2 ** 31

if len(sys.argv) > 1:
    n = int(sys.argv[1])
else:
    n = 113383
count = 1

while n > 1:
    #if n < threshold:
    #    print(n)
    #else:
    #    print(n, "Warning!")
    n = step(n)
    count += 1

print("Count:", count)
