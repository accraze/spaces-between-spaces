// ANDREW CRAZE PROGRAM #6 "SPACES BETWEEN SPACES"
// conways game of life....cellular automaton using 2-D arrays and subprograms.


#include <fstream.h>
#include <iostream.h>

const int HEIGHT = 45, WIDTH = 25;
void introMenu ( int &introChoice );
void enterFromKeyboard ( char initBoard[][WIDTH], int &rows, int &columns);
void newBoard ( void );
void boardDataFile ( char initBoard [] [WIDTH], int &rows, int &columns);
int countLiveCells ( char currentBoard[][WIDTH], int nrows, int ncols );
void arrayCopy (char dest [][WIDTH], char source[] [WIDTH] );
int countLiveNeighbor ( char currentBoard [] [WIDTH], int row, int columns );
void playGame (char currentBoard [] [WIDTH], 
			   char nextGenBoard [][WIDTH], int nrows, int ncols );
void restart (char initBoard [] [WIDTH], char currentBoard [] [WIDTH]);
void displayCurrentBoard ( char currentBoard[][WIDTH], int nrows, int ncols  );
void loadPattern ( char initBoard [] [WIDTH], char pattern[][WIDTH], int &rows, int &columns);
void patternMenu ( int &patternChoice );
void loadPatternArray( char pattern[] [WIDTH], int &rows, int &columns, int choice);
void arrayLoad ( char currentBoard[] [WIDTH], int nrows, int ncols );
void gameMenuDisplay ( int &gameMenuChoice );
void computeNextGeneration ( char currentBoard [][WIDTH], 
							char nextGenBoard [][WIDTH], int nrows, int ncols );


int main ( ) {
	
	int introChoice, gameMenuChoice, rows, columns, restartBoard, enterNewBoard;
	int i;
	char initBoard [HEIGHT] [WIDTH];
	char currentBoard [HEIGHT] [WIDTH];
	char nextGenBoard [HEIGHT] [WIDTH];
	char pattern [HEIGHT] [WIDTH];
	char repeat;
	
	
	do{
		enterNewBoard = 0;
		rows = 0;
		columns = 0;
		
	do{


	cout << endl << "*** Spaces Between Spaces ***" << endl;
	introMenu(introChoice);
	
	if (introChoice == 1) {
		enterFromKeyboard ( initBoard, rows, columns);
		repeat = 'n';
	}
	
		else if (introChoice == 2) {
			cout << endl<< "Load From Files" << endl;
			boardDataFile(initBoard, rows, columns);
			repeat = 'n';
		}
	
			else if (introChoice == 3) {
				cout << "Load Presets" << endl;
				loadPattern(initBoard, pattern, rows, columns);
				repeat = 'n';
				}
	
	else {
		cout << "Error: Invalid Entry" << endl << endl;
		repeat = 'y';
	}
	
}while (repeat == 'y');
	
	arrayCopy(currentBoard, initBoard);
		
	displayCurrentBoard ( currentBoard, rows, columns);
	
do{
	restartBoard = 0;
	gameMenuDisplay(gameMenuChoice);

	if (gameMenuChoice == 1) {
		playGame(currentBoard, nextGenBoard, rows, columns);
		restartBoard = 1;
	}
	
		else if (gameMenuChoice == 2) {
			restart(initBoard, currentBoard);
			restartBoard = 1;
		}
	
			else if (gameMenuChoice == 3) {
				cout << "Displaying Current Board...." << endl;
				displayCurrentBoard(currentBoard, rows, columns);
				restartBoard = 1;
			}
			else if (gameMenuChoice == 4){
				cout << "Enter a New Board" << endl;
				restartBoard = 0;
				enterNewBoard = 1;
				for (i = 0; i < 7;++i) {
					cout << endl;
				}
			}
			else if (gameMenuChoice == 5){
				cout << endl << endl << endl;
				restartBoard = 0;
			}
} while ( restartBoard == 1);
	}while (enterNewBoard == 1); // loop that allows User to enter new board
	
	cout << "Have A Good Day" << endl;
		cout << "Goodbye!" << endl << endl;
		return 0;
}											// End of int main

void introMenu ( int &introChoice )  // define a new board
{
	
	cout << endl << "Define a New Board" << endl;
	cout << "1)Enter Info Through Keyboard" << endl;
	cout << "2)Load Data File" << endl;
	cout << "3)Load Predefined Board" << endl;
	cin >> introChoice;
}


