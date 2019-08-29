# Filler

The principle is simple: two players take on each other ona board, and take turns placing the piece that the master of the game (supplied in theform of a Ruby executable) gives them, earning points. The game stops as soon as apiece can no longer be placed.

### Introduction
<dt>Filler is an algorithmic game which consists in filling a grid of a known size in advancewith pieces of random size and shapes, without the pieces being stacked more than onesquare above each other and without them exceeding the grid. If one of these conditionsis not met, the game stops.</dt>
</br >
<dt>Each successfully placed piece yields a number of points, and has only one player, thegoal of the game could be to get the best score possible. However, it is with two playersthat the filler takes all his interest. Each player has for the purpose of placing as manypieces as possible while attempting to prevent his opponent from doing the same. At theend of the game, the one with the most points wins the match.</dt>

### Objectives
Writing a Filler player is a very interesting algorithmic challenge. Each turn, the activeplayer receives the grid status and must maximize his points while trying to minimizethose of the opponent by eliminating it as quickly as possible.
* Arrange the pieces as efficiently as possible.
* Prevente the opponent from doing so.
* Create your own filling algorithm to counter the enemy algorithm.

### Instructions
#### The Filler
* Executable's name: `<login>.filler`
* Two players fight each other. They play one after the other.
* The goal is to collect as many points as possible by placing the highest number ofpieces on the the game board.
* The board is defined by X columns and N lines, it will then become X*N cells.
* At the beginning of each turn, you will receive your game piece.
* A game piece is defined by X columns and N lines, so it will be X*N cells. Inside each game piece, will be included a shape of one or many cells.
* To be able to place a piece on the board, it is mandatory that one, and only one cell of the shape (in your piece) covers the cell of a shape placed previously (your territory).
* The shape must not exceed the dimensions of the board.
* When the game starts, the board already contains one shape.
* The game stops at the first error: either when a game piece cannot be placed anymore or it has been wrongly placed.
#### The Board
* A board is a two-dimensional grid with an arbitrary number of rows and columns.
* To launch the game an initial board must be passed as an argument to the VM. This initial board must have a starting form for each player.
#### The Tokens
* The tokens are managed randomly by the VM.
* You can’t predict their size or shape untilthe VM transmits them to your program.
#### The Topic
* The first two lines of the filler must be in the following format:
`$$$ exec pPLAYER_NUMBER : [PLAYER_NAME]`
* If you are Player 1 your program will be represented by “o” and “O”. If you are Player 2, your program will be represented by “x” and “X”. The first step will be to get your player number.
* The lowercases (“x” or “o”) will highlight the piece last placed on the board. At the following turns, that same piece will be represented by the uppercase letters (“X” or “O”), as it won’t be the piece last placed anymore.
* You collect points each time you place a piece.
* Each turn, the filler will send the updated map and a new token to the player concerned.
* The player concerned will write on the standard output his or her piece’s coordinates to place it on the board.
* The filler will send the map and a new piece to the other player.

### Usage
Usage: ./filler_vm -f path [-i | -p1 path | -p2 path] [-s | -q | -t time]
* -t  --time		set timeout in second
* -q  --quiet		quiet mode
* -i  --interactive	interactive mode(default)
* -p1 --player1	use filler binary as a first player
* -p2 --player2	use filler binary as a second player
* -f  --file		use a map file (required)
* -s  --seed		use the seed number (initialization random) (man srand)
