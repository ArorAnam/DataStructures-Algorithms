
def solve(strings, n):
    skip = 0

    for i in range(len(strings) - 1):
        skip += abs(strings[i] - strings[i+1]) - 1

    return skip

result = []



t = list(map(int, input().split()))
while(t):
    n = int(input())

    strings = [int(x) for x in input().split()]

    result.append(solve(strings, n))

    t -= 1

for s in result:
    print(s)