void enterFromKeyboard ( char initBoard[][WIDTH], int &rows, int &columns)
{
	int liveCellRow, liveCellColumn;
	char repeat;
	
	
	do {
		
	cout << "Enter Number of Rows (5-20): " << endl;
	cin >> rows;
		if (rows < 5 || rows > 20) {
			cout << "Error: Number must be between (5-20)" << endl;
		    }
	} while (rows < 5 || rows > 20); // input rows
	
	
	do{
		
	cout << "Enter Number of Columns (5-40): " << endl;
	cin >> columns;
		if (columns < 5 || columns > 40) {
			cout << "Error: Number must be between (5-40)" << endl;
		}
	} while (columns < 5 || columns > 40); // input columns
	
	arrayLoad(initBoard, rows, columns );
	
	do {
		
		cout << "Enter Live Cell Row: ";
		cin >> liveCellRow;
		
		cout << "Enter Live Cell Column: ";
		cin >> liveCellColumn;
			
		initBoard [liveCellRow][liveCellColumn] = '*';
		
		cout << "More Live Cells? (y/n): ";
		cin >> repeat;
		
	}while (repeat == 'y'); // Loads up initBoard live cells
}


void arrayLoad ( char currentBoard[] [WIDTH], int nrows, int ncols )
{
	int col, row;
	
	for ( row = 0; row < nrows;  ++row) {
		for (col = 0; col < ncols; ++col) {
			currentBoard [row] [col] =  ' ';
		}
	}         // loads empty spaces into array
	
	
	for (row = 1; row < nrows; ++row) {
		
		currentBoard[row] [1] = '|';
		currentBoard[row] [ncols-1] = '|';
	}				// loads sidebars into array
	
	
}

void boardDataFile ( char initBoard [] [WIDTH] ,int &rows, int &columns)
{
	fstream infile;
	char fileName [100];
	int  i ,ix;
	
	cout << "Please Enter Full Data File Name To Load: " << endl;
	cin >> fileName;
	
	infile.open ( fileName , ios::in );

	
	if ( infile.fail() )
	{
		rows = 0;
		columns = 0;
		cout << "File open failure" << endl;
	}
	
    infile >> rows;
	infile >> columns;
	
	
	
	
	for (i = 1; i <= rows + 2; ++i){
		
		
		for (ix = 1; ix <= columns + 2; ++ix){
			
			infile >> initBoard [i][ix];
			
		}
		
	}
	
		
	infile.close();
	
	for ( i = 1; i < rows; ++i){
		for (ix = 0; ix < columns; ++ix){
			if (initBoard [i][ix] == '-') {
				initBoard [i][ix] = ' ';
			}
		}
	}
	
}

void loadPattern ( char initBoard[] [WIDTH],char pattern[][WIDTH], int &rows, int &columns)
{
	int patternChoice;
	cout << endl << "Please Select a Predefined pattern: " << endl;
	patternMenu(patternChoice);
	loadPatternArray( pattern, rows, columns, patternChoice);
	arrayCopy(initBoard, pattern);
}

void patternMenu ( int &patternChoice ){
	
	cout << "(1) Backslash" << endl;
	cout << "(2) Double-Helix" << endl;
	cout << "(3) Triangle" << endl;
	cout << "(4) Diamond" << endl;
	
	do{
		cout << "Please Enter Your Choice: ";
		cin >> patternChoice;
		if (patternChoice > 5) {
			cout << "Error: Choice Must be from (1-5)" << endl;
		}
	}while(patternChoice > 5);
}

