#import "template.typ": *
#import "@preview/subpar:0.1.1"

/* Setting the statement language for localization */
#set text(lang: "it")
#override_localization.update(_ => (:))

#set text(font: ("Libertinus Serif"))

/* Statement content block */
#statement[

La **Pizzeria Apollonia** non è un locale qualunque: è un vero e proprio tempio della pizza, famoso in tutta la città per il suo cornicione perfettamente alveolato e la cottura sempre impeccabile. Al centro di questo miracolo culinario c'è Alessandro, il maestro fornaio. Ogni sera, durante il frenetico servizio, Alessandro si destreggia tra $n$ forni ad altissime prestazioni, ognuno con la propria temperatura in continua variazione.

Il segreto di Alessandro per una pizza che cuocia alla perfezione, dorandosi al punto giusto senza mai bruciare, è il controllo assoluto del calore. Tuttavia, con centinaia di comande che arrivano in cucina, è umanamente impossibile tenere d'occhio i display di ogni singolo forno a mano. Per questo motivo, la pizzeria ha deciso di implementare un sistema informatico per monitorare in tempo reale i gradi dei forni e gestire i cambi di settaggio.

Il tuo compito è aiutare Alessandro scrivendo un programma che tenga traccia delle temperature. Quando Alessandro ha la pala in mano con una Margherita appena stesa, ha bisogno di sapere in un istante quanti forni si trovano esattamente nell'intervallo di calore perfetto per infornare. Aiutalo a non far bruciare l'impasto!

#inputfile

La prima riga di input contiene due interi $N$ e $Q$: il numero di forni gestiti da Alessandro e il numero di operazioni che avvengono durante la serata. I forni sono numerati da $1, 2, \dots, N$.

La riga successiva contiene $n$ interi $t_1, t_2, \dots, t_N$: la temperatura iniziale di ogni forno.

Successivamente, ci sono $Q$ righe che descrivono le operazioni. Ogni riga ha una delle seguenti forme:

* **`! k x`**: Alessandro abbassa o alza la fiamma, impostando la temperatura del forno $k$ a $x$ gradi.
* **`? a b`**: Alessandro deve infornare! Vuole sapere quanti forni hanno una temperatura attualmente compresa tra $a$ e $b$ (inclusi), ovvero l'intervallo di sicurezza in quel momento per cuocere senza bruciare.

#note[
]

#outputfile
Stampa la risposta per ogni interrogazione di tipo `?` su una nuova riga, così che Alessandro possa leggerla velocemente sul monitor.


#constraints

* $1 \le N, Q \le 2 \cdot 10^5$
* $1 \le t_i \le 10^9$
* $1 \le k \le N$
* $1 \le x \le 10^9$
* $1 \le a \le b \le 10^9$

#scoring

Il tuo programma verrà testato su diversi testcase raggruppati in subtask. Per ottenere il punteggio relativo
ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.

#ois_subtasks((
  subtask => [Casi d'esempio.],
  subtask => [$N,Q\leq 1000$.],
  subtask => [La risposta ad ogni query `? a b` non è mai maggiore di $100$.]
  subtask => [Nessuna limitazione aggiuntiva.]
),
(0, 1, 2, 3))

#examples(1)

#explanation

]