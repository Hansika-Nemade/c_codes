/**
* @file:   game.c
* @brief:  Computer vs Opponent tic tac toe game with MinMax Algorithm 
* @author: Hansika Nemade(hansikanemade@gmail.com)
* @date:   07/10/2023 (Saturday)
*/


// Headers
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define    COMPUTER            1
#define    OPPONENT            2

#define    COMPUTERSIGN       'O'
#define    OPPONENTSIGN       'X'

#define    SIDE                3      // length of board


// functions declarations
void TicTacToe(int Turn);
int* BestMove(char board[SIDE][SIDE], int MoveIndex);
int MinMax(char board[SIDE][SIDE], int depth, bool IsComp);

void InitializeBoard(char board[SIDE][SIDE]);

void BoardInfo(void);

bool IsGameOver(char board[SIDE][SIDE]);
bool RowCheck(char board[SIDE][SIDE]);
bool ColumnCheck(char board[SIDE][SIDE]);
bool DiagonalCheck(char board[SIDE][SIDE]);

void Winner(int winner);

void PrintBoard(char board[SIDE][SIDE]);


// ENTRY POINT OF MAIN FUNCTION
int main(void)
{
    printf("\n-------------------------------------------------------------------\n");
	printf("\t\t\t Tic-Tac-Toe\n"); 
	printf("-------------------------------------------------------------------\n\n");

    char play = ' ';

    // loop will continues until user terminate it
    while(play != 'y')
    {
        char choice;
	 	printf("Do you want to start first?(y/n) : ");
	 	scanf(" %c", &choice);

		if(choice=='n')
			TicTacToe(COMPUTER);    // if user want Computer to play first
		else if(choice=='y')
			TicTacToe(OPPONENT);    // if user want to play first
		else
			printf("Invalid choice\n"); 
        
		printf("\nDo you want to quit(y/n) : ");
       	scanf(" %c", &play);
    }

    return 0;
}

/*
*  FUNCTION NAME : TicTacToe()
*                      this function starts playing game if its Opponent turn it will take input from user and if its Computer turn
*                       it will find best move and update board. after game over it will tell result.
* 
*  PARAMETERS :  
*                1) int :  it takes an integer which tell who will play Computer or Opponent.
* 
*  RETURNS :
*                void :
*/

void TicTacToe(int Turn)
{
    char Board[SIDE][SIDE];            // 3x3 grid stored in two dimensional array
    int  MoveIndex = 0;

    int X = -1, Y = -1;     // it will represents position on the board

    int  BoardIndex;        //it represents the exact position on the board
    int* index = NULL;     // it will hold indices of best move

    int position = -1;      // it will store opponent move

    InitializeBoard(Board);       
    BoardInfo();

    //   loop it will terminate when  game over  or all the cells get filled
    while(IsGameOver(Board) == false && MoveIndex != (SIDE*SIDE))
    {
        // if computer's turn best move is calculated and then update it on board
       if(Turn == COMPUTER)
       {
          index = BestMove(Board, MoveIndex);
          Board[index[0]][index[1]]  = COMPUTERSIGN;

          BoardIndex = (((index[0]) * 3) + index[1]) + 1;     // which cell on the board 

          printf("COMPUTER has put a %c in cell %d\n\n", COMPUTERSIGN, BoardIndex);
          PrintBoard(Board);

          MoveIndex++;
          Turn = OPPONENT;
          free(index);    //
       } 
       else if(Turn == OPPONENT)
       {
          printf("You can insert in the following positions : ");

          // nested loop for printing which the cells which are not filled.
          // it will easy to play for opponent
          for(int le = 0; le < SIDE; le++)
          {
            for(int le2 = 0; le2 < SIDE; le2++)
            {
                if(Board[le][le2] == ' ')
                {
                    printf("%d ", (le*3 + le2) + 1);
                }
            }
          }

          // taking cell no. from opponent
          printf("\n\nEnter the position = ");
		  scanf("%d", &position);

          // converting cell no. to position on board
          X = (position - 1) / SIDE;
          Y = (position - 1) % SIDE;

          if(Board[X][Y] == ' ' && position < 10 && position > 0)
          {
            Board[X][Y] = OPPONENTSIGN; 
			printf ("\nHUMAN has put a %c in cell %d\n\n", OPPONENTSIGN, position); 
			PrintBoard(Board); 
			MoveIndex ++; 
			Turn = COMPUTER;
          }
          else if(Board[X][Y] != ' ' && position < 10 && position > 0)
          {
            printf("\nPosition is occupied, select any one place from the available places\n\n");
          } 
          else
          {
            printf("Invalid position\n");
          }
       }

    }

    // checking   if game is over or board is filled
    if (IsGameOver(Board) == false && MoveIndex == SIDE * SIDE) 
		printf("It's a draw\n"); 
	else
	{ 
		// Toggling the user to declare the actual winner 
		if (Turn == COMPUTER) 
			Turn = OPPONENT; 
		else if (Turn == OPPONENT) 
			Turn = COMPUTER; 
		
		Winner(Turn);    // declaring winner
	}

    return;
}


