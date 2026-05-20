#!/usr/bin/env python3
import sys
import random

def generate():
    # Args: N K TYPE SEED
    args = sys.argv[1:]
    if len(args) < 4:
        print("Usage: generator.py N K TYPE SEED", file=sys.stderr)
        sys.exit(1)
        
    N, K, TYPE, SEED = map(int, args)
    random.seed(SEED)
    
    K = min(K, N)
    
    # Generate N-1 road weights
    road_weights = []
    for _ in range(N - 1):
        if TYPE == 4:
            t = 1
        else:
            t = random.randint(1, 10000)
        road_weights.append(t)
        
    P = [0] * (N + 1)
    for i in range(1, N):
        P[i + 1] = P[i] + road_weights[i - 1]
        
    # Generate K chioschi
    chioschi = []
    
    # Smart test case design:
    # If restrict_locations is True, we place all K chioschi in the first half of the line
    # with small satisfaction values. This ensures that:
    # 1. For all participants in the second half, they must walk backward and cannot reach the chioschi.
    #    This forces the correct answer to be 0, catching "print 1" solutions.
    # 2. For all these participants, slow.cpp will scan all K chioschi and never find a valid one,
    #    forcing it to execute O(N * K) steps and TLE.
    restrict_locations = (TYPE == 6) or (TYPE in [2, 3, 4, 5] and SEED % 2 == 1)
    
    if restrict_locations:
        max_loc = min(K, N // 2)
        if max_loc < 1:
            max_loc = 1
        chiosco_locations = []
        for _ in range(K):
            chiosco_locations.append(random.randint(1, max_loc))
        
        for loc in chiosco_locations:
            y = random.randint(1, 1000)
            chioschi.append((loc, y))
    else:
        # Standard random placement
        chiosco_locations = random.sample(range(1, N + 1), K)
            
        for loc in chiosco_locations:
            if TYPE == 1:
                y = random.randint(1, 100)
            else:
                r = random.random()
                if r < 0.2:
                    y = random.randint(1, 50)
                else:
                    # Allow walking back a limited number of nodes on average
                    max_nodes_back = random.randint(1, max(1, N // 5))
                    y = random.randint(1, max_nodes_back * 10000 * 2)
            chioschi.append((loc, y))
            
    if restrict_locations and N > 1:
        T = random.randint(N // 2 + 1, N)
    else:
        T = random.randint(1, N)
            
    # Print input
    print(f"{N} {K} {T}")
    for t in road_weights:
        print(t)
    for loc, y in chioschi:
        print(f"{loc} {y}")

if __name__ == "__main__":
    generate()
