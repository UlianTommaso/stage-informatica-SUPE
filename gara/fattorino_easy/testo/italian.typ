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

Via Gemona è composta da $N$ luoghi in fila, numerati da $0$ a $N-1$. Samuele impiega $t_i$ minuti per camminare dal luogo $i$ al luogo $i+1$, e viceversa.

Samuele intanto si è perso in via Gemona e, dato che si è fatto tardi, decide di tornare al Toppo, in posizione $T$.

In $K$ luoghi $C_0, dots, C_(K-1)$ di via Gemona ci sono dei chioschi che vendono tranci di pizza. Il chiosco in posizione $C_i$ vende un trancio di pizza con un livello di soddisfazione $S_i$ (misurato in "quanto vale la pena fermarsi").

Samuele è disposto a fermarsi al massimo in un chiosco lungo il suo percorso verso il Toppo, ma solo se il tempo extra aggiunto al suo percorso è al massimo uguale al livello di soddisfazione della pizza che prenderebbe. In altre parole, se fermarsi a prendere una pizza gli fa perdere $t$ minuti in più rispetto al percorso più veloce, lo farà solo se il livello di soddisfazione è almeno $t$.

Dato che non sappiamo dove si trova Samuele, determina per ogni possibile posizione iniziale se Samuele si fermerà a prendere la pizza oppure no.

// #figure(
//   image("carte2.png", width: 60%),
//   caption: "Le carte di Toppabi con i gettoni indizio."
// )

#inputfile
La prima riga contiene gli interi $N$, $K$, $T$, rispettivamente il numero di luoghi, il numero di chioschi e la posizione del Toppo.

La $1+i$-esima riga $(0<=i<N-1)$ contiene un intero $t_i$, i minuti che ci mette Samuele per andare dal luogo $i$ al luogo $i + 1$, e viceversa.

La $N+i$-esima riga $(0<=i<K)$ righa contiene gli interi $C_i$ e $S_i$, rispettivamente la posizione dell'$i$-esimo chiosco e il suo livello di soddisfazione.

#note[
Tra gli allegati a questo task troverai un template `pizzaiolo_easy.*` con un esempio di implementazione.
]

#outputfile
Stampa $N$ righe. All'$i$-esima riga stampa $1$ se Samuele, partendo dalla posizione $i$, si fermerà a prendere la pizza. Stampa $0$ altrimenti. 

#constraints

- $2 <= N <= 50000$.
- $1 <= M <= 100000$.
- $1 <= K <= N$.
- $0 <= T < N$.
- $0 <= a_i, b_i < N$ e $a_i != b_i$ per ogni $0 <= i < M$.
- $1 <= t_i <= 10 000$ per ogni $0 <= i < M$.
- $0 <= C_i < N$ per ogni $0 <= i < K$.
- $1 <= S_i <= 10^9$ per ogni $0 <= i < K$.
- Ogni incrocio è raggiungibile da ogni altro incrocio.
- Le strade sono bidirezionali.

#scoring

Il tuo programma verrà testato su diversi testcase raggruppati in subtask. Per ottenere il punteggio relativo
ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.

#ois_subtasks((
  subtask => [Casi d'esempio.],
  subtask => [$N <= 500$.],
  subtask => [$K = 1$.],
  subtask => [$N <= 5 000$, $M <= 10 000$.],
  subtask => [$t_i = 1$ per ogni $0 <= i < M$.],
  subtask => [Nessuna limitazione aggiuntiva.]
),
(0, 2, 2, 3, 4, 5))

#examples(1)

#explanation

Nel *primo caso d'esempio*:
- Se Samuele parte dall'incrocio $0$, compie il percorso $0 -> 3 -> 1 -> 3$, prendendo la pizza nell'incrocio $1$. Il percorso aumenta di $6$ minuti, ma il livello di soddisfazione delle pizze nel chiosco $1$ è di $7$.
- Se Samuele parte dall'incrocio $1$, compie il percorso $1 -> 3$, prendendo la pizza nell'incrocio $1$. Il percorso coincide con quello ottimale.
- Se Samuele parte dall'incrocio $2$, compie il percorso $2 -> 3 -> 1 -> 3$, prendendo la pizza nell'incrocio $1$.
- Se Samuele parte dall'incrocio $3$, compie il percorso $3 -> 1 -> 3$, prendendo la pizza nell'incrocio $1$.

]