/*
*  FUNCTION NAME : BestMove()
*                      it will iterate board and calculate the score for each empty cell and stores the index in X and Y.
*                      considering the score which is large and that indices were return as best move.
*                      basically it will return the best optimal move.
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
*                2) int       :   this integer help in deciding the range og depth
* 
*  RETURNS :
*                int* : it will return an address of array which holds the indices of best optimal move.
*/
int* BestMove(char board[SIDE][SIDE], int MoveIndex)
{
    int X = -1, Y = -1;
    int score = 0, best = -1000;
    int* bestmove = (int*)malloc(sizeof(int) * 2);

    // calculating score of the moves which are empty
    // iterating the board
    for(int le = 0; le < SIDE; le++)
    {
        for(int le2 = 0; le2 < SIDE; le2++)
        {
            if(board[le][le2] == ' ')
            {
                board[le][le2] = COMPUTERSIGN;
                // calculating score for that particular move
                score = MinMax(board, MoveIndex+1, false);
                board[le][le2] = ' ';

                // storing best score and position 
                if(score > best)
                {
                    best = score;
                    X = le;
                    Y = le2;
                }
            }
        }
    }

    // storing position in array
    bestmove[0] = X;
    bestmove[1] = Y;

    return bestmove;
}


/*
*  FUNCTION NAME : MinMax()
*                      It considers all the possible ways the game can go and returns the score of that particular move.
*                      it is a recursive function and it explore tree by DFS algorithm  
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
*                2) int depth :  takes an integer which tells the depth of tree
*                3) isMax     :  which tells that we have to consider maximized score of minimized score
* 
*  RETURNS :
*                int : returns the score for that particular move.
*                      if OPPONENT wins it will return -1
*                      if COMPUTER Wins it will return 1
*                      if it's Draw then it will return 0
*/
int MinMax(char board[SIDE][SIDE], int depth, bool IsComp)      // IsComp means turn of Computer is or not
{
    int score = 0;
    int best = 0;

    if(IsGameOver(board) == true)
    {
        if(IsComp == true)
           return -1;
        else if(IsComp == false)
           return 1;
    }
    else
    {
       if(depth < 9)           // depth limit
       {
           if(IsComp == true)
           {
              best = -1000;
              // iterating board 
              for(int le = 0; le < SIDE; le++)
              {
                for(int le2 = 0; le2 < SIDE; le2++)
                {
                    if(board[le][le2] == ' ')
                    {
                        board[le][le2] = COMPUTERSIGN;
                        score = MinMax(board, depth+1, !IsComp);
                        board[le][le2] = ' ';

                        // storing maximum score
                        if(score > best)
                        {
                            best = score;
                        }
                    }
                }
              }

              return best;
           }
           else
           {
              best = 1000;
              // iterating board
              for(int le = 0; le < SIDE; le++)
              {
                for(int le2 = 0; le2 < SIDE; le2++)
                {
                    if(board[le][le2] == ' ')
                    {
                        board[le][le2] = OPPONENTSIGN;
                        score = MinMax(board, depth+1, !IsComp);
                        board[le][le2] = ' ';

                        // storing minimum score
                        if(score < best)
                        {
                            best = score;
                        }
                    }
                }
              }

              return best;
           }
       }
       else
       {
         return 0;     // if depth exceed return 0
       }
    }

    return 0;
}