void loadPatternArray (char pattern[][WIDTH], int &rows, int &columns, int choice)
{

	if (choice == 1) {
		rows = 7;
		columns = 13;
		arrayLoad(pattern, rows, columns);
		pattern [1][3] = '*';
		pattern [1][4] = '*';
		pattern [1][5] = '*';
		pattern [2][4] = '*';
		pattern [2][5] = '*';
		pattern [2][6] = '*';
		pattern [3][5] = '*';
		pattern [3][6] = '*';
		pattern [3][7] = '*';
		pattern [4][6] = '*';
		pattern [4][7] = '*';
		pattern [4][8] = '*';
		pattern [5][7] = '*';
		pattern [5][8] = '*';
		pattern [5][9] = '*';
		pattern [6][8] = '*';
		pattern [6][9] = '*';
		pattern [6][10] = '*';
		pattern [7][9] = '*';
		pattern [7][10] = '*';
		pattern [7][11] = '*';
	}
	
	else if ( choice == 2){
		rows = 8;
		columns = 12;
		arrayLoad(pattern, rows, columns);
		pattern [1][5] = '*';
		pattern [1][7] = '*';
		pattern [2][5] = '*';
		pattern [2][6] = '*';
		pattern [2][7] = '*';
		pattern [3][5] = '*';
		pattern [3][7] = '*';
		pattern [4][6] = '*';
		pattern [5][5] = '*';
		pattern [5][7] = '*';
		pattern [6][5] = '*';
		pattern [6][6] = '*';
		pattern [6][7] = '*';
		pattern [7][5] = '*';
		pattern [7][7] = '*';
		
 }
	
	else if ( choice == 3){
		rows = 5;
		columns = 15;
		arrayLoad(pattern, rows, columns);
		pattern [1][7] = '*';
		pattern [2][6] = '*';
		pattern [2][7] = '*';
		pattern [2][8] = '*';
		pattern [3][5] = '*';
		pattern [3][6] = '*';
		pattern [3][7] = '*';
		pattern [3][8] = '*';
		pattern [3][9] = '*';
		pattern [4][4] = '*';
		pattern [4][5] = '*';
		pattern [4][6] = '*';
		pattern [4][7] = '*';
		pattern [4][8] = '*';
		pattern [4][9] = '*';
		pattern [4][10] = '*';
		
	}
	
	
	else if ( choice == 4){
		rows = 11;
		columns = 15;
		arrayLoad(pattern, rows, columns);
		pattern [1][7] = '*';
		pattern [2][6] = '*';
		pattern [2][7] = '*';
		pattern [2][8] = '*';
		pattern [3][5] = '*';
		pattern [3][6] = '*';
		pattern [3][7] = '*';
		pattern [3][8] = '*';
		pattern [3][9] = '*';
		pattern [4][4] = '*';
		pattern [4][5] = '*';
		pattern [4][6] = '*';
		pattern [4][7] = '*';
		pattern [4][8] = '*';
		pattern [4][9] = '*';
		pattern [4][10] = '*';
		pattern [5][4] = '*';
		pattern [5][5] = '*';
		pattern [5][6] = '*';
		pattern [5][7] = '*';
		pattern [5][8] = '*';
		pattern [5][9] = '*';
		pattern [5][10] = '*';
		pattern [6][4] = '*';
		pattern [6][5] = '*';
		pattern [6][6] = '*';
		pattern [6][7] = '*';
		pattern [6][8] = '*';
		pattern [6][9] = '*';
		pattern [6][10] = '*';
		pattern [7][4] = '*';
		pattern [7][5] = '*';
		pattern [7][6] = '*';
		pattern [7][7] = '*';
		pattern [7][8] = '*';
		pattern [7][9] = '*';
		pattern [7][10] = '*';
		pattern [8][5] = '*';
		pattern [8][6] = '*';
		pattern [8][7] = '*';
		pattern [8][8] = '*';
		pattern [8][9] = '*';
		pattern [9][6] = '*';
		pattern [9][7] = '*';
		pattern [9][8] = '*';
		pattern [10][7] = '*';
	}
}

void displayCurrentBoard ( char currentBoard[][WIDTH], int nrows, int ncols  )
{
	int col, row;
	double pct, liveCells;
	char contin;
	
	
	cout << endl << endl;
	for (row = 1; row < nrows; ++row) {
		
		for ( col = 1 ; col < ncols; ++ col)
		 	cout << currentBoard[row][col];
		cout << endl;
	}
	
	liveCells = countLiveCells (currentBoard, nrows, ncols);			// counts live cells for output info
	
	cout << "Rows: " << nrows << ", ";
	cout << "Columns: " << ncols << ", ";
	cout << "Live: " << liveCells << ", ";
	pct = liveCells / ( row  + col );
	cout << "Pct: "<< pct <<  endl;
	cout << "Type any letter and press enter to continue: ";
	cin >> contin;												// allows game Menu to continue
	cout << endl << endl;
	
}

void restart (char initBoard [] [WIDTH], char currentBoard [] [WIDTH])
{
	arrayCopy(currentBoard, initBoard);
	cout << endl << endl << endl << endl << endl;
	cout << "Reset Board Complete" << endl;
}

