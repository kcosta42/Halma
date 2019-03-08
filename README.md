# Halma

About
-----
>Halma is a strategy board game invented in 1883 or 1884 by George Howard Monks, a US thoracic surgeon at Harvard Medical School. His inspiration was the English game Hoppity which was devised in 1854. The gameboard is checkered and divided into 16×16 squares.

Rules
-----
> Players take turns to move a single piece of their own colour. The piece may either be simply moved into an adjacent square OR it may make one or more hops over other pieces
>
>After each hop, the player may either finish or, if possible and desired, continue by hopping over another piece.
>
>The aim of the game is to be the first to player to move all pieces across the board and into opposing corner.

This is a project of ECE Paris Graduate School of Engineering

Installation
------------
Run `make fclean && make`

Usage
-----
Run `./halma` it will launch an interactive interface

### Example
```
  X  0 1 2 3 4 5 6 7 8 9 a b c d e f
Y
0    A A A . . . . . . . . . . C C C
1    . A A . . . . . . . . . . C C C
2    . A A A . . . . . . . C C C C C
3    . A A . . . . . . . . . C . . C
4    A A . A . . . . . . . . . . . .
5    . . . . . . . . . . . . . . . .
6    . . . . . . . . . . . . . . . .
7    . . . . . . . . . . . . . . . .
8    . . . . . . . . . . . . . . . .
9    . . . . . . . . . . . . . . . .
a    . . D . . . . . . . . . . . . .
b    D D . . . . . . . . . . . . . B
c    . . . . . . . . . . . . B . . B
d    D D D . . . . . . . B . . B B B
e    D D D D . . . . . . . . . B B .
f    . . D . D D . . . . . . B B B B

[Player 1 turn]
Choose which pion to move:
Enter valid coordinate for X:
```

##### Project done in 2016
