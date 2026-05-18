#!/usr/bin/env python3

import sys
import random

if __name__ == "__main__":
    # Args: MINN MAXN TYPE SEED
    args = sys.argv[1:]
    if len(args) < 4:
        MINN, MAXN, TYPE, SEED = 1, 10, 0, 42
    else:
        MINN, MAXN, TYPE, SEED = map(int, args)

    random.seed(SEED)

    if MINN > MAXN: MINN, MAXN = MAXN, MINN
    n = random.randint(MINN, MAXN)

    suits = ['W', 'S', 'U', 'P', 'E']
    
    # Deck construction logic?
    # Problem: "There are N cards of each suit... numbered 1 to N. Deck 5N cards. Player gets N cards."
    # So valid values are 1..N.
    # Player gets N cards sampled from the 5N deck? No, "deck is randomly distributed... each player gets N cards".
    # This implies the player gets a random subset of size N from the Full Deck (S1..SN, W1..WN, etc.).
    # Or implies N is the parameter of the problem input.
    # Let's assume input N is the N in problem.
    # We select N cards from the pool of 5*N cards.
    
    # Pool: (Suit, Val) for Suit in SWERC, Val in 1..N.
    pool = []
    # However we need to respect TYPE constraints.
    
    # If TYPE=1 (Values=1): pool only has Val=1 cards?
    # "Per ogni lettera c’è un singolo numero".
    # Does this mean the player holds only V=1 cards? 
    # Or player holds distinct values but only one per suit?
    # "Per ogni lettera c’è un singolo numero" -> "For each letter there is a single number".
    # This likely means the player's hand has at most 1 card of each suit?
    # Or all cards in hand have value 1?
    # Given Subtask 1 label "Values=1" in my plan? Actually user said "Per ogni lettera c’è un singolo numero".
    # This means count(Suit) <= 1 for all suits?
    # But N can be up to 100000. If N > 5, this is impossible (Pigeonhole).
    # Ah, maybe "Values for each letter are limited"?
    # "Per ogni lettera ci sono al massimo due numeri".
    # Maybe it means "The deck only has values 1..1"? No, N=100000 suggests values go up to N.
    
    # Interpretation 2: The player's hand happens to have few cards per suit?
    # But N is input. If N=100, player has 100 cards.
    # If "Per ogni lettera c'è un singolo numero", it must mean "There is only 1 number available (e.g. 1) for that suit in the whole deck?"
    # No, "numbered 1 to N".
    
    # Let's look at the subtask descriptions more closely.
    # "10 - Per ogni lettera c’è un singolo numero"
    # "20 - Per ogni lettera ci sono al massimo due numeri"
    # This probably refers to the counts in the hand?
    # If so, max N is 5 (for count=1) or 10 (for count=2).
    # But the points are small (10, 20).
    # If "Per ogni lettera c'è un singolo numero" meant "All cards have value 1", then N can be larger.
    # E.g. S1, W1, E1, R1, C1. (N=5).
    # Wait, if N=100000, and we have many S1... impossible. Unique cards.
    # The only interpretation that allows N up to 100000 is that "Per ogni lettera c'è un singolo numero" is NOT about the hand content.
    # Wait. Maybe N in input is NOT the N of the deck?
    # "First line contains the number N."
    # "deck comprises 5N cards".
    # "each player gets N cards".
    # So input N is indeed the number of cards in hand.
    # And deck N is same.
    
    # Re-read Subtask 1: "Per ogni lettera c’è un singolo numero".
    # If this refers to the *values* available: "Only value 1 exists". Then Deck N must be 1. Input N must be <= 5.
    # If this refers to the *hand* content: "Hand contains at most 1 card of each suit". Then Input N <= 5.
    
    # Let's assume Subtask 1 has small N (<= 5).
    # Subtask 2 N <= 10.
    # Subtask 3 "Unica lettera è S, N <= 2000". -> Hand has only S cards.
    
    # So for generator:
    
    # TYPE 1: Single number per letter -> N <= 5. Hand has unique suits.
    # TYPE 2: Max 2 numbers per letter -> N <= 10. Hand has max 2 of each suit.
    # TYPE 3: Only W -> Hand has only W cards.
    # TYPE 4: Full.
    
    full_pool = []
    
    if TYPE == 3:
        # Only S
        # We need N distinct values for S.
        # Deck has values 1..N.
        # So we just take S1..SN?
        # Hand is random subset? Or all?
        # "player gets N cards".
        # If Deck N = Input N, player gets all S cards? 
        # "5 players... randomly distributed".
        # If Input N = 100. Deck has 500 cards (100 S, 100 W...).
        # Player gets 100 cards.
        # Can player get 100 S cards? Yes.
        # So we generate N distinct values for S.
        vals = random.sample(range(1, 200000), n) # N is input n. Values can be anything valid in deck (1..DeckN).
        # We assume DeckN >= InputN. Let's use DeckN = InputN * 5 or something large logic-wise.
        # Actually standard: DeckN = InputN (from problem description "N... 5N... gets N").
        # So values are 1..N.
        # If Only S, we take all S cards?
        # S1...SN.
        vals = list(range(1, n + 1))
        random.shuffle(vals)
        cards = [f"W{v}" for v in vals]
        
    elif TYPE == 1:
        # One per letter.
        # N <= 5.
        # Choose N distinct suits from SWERC.
        chosen_suits = random.sample(suits, n)
        # Values can be anything 1..N.
        cards = [f"{s}{random.randint(1, n)}" for s in chosen_suits]
        
    elif TYPE == 2:
        # Max 2 per letter.
        # N <= 10.
        # Distribute count.
        counts = {s: 0 for s in suits}
        cards = []
        for _ in range(n):
            # Pick a suit with count < 2
            avail = [s for s in suits if counts[s] < 2]
            if not avail: break # Should not happen if N<=10
            s = random.choice(avail)
            counts[s] += 1
            # Pick unique value ?
            # Let's track used (s, v).
            v = random.randint(1, n)
            while f"{s}{v}" in cards: v = random.randint(1, n+100) # Safe hack
            cards.append(f"{s}{v}")
        
        # Sort cards by suit: S < W < E < R < C
        # Suits are already defined in the desired order in `suits` list: ['S', 'W', 'E', 'R', 'C']
        # We can use the index in that list as the key.
        cards.sort(key=lambda c: suits.index(c[0]))
            
    else:
        # Full random
        # We need N cards. Valid values 1..N (since DeckN=N).
        # We simulate deck: (S,1)..(S,N), (W,1)..(W,N)...
        # Pool size 5N.
        # Sample N.
        
        # Optimization for large N:
        # Don't build full pool.
        # Just generate unique pairs (S, V).
        seen = set()
        cards = []
        while len(cards) < n:
            s = random.choice(suits)
            v = random.randint(1, n)
            if (s,v) not in seen:
                seen.add((s,v))
                cards.append(f"{s}{v}")
                
    print(n)
    print(*(cards))
