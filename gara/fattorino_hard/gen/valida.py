#!/usr/bin/env python3
import sys

def valida(file_in, subtask_id):
    lines = [line.strip() for line in file_in.readlines()]
    lines = [line for line in lines if line]
    
    assert len(lines) >= 1, "Input file is empty"
    
    parts = lines[0].split()
    assert len(parts) == 4, f"First line must contain 4 integers (N M K T), got {len(parts)}"
    N, M, K, T = map(int, parts)
    
    # Check general constraints first
    assert 2 <= N <= 50000, f"N out of bounds: {N}"
    assert 1 <= M <= 100000, f"M out of bounds: {M}"
    assert 1 <= K <= N, f"K out of bounds: {K}"
    assert 0 <= T < N, f"T out of bounds: {T}"
    
    # Subtask constraints checking (subtask_id is 1-based index including samples)
    # 1: samples
    # 2: sub1 (N <= 10, M <= 20, K <= 10)
    # 3: sub2 (N <= 1000, M <= 2000, K <= 1000)
    # 4: sub3 (K = 1)
    # 5: sub4 (t_i = 1)
    # 6: sub5 (Full)
    
    if subtask_id == 2:
        assert N <= 10, f"Subtask 1: N <= 10, got {N}"
        assert M <= 20, f"Subtask 1: M <= 20, got {M}"
        assert K <= 10, f"Subtask 1: K <= 10, got {K}"
    elif subtask_id == 3:
        assert N <= 1000, f"Subtask 2: N <= 1000, got {N}"
        assert M <= 2000, f"Subtask 2: M <= 2000, got {M}"
        assert K <= 1000, f"Subtask 2: K <= 1000, got {K}"
    elif subtask_id == 4:
        assert K == 1, f"Subtask 3: K == 1, got {K}"
    
    assert len(lines) == 1 + M + K, f"Expected {1 + M + K} lines, got {len(lines)}"
    
    # Check edges
    adj = [[] for _ in range(N)]
    for i in range(M):
        parts = lines[1 + i].split()
        assert len(parts) == 3, f"Edge {i} must have 3 values, got {len(parts)}"
        u, v, t = map(int, parts)
        assert 0 <= u < N and 0 <= v < N, f"Edge nodes out of bounds: {u}, {v}"
        assert u != v, f"Self loop not allowed: {u}"
        assert 1 <= t <= 10000, f"Edge weight out of bounds: {t}"
        if subtask_id == 5:
            assert t == 1, f"Subtask 4: all weights must be 1, got {t}"
        adj[u].append(v)
        adj[v].append(u)
        
    # Check connectivity using BFS
    visited = [False] * N
    queue = [0]
    visited[0] = True
    head = 0
    while head < len(queue):
        u = queue[head]
        head += 1
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)
    assert len(queue) == N, f"Graph is not connected! Visited only {len(queue)} nodes out of {N}."
    
    # Check chioschi
    for i in range(K):
        parts = lines[1 + M + i].split()
        assert len(parts) == 2, f"Chiosco {i} must have 2 values, got {len(parts)}"
        u, y = map(int, parts)
        assert 0 <= u < N, f"Chiosco node out of bounds: {u}"
        assert 1 <= y <= 10**9, f"Chiosco yumminess out of bounds: {y}"
        
    return True

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: valida.py <input_file> <subtask_id>", file=sys.stderr)
        sys.exit(1)
    
    input_file = sys.argv[1]
    subtask_id = int(sys.argv[2])
    
    with open(input_file, 'r') as f:
        valida(f, subtask_id)
    sys.exit(0)
