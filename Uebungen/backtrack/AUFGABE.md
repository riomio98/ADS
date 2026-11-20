# ADS – Testatsimulation 1: Rekursiver optimaler Textumbruch

**Bearbeitungszeit: 60 Minuten.** Diese Aufgabe ist eine Übungssimulation,
keine tatsächliche Prüfungsaufgabe.

## Ausgangslage

Das bekannte Mini-Projekt bricht Texte gierig um. Eine Zeile darf maximal
`breite` Zeichen haben. Zwischen zwei Wörtern ist jeweils genau ein Leerzeichen.
Die Kosten einer Zeile sind `(breite - zeilenbreite)^2`.
Die letzte Zeile hat Kosten 0. Auch leere Texte sind zulässig.
Es ist sichergestellt, dass jedes Wort in die Spaltenbreite passt.

Die Funktionen `zeilenbreite`, `zeilenkosten`, `gierigerUmbruch` und
`gierigeKosten` sind bereits implementiert. Es sind keine Änderungen an
der Kommandozeilenverarbeitung erforderlich.

## Deine Aufgaben

**A – Herleitung (10 Minuten):** Definiere, welches Teilproblem ein Aufruf
`optimaleKosten(woerter, breite, start)` löst. Formuliere einen Basisfall
und eine Rekursionsvorschrift.

**B – Implementierung (35 Minuten):** Implementiere ausschließlich
`optimaleKosten(...)` in `common.cpp`. Die Funktion soll die minimal möglichen
Gesamtkosten zurückgeben. Die ursprüngliche Reihenfolge der Wörter muss
erhalten bleiben. Verwende Rekursion und verzichte zunächst auf
Memoisierung oder andere Optimierungen.

**C – Prüfung (15 Minuten):** Teste leere Eingabe, einen einzelnen Begriff,
mehrere zwingende Zeilen und einen Fall, in dem Greedy schlechter ist.
Beschreibe, warum die vollständige rekursive Suche im schlechtesten Fall
viel mehr Kombinationen durchläuft als das Greedy-Verfahren.

## Verbindlicher Testfall

Text: `aaa bb cc ddddd`, Breite: `6`

Greedy:

    aaa bb    # Kosten 0
    cc        # Kosten 16
    ddddd     # Kosten 0 (letzte Zeile)

Ergebnis: **16**

Optimal:

    aaa       # Kosten 9
    bb cc     # Kosten 1
    ddddd     # Kosten 0

Ergebnis: **10**

## Dateien

- `common.h` – Funktionsschnittstellen
- `common.cpp` – vorbereitete Funktionen und **TODO** für Rekursion
- `spalte.cpp` – vollständiges Hauptprogramm
- `tests.cpp` – automatische Tests, die zu Beginn absichtlich fehlschlagen
- `beispiel.txt` – Originalbeispiel des Mini-Projekts
- `kurz.txt` – Testeingabe, bei der Greedy nicht optimal ist

## Kompilieren (C++17)

Unter Windows mit MinGW/g++ (Eclipse kann dieselben Dateien verwenden):

```sh
g++ -std=c++17 -Wall -Wextra -pedantic spalte.cpp common.cpp -o spalte.exe
g++ -std=c++17 -Wall -Wextra -pedantic tests.cpp common.cpp -o tests.exe
```

Unter Linux entsprechend `-o spalte` und `-o tests` verwenden.

Testaufrufe:

```sh
./spalte.exe kurz.txt -w=6 -z
./spalte.exe beispiel.txt -w=29 -z
./tests.exe
```

**Wichtig:** Das Projekt kompiliert sofort. Der Platzhalter der Testatfunktion
liefert zunächst `-1`. Damit zeigt das Hauptprogramm bewusst noch kein
korrektes optimales Ergebnis, und alle automatischen Tests schlagen fehl,
bis du deine rekursive Lösung implementiert hast.

Die Übungsdateien nutzen `using namespace std;` in den `.cpp`-Dateien.
Anders als das Original-Mini-Projekt ist das Paket unabhängig von `pbma`,
damit es ohne zusätzliche Dateien kompiliert werden kann.
