#import "template.typ": *
#import "@preview/subpar:0.1.1"

/* Setting the statement language for localization */
#set text(lang: "it")
#override_localization.update(_ => (:))

#set text(font: ("Libertinus Serif"))

/* Statement content block */
#statement[

Allo stage partecipano $N$ ragazzi, tutti molto affamati. 
Per il pranzo, Tommaso decide di preparare le pizze scegliendo tra i seguenti gusti: 
#strong("D")iavola, #strong("C")apricciosa, #strong("W")urstel, #strong("S")alsiccia e #strong("M")arinara. 

Ogni ragazzo fa al massimo un'ordinazione e Tommaso raccoglie $N$ ordinazioni in totale. 
Per ogni ordinazione, scrive su un bigliettino la lettera iniziale del gusto di pizza richiesto.

#figure(
  image("carte2.png", width: 60%),
  caption: "I bigliettini delle pizze."
)

Purtroppo, mentre va in cucina, Tommaso inciampa e scompiglia tutte le comande che aveva in mano.
Prima di iniziare a infornare, deve riordinare i bigliettini in fila rispettando queste regole:
- I bigliettini dello stesso gusto devono essere tutti vicini tra loro, così da preparare le pizze dello stesso tipo tutte di seguito.
- Essendo più delicate da preparare per via delle attenzioni verso i vegani, tutte le ordinazioni della pizza Marinara (M) devono trovarsi alla fine della fila.

In una singola mossa, Tommaso può prendere un bigliettino dalla fila e reinserirlo in qualsiasi altra posizione (all'inizio, alla fine o tra due bigliettini). Essendo di fretta, vuole eseguire il minimo numero di mosse per riordinare i bigliettini. 

Aiuta Tommaso a calcolare il minimo numero di mosse necessarie.

#inputfile
La prima riga contiene un intero $N$, il numero di bigliettini raccolti.

La seconda riga contiene $N$ caratteri separati da uno spazio, che rappresentano i bigliettini.
Ogni bigliettino è un carattere tra {`D`, `C`, `W`, `S`, `M`}, che rappresenta il gusto della pizza ordinata.

#note[
Tra gli allegati a questo task troverai un template `pizzaiolo_easy.*` con un esempio di implementazione.
]

#outputfile
Stampa un singolo intero, il minimo numero di mosse che deve fare Tommaso per riordinare i bigliettini. 


#constraints

- $1 <= N <= 100 000$.

#scoring

Il tuo programma verrà testato su diversi testcase raggruppati in subtask. Per ottenere il punteggio relativo
ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.

#ois_subtasks((
  subtask => [Casi d'esempio.],
  subtask => [Sono presenti bigliettini di esattamente 2 gusti in totale.],
  subtask => [La pizza Marinara (`M`) non è stata richiesta da nessuno e $N <= 2 000$.],
  subtask => [Esiste una soluzione in cui l'ordine finale dei gusti è `D`, `C`, `W`, `S`, `M`.],
  subtask => [Nessuna limitazione aggiuntiva.]
),
(0, 1, 2, 2, 3))

#examples(2)

#explanation

Nel *primo caso d'esempio*, Tommaso con una mossa può spostare il bigliettino `M` all'ultima posizione e con un'altra mossa spostare il secondo bigliettino `S` accanto al primo. L'ordine finale è `S S W M`.

Nel *secondo caso d'esempio*, i bigliettini sono già ordinati secondo le regole di Tommaso.
]