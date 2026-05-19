#!/usr/bin/env python3
import sys

def valida(file_in, subtask_id):
    lines = [line.strip() for line in file_in.readlines()]
    lines = [line for line in lines if line]
    
    assert len(lines) >= 1, "Input file is empty"
    
    parts = lines[0].split()
    assert len(parts) == 3, f"First line must contain 3 integers (N K T), got {len(parts)}"
    N, K, T = map(int, parts)
    
    # Check general constraints
    assert 2 <= N <= 100000, f"N out of bounds: {N}"
    assert 1 <= K <= N, f"K out of bounds: {K}"
    assert 1 <= T <= N, f"T out of bounds: {T}"
    
    # Subtask constraints checking
    # 1: samples
    # 2: sub1 (N <= 10, K <= 10)
    # 3: sub2 (N <= 1000, K <= 1000)
    # 4: sub3 (K = 1)
    # 5: sub4 (t_i = 1)
    # 6: sub5 (Full)
    
    if subtask_id == 2:
        assert N <= 10, f"Subtask 1: N <= 10, got {N}"
        assert K <= 10, f"Subtask 1: K <= 10, got {K}"
    elif subtask_id == 3:
        assert N <= 1000, f"Subtask 2: N <= 1000, got {N}"
        assert K <= 1000, f"Subtask 2: K <= 1000, got {K}"
    elif subtask_id == 4:
        assert K == 1, f"Subtask 3: K == 1, got {K}"
        
    expected_lines = 1 + (N - 1) + K
    assert len(lines) == expected_lines, f"Expected {expected_lines} lines, got {len(lines)}"
    
    # Check N-1 road weights
    for i in range(N - 1):
        line_str = lines[1 + i]
        assert line_str.isdigit(), f"Road weight must be an integer, got {line_str}"
        t = int(line_str)
        assert 1 <= t <= 10000, f"Road weight out of bounds: {t}"
        if subtask_id == 5:
            assert t == 1, f"Subtask 4: all weights must be 1, got {t}"
            
    # Check K chioschi
    for i in range(K):
        parts = lines[1 + (N - 1) + i].split()
        assert len(parts) == 2, f"Chiosco {i} must have 2 values, got {len(parts)}"
        u, y = map(int, parts)
        assert 1 <= u <= N, f"Chiosco node out of bounds: {u}"
        assert 1 <= y <= 10**9, f"Chiosco satisfaction out of bounds: {y}"
        
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
