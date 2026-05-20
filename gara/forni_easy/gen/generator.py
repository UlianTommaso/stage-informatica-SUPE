#!/usr/bin/env python3
import sys
import random

if __name__ == "__main__":
    # Args: MINN MAXN MINQ MAXQ TYPE SEED
    args = sys.argv[1:]
    if len(args) < 6:
        MINN, MAXN, MINQ, MAXQ, TYPE, SEED = 1, 10, 1, 10, 3, 42
    else:
        MINN, MAXN, MINQ, MAXQ, TYPE, SEED = map(int, args)

    random.seed(SEED)

    if MINN > MAXN: MINN, MAXN = MAXN, MINN
    if MINQ > MAXQ: MINQ, MAXQ = MAXQ, MINQ

    n = random.randint(MINN, MAXN)
    q = random.randint(MINQ, MAXQ)

    # Determine maximum temperature value based on subtask type
    if TYPE == 2:
        max_val = 1_000_000
    else:
        max_val = 1_000_000_000

    # Generate initial temperatures
    t = [random.randint(1, max_val) for _ in range(n)]

    print(f"{n} {q}")
    print(" ".join(map(str, t)))

    # Generate Q queries
    for _ in range(q):
        # We can alternate or randomly choose between update '!' and query '?'
        # Let's say 40% updates, 60% queries
        op = '!' if random.random() < 0.4 else '?'
        if op == '!':
            k = random.randint(1, n)
            x = random.randint(1, max_val)
            print(f"! {k} {x}")
            t[k - 1] = x
        else:
            # For query '?', sometimes we query an existing temperature from our list,
            # sometimes a completely random temperature to test the '0' cases.
            if random.random() < 0.8:
                # Query an existing temperature to ensure we get non-zero answers
                x = random.choice(t)
            else:
                x = random.randint(1, max_val)
            print(f"? {x}")
