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
    
    T = random.randint(1, N)
    
    # Clamp M and K to mathematically possible limits
    M = min(M, N * (N - 1) // 2)
    K = min(K, N)
    
    if TYPE == 6:
        # Anti-hacker graph:
        # We need a star-like graph with many long branches (traps).
        # T is the center (node 1).
        T = 1
        edges = set()
        num_branches = min(K, 150)
        nodes_per_branch = (N - 1) // max(1, num_branches)
        
        node_id = 2
        branch_ends = []
        for b in range(num_branches):
            prev = 1
            for _ in range(nodes_per_branch):
                if node_id > N: break
                edges.add((min(prev, node_id), max(prev, node_id)))
                prev = node_id
                node_id += 1
            branch_ends.append(prev)
            
        # Connect remaining nodes to center
        while node_id <= N:
            edges.add((1, node_id))
            node_id += 1
            
        weighted_edges = []
        for u, v in edges:
            weighted_edges.append((u, v, 10000))
            
        # We don't add more edges to keep the trap structure intact
    else:
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
            
        S = T
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
        elif TYPE == 6:
            # Place top 150 kiosks at branch ends with very high Y to attract hacker1
            if len(branch_ends) > 0:
                node = branch_ends.pop()
                y = 10000 * nodes_per_branch * 2 - 10000 # Exactly covers the branch but not the center
            else:
                # Other kiosks are near the center with small Y, but sufficient for their local area
                y = random.randint(10000, 30000)
        else:
            r = random.random()
            if r < 0.2:
                y = random.randint(1, 50)
            elif r < 0.5:
                y = random.randint(1, 2000)
            else:
                max_jumps = random.randint(1, 5)
                y = random.randint(1, max_jumps * 10000 * 2)
        chioschi.append((node, y))
        
    M = len(weighted_edges)
    
    # Print input
    print(f"{N} {M} {K} {T}")
    for u, v, t in weighted_edges:
        print(f"{u} {v} {t}")
    for node, y in chioschi:
        print(f"{node} {y}")

if __name__ == "__main__":
    generate()
