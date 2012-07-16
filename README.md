SPACES BETWEEN SPACES
=====================


About
-----

Conway's Game of Life is an infinite 2-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead. Every cell interacts with its eight neighbours, which are the cells that are horizontally, veritically or diagonally adjacent. At each step in time, the following transitions occur:

	1. Any live cell with fewer than 2 live neighbours dies, as if caused by under-population.
	2. Any live cell with 2 or 3 live neighbours lives on to the next generation.
	3. Any live cell with more than 3 live neighbours dies, as if by overcrowding.
	4. Any dead cell with exactly 3 live neighbours becomes a live cell, as if by reproduction.



Menu Options
------------

The Start Menu offers 3 choices to define a new board:
* Enter Info Through Keyboard
* Load Data File
* Load Predefined Board

If the user selects to *Enter Info through Keyboard*, they will then be asked to *Enter Number of Rows (5-20)* as well as *Enter the number of columns (5-40)*. Once the user enters the size of the new board, they will then be asked to enter the coordinates of each live cell's row & column.

If the user selects to *Load Data File*, the menu will ask for a full data file name to load. Please make sure enter the full path to the working directory containing your file. Please note, the current supported file is `.txt` .... future updates will also provide support for `.json` and `.csv` files.



If the user selects *Load Predefined Board* , they will be allowed to choose from 4 different predefined shapes. 


*(1) Backslash*  
![](http://github.com/accraze/spaces-between-spaces/raw/master/img/backslash1.jpg)   


*(2) Double Helix*  
![](http://github.com/accraze/spaces-between-spaces/raw/master/img/doublehelix.jpg)   


*(3) Triangle*  
![](http://github.com/accraze/spaces-between-spaces/raw/master/img/triangle.jpg)    


*(4) Diamond*  
![](http://github.com/accraze/spaces-between-spaces/raw/master/img/diamond.jpg)

After a Start Menu option has been chosen and configured, the game will start.


Game Play
---------

Conway's Game of Life is described as a 'zero-player game' meaning that it will run based on its initial state. Create an initial configuration and observe how it evolves!


Once the initial configuration is displayed, hit any key to continue. The game play menu will appear:

![](http://github.com/accraze/spaces-between-spaces/raw/master/img/menu.jpg)

*(1) Create Spaces Between Spaces
*(2) Restart the Game
*(3) Display the Current Board
*(4) Enter a New Board
*(5) Stop the Program

To play the game select '(1) Create Spaces Between Spaces'. The user will be asked to define how many 'steps' in evolution of the board are desired. The board will then cycle through its many steps of evolution.

To restart the game from its initial configuration select '(2) Restart the Game'.

To view the board in its current state, choose  '(3) Display the Current Board'

Choose '(4) Enter a New Board' to set up a new initial configuration.

To quit, select '(5) Stop the Program'.