void playGame (char currentBoard [] [WIDTH], char nextGenBoard [][WIDTH], int nrows, int ncols )
{
	int i, turns;
	do{
	cout << "How Many Turns?: ";
	cin >> turns;
		if (turns <= 0) {
			cout << "Error: Invalid Entry. Number must be positive" << endl << endl;
		}
	}while (turns <= 0);
	
	displayCurrentBoard(currentBoard, nrows, ncols);
	
	for (i = 0; i < turns; ++i) {
		
		computeNextGeneration(currentBoard, nextGenBoard, nrows, ncols);
		displayCurrentBoard( nextGenBoard, nrows, ncols);
		arrayCopy(currentBoard, nextGenBoard);
		
	}
}


void computeNextGeneration ( char currentBoard [][WIDTH], char nextGenBoard [][WIDTH], int nrows, int ncols )
{

	int row, columns, neighbor;
	
	arrayCopy(nextGenBoard, currentBoard);
	
	for (row = 0; row < nrows; ++row) {
		for (columns = 0; columns < ncols; ++columns) {
			
			neighbor = countLiveNeighbor(nextGenBoard, row, columns);
			
			if (nextGenBoard[row][columns] == '*') {
		
			
			if (neighbor < 2){
				nextGenBoard[row][columns] = ' ';
			} // rule 1. underpopulation
				
				else if (neighbor > 3){
					nextGenBoard [row][columns] = ' ';
				} // rule 2. overcrowding
					
				else if ( neighbor == 2 || neighbor == 3){
					nextGenBoard[row][columns] = '*';
				} // rule 3. live Cell continues on to next generation
			} // checks for Rules 1-3	
			
			else if (currentBoard [row][columns] == ' ') {
				if (neighbor == 3)
					nextGenBoard [row][columns] = '*';
			}			// checks for Rule 4 dead cell becomes live cell

		}
	}

}

int countLiveNeighbor ( char currentBoard [] [WIDTH], int row, int columns )
{
	int liveNeighbor;

	liveNeighbor = 0;
			
				
				if (currentBoard [row] [columns + 1] == '*'){
					liveNeighbor = liveNeighbor + 1;
				}	// checks right
				
				if (currentBoard [row -1] [columns + 1] == '*') {
					liveNeighbor = liveNeighbor + 1;
				} // checks upper right
	
				if (currentBoard [row + 1] [columns + 1] == '*'){
					liveNeighbor = liveNeighbor + 1;
				} // checks lower right
	
				if (currentBoard [row] [columns -1] == '*'){
						liveNeighbor = liveNeighbor + 1;
				} // checks left
	
				if (currentBoard [row -1] [columns - 1] == '*') {
		liveNeighbor = liveNeighbor + 1;
	} // checks upper left
				
				if (currentBoard [row + 1] [columns - 1] == '*') {
		liveNeighbor = liveNeighbor + 1;
	} // checks lower left
	
				if (currentBoard [row -1] [columns] == '*'){
						liveNeighbor = liveNeighbor + 1;
					} // checks top
	
				if (currentBoard [row + 1] [columns] == '*'){
						liveNeighbor = liveNeighbor + 1;
					} // checks bottom
					
	return liveNeighbor;
} // checks all 8 neighbors of current board row and column.


void arrayCopy (char dest [][WIDTH], char source[] [WIDTH] )
{
	int i, ix;
	for (i = 0; i < HEIGHT; ++i)
	{
		for (ix = 0; ix < WIDTH; ++ix) {
			dest[i][ix] = source[i][ix];
		}
	}
	
}

int countLiveCells ( char currentBoard[][WIDTH], int nrows, int ncols )
{
	int row, columns, liveCells;
	liveCells = 0;
	for (row = 0; row < nrows; ++row) {
		for (columns = 0; columns < ncols; ++columns) {
			if (currentBoard [row][columns] == '*') {
				liveCells = liveCells + 1;
			}
		}
	}
	return liveCells;
}

		
void gameMenuDisplay ( int &gameMenuChoice )
{
	cout << "(1) Create Spaces Between Spaces" << endl;
	cout << "(2) Restart the Game" << endl;
	cout << "(3) Display the Current Board" << endl;
	cout << "(4) Enter a New Board" << endl;
	cout << "(5) Stop the Program" << endl;
	
	do{
	cout << "Please Enter a selection: ";
	cin >> gameMenuChoice;
		if (gameMenuChoice > 5) {
			cout << "Error: Choice must be from (1-5)" << endl;
		}
	}while (gameMenuChoice > 5);
}

	
