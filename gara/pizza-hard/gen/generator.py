#!/usr/bin/env python3
import sys
import random

def generate():
    # Args: N M K TYPE SEED
    args = sys.argv[1:]
    if len(args) < 5:
        print("Usage: generator.py N M K TYPE SEED", file=sys.stderr)
        sys.exit(1)
        
    N, M, K, TYPE, SEED = map(int, args)
    random.seed(SEED)
    
    # Clamp M and K to mathematically possible limits
    M = min(M, N * (N - 1) // 2)
    K = min(K, N)
    
    # Generate tree to guarantee connectivity
    edges = set()
    for i in range(2, N + 1):
        p = random.randint(1, i - 1)
        edges.add((p, i))
        
    # Add remaining edges
    while len(edges) < M:
        u = random.randint(1, N)
        v = random.randint(1, N)
        if u != v:
            edge = (min(u, v), max(u, v))
            edges.add(edge)
            
    # Convert edges to list and shuffle
    edge_list = list(edges)
    random.shuffle(edge_list)
    
    weighted_edges = []
    for u, v in edge_list:
        if TYPE == 4:
            t = 1
        else:
            t = random.randint(1, 10000)
        weighted_edges.append((u, v, t))
        
    # Generate K chioschi
    # Smart test case: if SEED is odd, restrict satisfaction values to be small
    # relative to edge weights so that detours are heavily penalized and many nodes get 0.
    small_satisfaction = (SEED % 2 == 1)
    
    if small_satisfaction:
        # BFS from N to find nodes sorted by distance from N
        adj = {i: [] for i in range(1, N + 1)}
        for u, v, t in weighted_edges:
            adj[u].append(v)
            adj[v].append(u)
            
        S = N
        visited = {S}
        queue = [S]
        head = 0
        while head < len(queue):
            u = queue[head]
            head += 1
            for v in adj[u]:
                if v not in visited:
                    visited.add(v)
                    queue.append(v)
        # queue is sorted from closest to N to furthest from N
        # We want the furthest nodes from N to be kiosks
        reversed_queue = queue[::-1]
        chiosco_nodes = reversed_queue[:K]
        random.shuffle(chiosco_nodes)
    else:
        chiosco_nodes = random.sample(range(1, N + 1), K)
        
    chioschi = []
    for node in chiosco_nodes:
        if TYPE == 1:
            y = random.randint(1, 100)
        elif small_satisfaction:
            if TYPE == 4:
                y = random.randint(1, 5)
            else:
                y = random.randint(1, 15000)
        else:
            r = random.random()
            if r < 0.2:
                y = random.randint(1, 50)
            elif r < 0.5:
                y = random.randint(1, 2000)
            else:
                y = random.randint(1, 10**9)
        chioschi.append((node, y))
        
    # Print input
    print(f"{N} {M} {K}")
    for u, v, t in weighted_edges:
        print(f"{u} {v} {t}")
    for node, y in chioschi:
        print(f"{node} {y}")

if __name__ == "__main__":
    generate()