/*
*  FUNCTION NAME : ShowBoard()
*                      prints board to show the status of board
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
* 
*  RETURNS :
*                void :
*/
void PrintBoard(char board[SIDE][SIDE])
{
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);

    return;
}


/*
*  FUNCTION NAME : BoardInfo()
*                      it prints the instructions and positions of board for opponent
* 
*  PARAMETERS :  
*                void :
* 
*  RETURNS :
*                void :
*/
void BoardInfo(void)
{
    printf("\nChoose a cell numbered from 1 to 9 as below and play\n\n"); 
	
	printf("\t\t\t 1 | 2 | 3 \n"); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t 4 | 5 | 6 \n"); 
	printf("\t\t\t-----------\n"); 
	printf("\t\t\t 7 | 8 | 9 \n\n");

    return;
}

/*
*  FUNCTION NAME : InitializeBoard()
*                     it will initialize each cell of the board to NULL.
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
* 
*  RETURNS :
*                void :
*/
void InitializeBoard(char board[SIDE][SIDE])
{
    for(int le = 0; le < SIDE ; le++)
    {
        for(int le2 = 0; le2 < SIDE; le2++)
        {
            board[le][le2] = ' ';
        }
    }

    return;
}


/*
*  FUNCTION NAME : Winner()
*                      prints board to show the status of board
* 
*  PARAMETERS :  
*                1) int :  it will takes integer that tells who wins the game and declares the winner.
* 
*  RETURNS :
*                void :
*/
void Winner(int winner)
{
    if(winner == OPPONENT)
       printf("YOU has Won\n");
    else
       printf("COMPUTER has Won\n");

    return;
}


/*
*  FUNCTION NAME : IsGameOver()
*                      it will check weather game is over or not by checking the status of the board
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
* 
*  RETURNS :
*                bool :  it returns true if game over otherwise return false
*/
bool IsGameOver(char board[SIDE][SIDE])
{
    if(RowCheck(board) || ColumnCheck(board) || DiagonalCheck(board) )
        return(true);

    return(false);
}


/*
*  FUNCTION NAME : RowCheck()
*                      it will iterate the rows and check weather the 3 cells of a row contains same symbol
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
* 
*  RETURNS :
*                bool :  if 3 cells of a row contains same symbol but not null then it returns true otherwise return false
*/
bool RowCheck(char board[SIDE][SIDE])
{
    // loop will iterate row 
   for(int le = 0; le < SIDE; le++)
   {
        if(board[le][0] == board[le][1] && board[le][1] == board[le][2] && board[le][2] != ' ')    //
            return(true);
   }

   return(false);
}


/*
*  FUNCTION NAME : ColumnCheck()
*                      it will iterate the columns and check weather the 3 cells of a column contains same symbol
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
* 
*  RETURNS :
*                bool : if 3 cells of a column contains same symbol but not null then it returns true otherwise return false
*/
bool ColumnCheck(char board[SIDE][SIDE])
{
    // loop will iterate column
    for(int le = 0; le < SIDE; le++)
    {
        if(board[0][le] == board[1][le] && board[1][le] == board[2][le] && board[2][le] != ' ')   //
            return(true);
    }

    return(false);
}


/*
*  FUNCTION NAME : DiagonalCheck()
*                      it will check the rows weather the 3 cells  contains same symbol
* 
*  PARAMETERS :  
*                1) char [][] :  takes an two dimensional array which stores the board's status
* 
*  RETURNS :
*                bool : if diagonal 3 cells contains same symbol but not null then it returns true otherwise return false
*/
bool DiagonalCheck(char board[SIDE][SIDE])
{
    //checking diagonal cells

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
        return(true);

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
        return(true);

    return(false);
}



