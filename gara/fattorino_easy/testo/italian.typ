#import "template.typ": *
#import "@preview/subpar:0.1.1"

/* Setting the statement language for localization */
#set text(lang: "it")
#override_localization.update(_ => (:))

#set text(font: ("Libertinus Serif"))

#import "@preview/zero:0.2.0": num, set-group
#set-group(separator: "#h(0.133333em)")

/* Statement content block */
#statement[

È l'ora di pranzo allo stage per le Olimpiadi di Informatica e tutti gli studenti sono affamati! Tommaso aveva promesso di preparare la pizza per tutti, ma come al solito è troppo lento. Samuele, stufo di aspettare, decide di andare lui stesso in pizzeria a prendere le pizze.

Via Gemona è composta da $N$ luoghi in fila, numerati da $1$ a $N$. Samuele impiega $t_i$ minuti per camminare dal luogo $i$ al luogo $i+1$, e viceversa.

Samuele intanto si è perso in via Gemona e, dato che si è fatto tardi, decide di tornare al Toppo, in posizione $T$.

#figure(
  image("fattorino.png", width: 50%),
  caption: "Samuele che corre verso il Toppo."
)

In $K$ luoghi $C_1, dots, C_K$ di via Gemona ci sono dei chioschi che vendono tranci di pizza. Il chiosco in posizione $C_i$ vende un trancio di pizza con un livello di soddisfazione $S_i$ (misurato in "quanto vale la pena fermarsi").

Samuele è disposto a fermarsi al massimo in un chiosco lungo il suo percorso verso il Toppo, ma solo se il tempo extra aggiunto al suo percorso è al massimo uguale al livello di soddisfazione della pizza che prenderebbe. In altre parole, se fermarsi a prendere una pizza gli fa perdere $t$ minuti in più rispetto al percorso più veloce, lo farà solo se il livello di soddisfazione è almeno $t$.

Dato che non sappiamo dove si trova Samuele, determina per ogni possibile posizione iniziale se Samuele si fermerà a prendere la pizza oppure no.

#inputfile
La prima riga contiene gli interi $N$, $K$, $T$, rispettivamente il numero di luoghi, il numero di chioschi e la posizione del Toppo.

La $1+i$-esima riga $(1 <= i <= N-1)$ contiene un intero $t_i$, i minuti che ci mette Samuele per andare dal luogo $i$ al luogo $i+1$, e viceversa.

La $N+i$-esima riga $(1 <= i <= K)$ contiene gli interi $C_i$ e $S_i$, rispettivamente la posizione dell'$i$-esimo chiosco e il suo livello di soddisfazione.

#note[
Tra gli allegati a questo task troverai un template `fattorino_easy.*` con un esempio di implementazione.
]

#outputfile
Stampa $N$ righe. All'$i$-esima riga stampa $1$ se Samuele, partendo dalla posizione $i$, si fermerà a prendere la pizza. Stampa $0$ altrimenti.

#constraints

- $2 <= N <= 100 000$.
- $1 <= K <= N$.
- $1 <= T <= N$.
- $1 <= t_i <= 10 000$ per ogni $1 <= i <= N-1$.
- $1 <= C_i <= N$ per ogni $1 <= i <= K$.
- $1 <= S_i <= 10^9$ per ogni $1 <= i <= K$.

#scoring

Il tuo programma verrà testato su diversi testcase raggruppati in subtask. Per ottenere il punteggio relativo
ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.

#ois_subtasks((
  subtask => [Casi d'esempio.],
  subtask => [$N <= 10$.],
  subtask => [$N <= 1 000$.],
  subtask => [$K = 1$.],
  subtask => [$t_i = 1$ per ogni $1 <= i <= N-1$.],
  subtask => [Nessuna limitazione aggiuntiva.]
),
(0, 1, 1, 2, 2, 3))

#examples(1)

#explanation

Nel *primo caso d'esempio* ci sono $N=4$ luoghi, il Toppo è in posizione $T=4$, e c'è un solo chiosco in posizione $1$ con soddisfazione $S=7$. I tempi di percorrenza sono $t_1=3$, $t_2=2$, $t_3=5$.

- Se Samuele partisse dalla posizione $1$: il chiosco si trova sul suo percorso ottimale $1 -> 2 -> 3 -> 4$, quindi non perde tempo extra.
- Se Samuele partisse dalla posizione $2$: compierebbe il percorso $2 -> 1 -> 2 -> 3 -> 4$, perdendo $6$ minuti. Dato che $6 <= 7$, prenderebbe la pizza.
- Se Samuele partisse dalla posizione $3$: il percorso ottimale è $3 -> 4$. Passare per $1$, prendendo la pizza, farebbe perdere $10$ minuti. Essendo il livello di soddisfazione della pizza $7 < 10$, non prenderebbe la pizza.
- Se Samuele partisse dalla posizione $4$: passare per $1$, prendendo la pizza, farebbe perdere $20$ minuti. Quindi non prenderebbe la pizza.

]