#import "template.typ": *
#import "@preview/subpar:0.1.1"

/* Setting the statement language for localization */
#set text(lang: "it")
#override_localization.update(_ => (:))

#set text(font: ("Libertinus Serif"))

/* Statement content block */
#statement[

Allo stage partecipano $N$ ragazzi, numerati da $1$ a $N$, e sono tutti molto affamati.
Per questo Tommaso decide, per il pranzo, di preparare le pizze scegliendo i seguenti gusti: 
#strong("D")iavola, #strong("C")apricciosa, #strong("W")urstel, #strong("S")alsiccia e #strong("M")arinara. 

Raccoglie le ordinazioni e scrive ogni singola richiesta su un bigliettino.
Ogni bigliettino contiene la lettera iniziale del gusto di pizza e un intero, il numero del ragazzo che l'ha ordinata. 

#figure(
  image("carte2.png", width: 60%),
  caption: "Le carte di Toppabi con i gettoni indizio."
)

Ogni ragazzo può ordinare quante pizze desidera, ma al massimo una per ogni gusto. 
È anche possibile che un ragazzo non ordini nulla.

Purtroppo, mentre va in cucina, Tommaso inciampa e scompiglia tutte le comande che aveva in mano.
Prima di iniziare a infornare, deve riordinare i bigliettini in fila rispettando queste regole:
- I bigliettini dello stesso gusto devono essere tutti vicini tra loro, così da prepararle tutte di seguito.
- Per ogni gusto, i bigliettini devono essere ordinati in modo crescente in base al numero del ragazzo, così da non confondersi nella consegna.
- Essendo più delicate da preparare per via delle attenzioni verso i vegani, tutte le ordinazioni della pizza Marinara (M) devono trovarsi alla fine della fila.

In una singola mossa, Tommaso può prendere un bigliettino dalla fila e reinserirlo in qualsiasi altra posizione (all'inizio, alla fine o tra due bigliettini). Essendo di fretta, vuole eseguire il minimo numero di mosse per riordinare i bigliettini. 

Aiuta Tommaso a calcolare il minimo numero di mosse necessarie.

#inputfile
La prima riga contiene un intero $N$, il numero di carte pescate da Lorenzo.

La seconda riga contiene $N$ valori separati da uno spazio, che rappresentano i bigliettini.
Ogni bigliettino è una stringa composta da un carattere tra {`D`, `C`, `W`, `S`, `M`},
che rappresenta il gusto della pizza, seguito un numero intero $V$ tale che $1 <= V <= N$, che rappresenta il numero del ragazzo che l'ha ordinata.

#note[
Tra gli allegati a questo task troverai un template `pizzaiolo_hard.*` con un esempio di implementazione.
]

#outputfile
Stampa un singolo intero, il minimo numero di mosse che deve fare Tommaso per riordinare i bigliettini. 


#constraints

- $1 <= N <= 100 000$.
- I bigliettini sono tutti distinti.

#scoring

Il tuo programma verrà testato su diversi testcase raggruppati in subtask. Per ottenere il punteggio relativo
ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.

#ois_subtasks((
  subtask => [Casi d'esempio.],
  subtask => [Per ogni gusto c'è un solo bigliettino.],
  subtask => [Per ogni gusto ci sono al massimo due bigliettini e i gusti sono ordinati tra loro secondo l'ordine `D` < `C` < `W` < `S` < `M`.],
  subtask => [Tutte i bigliettini sono del gusto `C`, $N <= 2 000$.],
  subtask => [$N <= 2 000$.],
  subtask => [Nessuna limitazione aggiuntiva.]
),
(0, 1, 2, 2, 2, 3))

#examples(2)

#explanation

Nel *primo caso d'esempio*, Tommaso con una mossa può spostare il bigliettino `M1` all'ultima posizione e con un'altra mossa spostare il bigliettino `S1` alla prima posizione.

Nel *secondo caso d'esempio*, i bigliettini sono già ordinati secondo le regole di Tommaso.
]