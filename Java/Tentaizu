//Nathaell Avril Leman
//Started on 01/26/2022
//Finished on 02/04/2022
//Solution to Tentaizu problem for P2 COP3503.

import java.util.*;
public class tentaizu{

    static Scanner stdin = new Scanner(System.in);
    private String[][] board;
    private String tile;
    private int n = 7;
    private int totalTiles = (n*n);
    public static void main(String args[]){
        int numCases = stdin.nextInt();
        for(int loop = 1; loop <= numCases; loop++){
            System.out.println("Tentaizu #"+ loop);
            tentaizu game = new tentaizu(numCases);
            game.starmap(0, 0);

            // numCases = stdin.nextInt();
        }
    }

    //Sets up our Tentaizu board.
    public tentaizu(int numCases){
        board = new String[n][n];

        //Initializes the board with the clues.
        for(int y = 0; y < n; y++){        
            if(stdin.hasNext()){    //Will keep taking input until EOF...basically.
                tile = stdin.next();//Since there are no whitespace in between, we have to take in one character at a time.
            }
            for(int x = 0; x < tile.length() && tile.length() == n; x++){
                char a = tile.charAt(x);
                
                //Return true if the char we scanned has a number within it.
                if(isNumber(a)){ 
                    board[x][y] = Character.toString(a);
                }
                else{    //The tile is empty!
                    board[x][y] = ".";
                }
            }
        }
        System.out.println();
    }


    //Our most hardworking function, it tries to solve the given board recursively.
    public boolean starmap(int location, int numStars){

        //If the amount of stars has reached ten, do one last check to see if the board as a whole is valid.
        if(numStars == 10){
            if(!finalCheck()){
                return false;
            }
            //It's valid! Hooray!! We can finally print now.
            printSol();
            return true;
        }

        //The program has tirelessly worked its way to the end of the board.
        if(location == totalTiles)
            return false;

        //Traverses the whole board recursively.
        //Once it reaches the end, it'll basically work the board backwards.
        starmap(location+1, numStars);

        //Checks to see if a star placement on this tile is legal.
        if(isSafe(location/n, location%n) == true){
            board[location/n][location%n] = "*";
            starmap(location+1, numStars+1);
            board[location/n][location%n] = ".";    
        }
        return false;
    }

    //Does the final round of checking.
    public boolean finalCheck(){
        //Much easier to check since all we have to do is
        //go to each number tile and see if the amount of stars line up.
        for(int i = 0; i < totalTiles; i++){
            //Not a number! SKIP.
            if(!isNumber(board[i/n][i%n].charAt(0))){
                continue;
            }
            //hey its a number, SHOW ME THE STARS!
            if(totalStars(i/n,i%n) != Integer.parseInt(board[i/n][i%n])){
                return false;
            }
        }
        return true;
    }

    //Checks the 8 adjacent tiles for numbers tiles. 
    //Returns true if there are no number tiles or if the stars around a number tile isn't equal to itself.
    public boolean isSafe(int row, int col){

        //Quick check just in case this tile we are trying to place a star in is actually a number tile.
        if(isNumber(board[row][col].charAt(0))){
            return false;
        }
        
        //Checks the surrounding tiles starting from the right, going anti-clockwise.
        //Better chances it will find a number faster since we are working from the bottom up.
        if(checkIfNumber(row, col+1)){
            if(totalStars(row, col+1) >= Integer.parseInt(board[row][col+1])){  
                return false;
            }
        }
        if(checkIfNumber(row-1, col+1)){
            if(totalStars(row-1, col+1) >= Integer.parseInt(board[row-1][col+1])){  
                return false;
            }
        }
        if(checkIfNumber(row-1, col)){
            if(totalStars(row-1, col) >= Integer.parseInt(board[row-1][col])){  
                return false;
            }
        }
        if(checkIfNumber(row-1, col-1)){
            if(totalStars(row-1, col-1) >= Integer.parseInt(board[row-1][col-1])){  
                return false;
            }
        }
        if(checkIfNumber(row, col-1)){
            if(totalStars(row, col-1) >= Integer.parseInt(board[row][col-1])){  
                return false;
            }
        }
        if(checkIfNumber(row+1, col-1)) {
            if(totalStars(row+1, col-1) >= Integer.parseInt(board[row+1][col-1])){  
                return false;
            }
        }
        if(checkIfNumber(row+1, col)){
            if(totalStars(row+1, col) >= Integer.parseInt(board[row+1][col])){  
                return false;
            }
        }
        if(checkIfNumber(row+1, col+1)){
            if(totalStars(row+1, col+1) >= Integer.parseInt(board[row+1][col+1])){  
                return false;
            }
        }
        return true;
    }

    //Returns the amount of stars found adjacent to the tile that is passed in.
    public int totalStars(int row, int col){
        int retval = 0;

        retval += checkStar(row, col+1);
        retval += checkStar(row-1, col+1);
        retval += checkStar(row-1, col);
        retval += checkStar(row-1, col-1);
        retval += checkStar(row, col-1);
        retval += checkStar(row+1, col-1);
        retval += checkStar(row+1, col);
        retval += checkStar(row+1, col+1);
        return retval;
    }

    //Simple function to check if a tile is a star or not.
    //Returns 1 if there is a star present.
    public int checkStar(int row, int col){
        if(isOutOfBounds(row,col))
            return 0;

        if(board[row][col] != "*")
            return 0;
            
        return 1;
    }

    //Simple function to check if a tile is a number or not.
    //Because I made this too convoluted for myself :)
    public boolean checkIfNumber(int row, int col){
        //Returns false if these coordinates would go outside of the board.
        if(isOutOfBounds(row,col))
            return false;

        //Returns false if it isn't a number.
        if(!Character.isDigit(board[row][col].charAt(0)))
            return false;
            
        return true;
    }

    //Out of bounds function...not much to say, sorry.
    public boolean isOutOfBounds(int row, int col){
        if(row < 0 || row >= n || col < 0 || col >= n){
            return true;
        }
        return false;
    }

    public boolean isNumber(char a){
        if(Character.isDigit(a))
            return true;
        return false;
    }
    
    //Prints out the board once it is finished.
    public void printSol(){
         for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                //For the nice thing we call formatting.
                if(x == 6)
                    System.out.println(board[x][y]);
                else System.out.print(board[x][y]);
            }
        }
        //Spaced out for other boards prints.
        System.out.println();
    }
}
