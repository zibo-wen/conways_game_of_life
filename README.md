# Conway's Game of Life

## Background
Here is a brief description of the Conway's Game of Life from WikiPedia:
> _The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine._

<div align="center">
  <img src="/img/pulsar.gif" alt="Pulsar Pattern" width="390">
  
  _Example Output: One of the Oscillator Patterns in GOL, Known as "Pulsar"_
</div>



## Rules and Description
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

* Any live cell with fewer than two live neighbours dies, as if by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

These rules, which compare the behavior of the automaton to real life, can be condensed into the following:

* Any live cell with two or three live neighbours survives.
* Any dead cell with three live neighbours becomes a live cell.
* All other live cells die in the next generation. Similarly, all other dead cells stay dead.

These three rules are implemented in the _Game_ class when calculating the status of the next generation.
In each iteration, the future status of a cell depends solely on its own status and the number of alive cells around it. To speed up the computation, each cell on the board (the _Cell_ class) contains three elements: the current status, the status in the next generation, and the number of alive cells adjacent to it. The number of alive cells is only updated when the status of an adjacent changes, and in this way, a lot of unnecessary calculations are avoided. 

## Future Development
  1. Plan to build a GUI for this game to show the life patterns in each iteration and to allow pausing and resuming at any time.
  
  2. Plan to design a more formal formatting for the pattern files, including error handlings in the initialization process.
