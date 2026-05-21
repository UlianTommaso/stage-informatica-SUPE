#import "template.typ": *
#import "@preview/subpar:0.1.1"

/* Setting the statement language for localization */
#set text(lang: "it")
#override_localization.update(_ => (:))

#set text(font: ("Libertinus Serif"))

/* Statement content block */
#statement[

Alessandro lavora come pizzaiolo alla Pizzeria Appollonia. Per preparare le pizze per i ragazzi dello Stage, Alessandro ha a disposizione $N$ forni, le cui temperature cambiano continuamente.

#figure(
  image("valerio.jpeg", width: 60%),
  caption: "Alessandro intento a cucinare le pizze."
)

Gli $N$ forni sono numerati da $1$ a $N$ e inizialmente il forno $i$ ha una temperatura di $t_i$ gradi.

Durante la giornata, per preparare le pizze, avvengono $Q$ *eventi* sui forni. Ogni evento è di uno dei seguenti tipi:
- La temperatura del forno $k$ cambia a $x$ gradi. 
- Alessandro si chiede quanti sono i forni che hanno uba temperatura di tra $x$ gradi, così da cucinare la pizza senza bruciarla.

Dato che Alessandro è indaffarato a preparare le pizze, aiutalo rispondendo alle sue domande.

#inputfile

La prima riga di input contiene due interi $N$ e $Q$, rispettivamente il numero di forni gestiti da Alessandro e il numero di operazioni che avvengono durante la serata. I forni sono numerati da $1, 2, dots, N$.

La riga successiva contiene $N$ interi $t_1, t_2, dots, t_N$: la temperatura iniziale di ogni forno.

Successivamente, ci sono $Q$ righe che descrivono le operazioni. Ogni riga ha una delle seguenti forme:

- *`! k x`*: Alessandro abbassa o alza la fiamma, impostando la temperatura del forno $k$ a $x$ gradi.
- *`? x`*: Alessandro vuole sapere quanti forni hanno una temperatura attualmente pari esattamente a $x$ gradi.

#note[
Tra gli allegati a questo task troverai un template `forni_easy.*` con un esempio di implementazione.
]

#outputfile
Stampa la risposta per ogni interrogazione di tipo `?` su una nuova riga, così che Alessandro possa leggerla velocemente sul monitor.


#constraints

- $1 <= N, Q <= 2 dot 10^5$
- $1 <= t_i <= 10^9$
- $1 <= k <= N$
- $1 <= x <= 10^9$

#scoring

Il tuo programma verrà testato su diversi testcase raggruppati in subtask. Per ottenere il punteggio relativo
ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.

#ois_subtasks((
  subtask => [Casi d'esempio.],
  subtask => [$N, Q <= 1000$.],
  subtask => [Tutte le temperature iniziali e quelle inserite nelle query sono al massimo $10^6$ (ovvero $t_i, x <= 10^6$).],
  subtask => [Nessuna limitazione aggiuntiva.]
),
(0, 1, 2, 2))

#examples(1)

#explanation

Nel *primo caso d'esempio*:
- Inizialmente ci sono $5$ forni con temperature $[3, 7, 2, 2, 5]$.
- Alla query `? 2`, ci sono $2$ forni (il terzo e il quarto) con temperatura pari a $2$. Viene quindi stampato `2`.
- L'operazione `! 3 6` modifica la temperatura del terzo forno portandola a $6$. Le temperature diventano $[3, 7, 6, 2, 5]$.
- Alla query `? 2`, ora c'è solo $1$ forno (il quarto) con temperatura pari a $2$. Viene quindi stampato `1`.
]
