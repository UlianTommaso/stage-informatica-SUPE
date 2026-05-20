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

    suits = ['D', 'C', 'W', 'S', 'M']
    
    cards = []

    if TYPE == 2:
        # TYPE 2: Exactly 2 tastes (Adversarial Definitivo)
        # Escludiamo la 'M'. Scegliamo coppie che rompono l'ordine D < C < W < S
        adversarial_pairs = [
            ('C', 'D'), ('W', 'D'), ('W', 'C'), 
            ('S', 'D'), ('S', 'C'), ('S', 'W')
        ]
        
        # Scegliamo la coppia in base al SEED per variare nei 11 testcase
        pair = adversarial_pairs[SEED % len(adversarial_pairs)]
        
        half = n // 2
        # Array perfettamente ordinato secondo la coppia "sbagliata" (es. tutte S e poi tutte D)
        cards = [pair[0]] * half + [pair[1]] * (n - half)
        
        # Aggiungiamo un 1% di rumore per non renderlo troppo banale
        noise_count = int(n * 0.01)
        for _ in range(noise_count):
            idx1 = random.randint(0, n - 1)
            idx2 = random.randint(0, n - 1)
            cards[idx1], cards[idx2] = cards[idx2], cards[idx1]
    elif TYPE == 3:
        # TYPE 3: M not present, N <= 2000
        chosen_suits = ['D', 'C', 'W', 'S']
        for _ in range(n):
            cards.append(random.choice(chosen_suits))
            
    elif TYPE == 5:
        # TYPE 5: Optimal order is D, C, W, S, M
        target_order = ['D', 'C', 'W', 'S', 'M']
        
        # Creiamo uno "scheletro" che compone circa l'85% dell'array.
        # Questo garantisce che l'ordinamento D C W S M sia matematicamente il più conveniente.
        base_count = int(n * 0.85)
        noise_count = n - base_count
        
        # Generiamo i bigliettini base e li ordiniamo secondo il target
        backbone = [random.choice(target_order) for _ in range(base_count)]
        order_map = {suit: i for i, suit in enumerate(target_order)}
        backbone.sort(key=lambda x: order_map[x])
        
        cards = backbone
        
        # Inseriamo i rimanenti bigliettini ("rumore") in posizioni totalmente casuali
        for _ in range(noise_count):
            noise_char = random.choice(target_order)
            insert_pos = random.randint(0, len(cards))
            cards.insert(insert_pos, noise_char)
            
    else:
        # TYPE 1, 4 e altri (Full random)
        for _ in range(n):
            cards.append(random.choice(suits))
                
    print(n)
    print(*(cards))