//Author: Kyle Frudakis
//Title: Sudoku Solver
//Description: I have grown tired of spending too much time on sudoku, so
//              I have create a program that will solve sudoku puzzles for me on a 9x9 scale.
//              Input 0 for empty slots on the sudoku board

//Sudoku Rules:
//  1. A number n can only appear once in each column
//  2. A number n can only appear once in each row
//  3. A number n can only appear once in each 3x3 box
import java.util.Scanner;

public class Sudoku_Solver {

    private static final int SIZE = 9; //constant for 9x9 sudoku table
    public static void main(String[] args) { //[row][column]

        //user input board
        int [][] board = CreateBoard();
        
        //test board
        /*int [][] board = {
            {8,0,0,0,0,9,0,0,5},
            {0,4,0,0,0,0,7,2,6},
            {0,0,0,0,3,0,8,0,0},
            {0,0,0,0,4,7,0,0,0},
            {0,3,0,0,5,0,0,0,0},
            {0,0,4,0,9,0,5,3,0},
            {0,0,0,0,7,0,0,0,0},
            {9,1,0,0,2,0,0,8,0},
            {0,2,0,0,0,5,9,0,0}
        };*/
        System.out.println("Puzzle Before Solving: ");
        printBoard(board);

        if(SolvingWizard(board)) {
            System.out.println("Successfully solved!\n\n");
        } else {
            System.out.println("Unsolvable Puzzle!");
        }
    
        printBoard(board);
    }

    private static int[][] CreateBoard() {
        //This function will allow the user to input the given board they are trying to solve
        //basically filling up a 2d array
        int[][] table;
        table = new int[9][9];
        Scanner scan = new Scanner(System.in);
        int number;
        for(int row = 0; row < SIZE; row++) {
            for(int column = 0; column < SIZE; column++) {
                System.out.println("Num. for position [" + row + "][" + column + "]: ");
                number = scan.nextInt();
                table[row][column] = number;
            }
        }
        return table;
    }

    private static void printBoard(int[][] board) {
        //print out the contents of the board
        String str = "-----------";
        for(int i = 0; i < 3; i++) {
            str += str;
        }
        for(int row = 0; row < SIZE; row++) {
            if(row % 3 == 0 && row != 0) {
                System.out.println(str);
            }
            for(int column = 0; column < SIZE; column++) {
                if(column % 1 == 0 && column != 0) {
                    System.out.print("\t");
                }
                if(column % 3 == 0 && column != 0) {
                    System.out.print("|\t");
                }
                System.out.print(board[row][column]);
            }
            System.out.println();
        }
    }

    //helper functions to see if a number exist in a row, column, or box
    private static boolean NumInRow(int[][] board, int num, int row) {
        //This function checks if num exist in a row on the board
        for(int i = 0; i < SIZE; i ++) {
            if(board[row][i] == num ) {
                return true;
            }
        }
        return false;
    }

    private static boolean NumInColumn(int[][] board, int num, int column) {
        //This function checks if num exist in a column on the board
        for(int i = 0; i < SIZE; i++) {
            if(board[i][column] == num) {
                return true;
            }
        }
        return false;
    }
    
    private static boolean NumInBox(int[][] board, int num, int row, int column) {
        //This function checks if num exist withing its local 3x3 box
        int localRow = row - row % 3; //gets us to the top row of local box
        int localColumn = column - column % 3; //gets us to far left of local box
        //together, these get us to the top left of local box, now we can iterate through the box
        //EX) [0][3]
        for(int i = localRow; i < localRow + 3; i++) { //row
            for(int j = localColumn; j < localColumn + 3; j++) { //column
                if(board[i][j] == num) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean ProperLocation(int[][] board, int num, int row, int column) {
        return !NumInRow(board, num, row) &&
            !NumInColumn(board, num, column) &&
            !NumInBox(board, num, row, column);
    }


    private static boolean SolvingWizard(int[][] board) {
        //This is the algorithm that will solve the sudoku puzzle!
        for(int row = 0; row < SIZE; row++) {
            for(int column = 0; column < SIZE; column++) {
                //iterating through the whole board
                if(board[row][column] == 0) {
                    //check for valid inputs into empty slot
                    for(int trynum = 1; trynum <= SIZE; trynum++) {
                        if(ProperLocation(board, trynum, row, column)) {
                            board[row][column] = trynum;

                            //recursive call
                            if(SolvingWizard(board)) {
                                return true; //this means we have successfully completed the board! bc everything was true
                            }
                            else {
                                board[row][column] = 0;
                                //couldn't solve board with previous number given, so get rid of it.
                            }
                        }
                    }
                    return false; //for when we try all the numbers and they arent valid for a spot
                }
            }
        }
        return true; //if we have exited the table, it means we have solved the table!
    }

}
