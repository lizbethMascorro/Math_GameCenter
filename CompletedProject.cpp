#include <iostream>            // include cin and cout
#include <iomanip>            // include formatting functions
#include <cmath>            // include math functions
#include <ctime>            // include time functions
#include <string>            // include string functions
using namespace std;            // no need for std::

string DisplayIntro();            // function declaration
int DisplayMenu();            // function declaration
void DisplayWelcome(string &userName);            // function declaration
int PlayPractice();            // function declaration
int PlayHang();            // function declaration
int displayIntructions(int game);            // function declaration
void displayHang(int fails);            // function declaration
int PlayTTT();            // function declaration
void displayTTT(char board[]);            // function declaration
int isGameOver(char board[]);             // function declaration
bool isCompleteBoard(char board[]);            // function declaration
bool equationXint();            // function declaration
bool equationYint();            // function declaration
bool tableQuestion(int placeNum);            // function declaration

// declare main()
int main(){            
    // declare and initialize string with return of function
    string userName = DisplayIntro();            
    
    // call DisplayWelcome() with string as arg
    DisplayWelcome(userName);
    
    // declare and initialize int with return of function
    int option = DisplayMenu();
    // while loop, loops until user ends game
    while(option == 1 or option == 2 or option == 3 or option == 20){
        if(option == 20){           // if returned from game instructions
            // output border
            cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
            option = DisplayMenu();         // save return value into int
        }   // end if
        if(option == 1){    // if input 1 - TicTacToe
            option = PlayTTT();         // save return value into int
        }   // end if
        else if(option == 2){    // else if input 2 - Hangman
            option = PlayHang();         // save return value into int
        }   // end else if
        else if(option == 3){    // else if input 3 - Math Practice
            option = PlayPractice();         // save return value into int
        }   // end else if
    }   // end while loop
    
    if(option == 4){    // if input is 4 - exit game
        // output goodbye
        cout << "                   Goodbye " << userName << "!" << endl;
    }   // end if
    
    return 0;    // return 0 if ran sucessfully
}   // end main()

int PlayTTT(){  
    // output title
    cout << "                   Tic-Tac-Toe\n                  -------------" << endl << endl;
    int option = displayIntructions(1);     //  save function return into int
    if(option == 2){        // if int is 2 
        return 20;      // return 20 to main()
    }   // end if
    
    // array of chars for board
    char gameBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int playerNum = 1;      // declare and initialize int
    char key;       // declare char
    int choice;     // declare int
    
    while(!isCompleteBoard(gameBoard)){     // will run until board game is full
        cout << "---------------------------" << endl << endl;  // output border
        displayTTT(gameBoard);  // call function with array of chars
        cout << endl;       // output new line
        
        if (playerNum % 2 == 1) { // if playerNum is odd
            playerNum = 1; // odd - player 1
        }   // end if
        else {  // else playerNum is even
            playerNum = 2;  // even - player 2
        }// end else
        
        cout << "Player " << playerNum << ": ";     // output playerNum
        cin >> choice;      // save input into int
        cout << endl;   // output new line
        if(choice == 1234)  // if input is 1234
            return 20;      // return 20 to main()
        
        if(playerNum == 1){     // if player 1
            key = 'X';      // key is X
        }   // end if
        else{     // else player 2
            key = 'O';      // key is O
        }   // end else
        
        bool invalidMove = true;     // initialize and declare bool
        while(invalidMove){     // while bool is true - choice is invalid
            if (choice == 1 && gameBoard[0] == '1') { // if int is 1 and spot is empty
                gameBoard[0] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(equationXint())  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end if
            else if (choice == 2 && gameBoard[1] == '2') { // if int is 2 and spot is empty
                gameBoard[1] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(equationXint())  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 3 && gameBoard[2] == '3') { // if int is 3 and spot is empty
                gameBoard[2] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(equationXint())  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 4 && gameBoard[3] == '4') { // if int is 4 and spot is empty
                gameBoard[3] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(equationYint())  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 5 && gameBoard[4] == '5') { // if int is 5 and spot is empty
                gameBoard[4] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(equationYint())  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 6 && gameBoard[5] == '6') { // if int is 6 and spot is empty
                gameBoard[5] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(equationYint())  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 7 && gameBoard[6] == '7') { // if int is 7 and spot is empty
                gameBoard[6] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(tableQuestion(choice))  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 8 && gameBoard[7] == '8') { // if int is 8 and spot is empty
                gameBoard[7] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(tableQuestion(choice))  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else if (choice == 9 && gameBoard[8] == '9'){ // if int is 9 and spot is empty
                gameBoard[8] = key; // replace key with num (spot now taken)
                invalidMove = false;// make bool false, ends while loop(valid move)
                if(tableQuestion(choice))  // call function, if return value is true
                    return 20;  // return 20 to main()
            }// end else if
            else {  // else spot is taken
                // output warning invalid move
                cout << "Invalid move. Please try again." << endl; 
                cout << "Player " << playerNum << ": "; // prompt for input spot 
                cin >> choice;  // save input in int
                if(choice == 1234)  // if input 1234
                    return 20;  // return 20 to main()
            }// end else
        }// end while loop
        
        if(isGameOver(gameBoard) == 2) {// if return value from function is 2
            displayTTT(gameBoard);  // call function - display board
            cout << "Player " << playerNum << " wins!" << endl; // output winner
            return 20;  // return 20 to main()
        }   // end if 
        playerNum++;    // increase playerNum by 1
    }   // end while loop

    if(isGameOver(gameBoard) == 3){ // if return value from function is 3
        displayTTT(gameBoard);  // call function - display board
        cout << "Tie!" << endl; // output tie
        return 20;  // return 20 to main()
    }// end if 
    
    return 20;  // return 20 to main()
} //end PlayTTT()

int PlayHang(){
    // output game title
    cout << "                       Hangman\n                      ---------" << endl << endl;
    int option = displayIntructions(2);      //  save function return into int
    
    if(option == 2){        // if int is 2 
        return 20;      // return 20 to main()
    }   // end if
    
    // declare and initialize strings
    string secretW = "slope", displayW = "-----", lettersGuessed;
    char letter;    // declare char 
    int incorrect = 0, correct = 0, index;  // declare and initialize ints
    
    // while loop- loops until incorrect = 6, correct = word size
    while(incorrect < 6 and correct < secretW.size()){ 
        cout << "---------------------------" << endl;  // output border
        cout << "          WORD #1          " << endl << endl;  // output wordNum
        displayHang(incorrect); // call function to display hang
        if(incorrect == 3){ // if 3 times incorrect
            // output hint
            cout << " Hint: The steepness of a\n line (rise/run)" << endl << endl;
            incorrect = 0;  // initialize incorrect to 0
        }   // end if
        cout << "Word #1: " << displayW << endl;    // output dashes
        cout << "Letter: "; // prompt for letter
        cin >> letter;  // save input into char
        if(letter == 'E')   // if input E
            return 20;  // return 20 to main()
        
        if(lettersGuessed.find(letter,0) == -1){    // if letter hasnt been inputted before
            index = secretW.find(letter, 0);    // look for letter in secret word, return index
            if(index == -1){    // if letter isnt in secret word
                incorrect++;    // add 1 to incorrect
            }   // end if
            else{   // else letter is in word
                correct++;  // add 1 to correct
            }
            // while loop- loops until it searches for letter in entire secret word
            while(index < secretW.size() and index != -1){
                string charToString;    // declare string
                charToString.push_back(letter); // add letter to empty string
                displayW.replace(index, 1, charToString); // replace string with dash
                index = secretW.find(letter, index+1); // look for letter after its first location
            }   // end while loop
            lettersGuessed.push_back(letter);   // add letter to array of letters guessed
        }// end if
        else{   // else - letter already guessed before
            cout << "** INVALID **" << endl;    // output warning
            // output warning
            cout << " - You've already entered " << letter << "." << endl;
        }// end else
        cout << endl;   // output newline
    }   // end while loop
    
    if(incorrect == 6){ // if incorrect is 6
        cout << "---------------------------" << endl << endl;//output border
        displayHang(incorrect); // call function to display
        cout << "Failed to guess to word!"; // output fail msg
        return 20;  // return 20 to main()
    }// end if
    else{   // else - guess word
        cout << "Fantastic Job!" << endl;   // output good job
        cout << "Word#1: " << displayW << endl; // output word
        cout << "        " << "-----" << endl;  // output underline
    }// end else
    
    secretW = "intercept";  //initizlize secret word
    displayW = "---------"; // initialize dashes
    lettersGuessed.resize(0);   // clear array
    incorrect = 0;  // clear incorrect
    correct = 0;    // clear correct
    
    // while loop- loops until incorrect = 6, correct = uniqueLettersInWord
    while(incorrect < 6 and correct < 7){
        cout << "---------------------------" << endl;  // output border
        cout << "          WORD #2          " << endl << endl;  // output title
        displayHang(incorrect); // call function to display
        if(incorrect == 3){ // if incorrect is 3
            cout << " Hint: Point where a line\n"   // output hint
                << "intercepts with axes (x-int/y-int)" << endl << endl;//hint
            incorrect = 0;// clear incorrect
        }// end if 
        
        cout << "Word #2: " << displayW << endl;// output dashes
        cout << "Letter: "; // prompt for guess
        cin >> letter;  // save input into char
        if(letter == 'E')   // if input is E
            return 20;  // return 20 to main()
        
        if(lettersGuessed.find(letter,0) == -1){    // if letter hasnt been inputted before
            index = secretW.find(letter, 0);    // look for letter in secret word, return index
            if(index == -1){    // if letter isnt in secret word
                incorrect++;    // add 1 to incorrect
            }   // end if
            else{   // else letter is in word
                correct++;  // add 1 to correct
            }
            // while loop- loops until it searches for letter in entire secret word
            while(index < secretW.size() and index != -1){
                string charToString;    // declare string
                charToString.push_back(letter); // add letter to empty string
                displayW.replace(index, 1, charToString); // replace string with dash
                index = secretW.find(letter, index+1); // look for letter after its first location
            }   // end while loop
            lettersGuessed.push_back(letter);   // add letter to array of letters guessed
        }// end if
        else{   // else - letter already guessed before
            cout << "** INVALID **" << endl;    // output warning
            // output warning
            cout << " - You've already entered " << letter << "." << endl;
        }// end else
        cout << endl;   // output newline
    } // end while loop
    
    if(incorrect == 6){ // if incorrect is 6
        cout << "---------------------------" << endl << endl;//output border
        displayHang(incorrect); // call function to display
        cout << "Failed to guess to word!"; // output fail msg
        return 20;  // return 20 to main()
    }// end if
    else{   // else - guess word
        cout << "Fantastic Job!" << endl;   // output good job
        cout << "Word#1: " << displayW << endl; // output word
        cout << "        " << "-----" << endl;  // output underline
    }// end else
    
    return 20; // return 20 to main()
}// end PlayHang()

int PlayPractice(){
    // output game title
    cout << "                    Math Practice\n                   ---------------" << endl << endl;

    time_t start, end, totalTime; // variables for time
    time(&start); // time at start
    
    // declare and initialize ints
    int a1 = -14, a2 = -4, a3 = -4, a4 = 17, a5 = 11, input;
    
    int option = displayIntructions(3); // call function and save return in int
    
    if(option == 2){        // if int is 2 
        return 20;      // return 20 to main()
    }   // end if
    
    // output border
    cout << "--------------------------------------------" << endl << endl;
    // output question
    cout << "#1 Solve for y. \n\ty = 3x + 7(x - 2) , x = 0" << endl;
    cout << "y = "; // prompt for answer
    cin >> input;   // save answer in input
    cout << endl;   // output newline
    if(input == 1234)  // output newline
        return 20;  // return 20 to main()
    while(input != a1){ // while input isnt answer
        cout << "TRY AGAIN" << endl;    // output try again
        cout << "\ty = 3x + 7(x - 2) , x = 0" << endl; // output question
        cout << "y = ";// prompt for answer
        cin >> input;// save answer in input
        cout << endl;// output newline
        if(input == 1234)// if input 1234
            return 20;// return 20 to main()
    }   // end while loop
    
    // output border
    cout << "--------------------------------------------" << endl << endl;
    // output question
    cout << "#2 Solve for x. \n\tx = 2 - 3(2y + 2) , y = 0" << endl;
    cout << "x = "; // prompt for answer
    cin >> input;   // save answer in input
    cout << endl;  // output newline
    if(input == 1234)// if input 1234
        return 20; // return 20 to main()
    while(input != a2){// while input isnt answer
        cout << "TRY AGAIN" << endl;// output try again
        cout << "\tx = 2 - 3(2y + 2) , y = 0" << endl; // output question
        cout << "x = ";// prompt for answer
        cin >> input;  // save answer in input
        cout << endl; // output newline
        if(input == 1234) // if input 1234
            return 20; // return 20 to main()
    }  // end while loop
    
    // output border
    cout << "--------------------------------------------" << endl << endl;
    // output question
    cout << "#3 Solve for y. \n\t5y = 3y + 2(3x^2 + 2x - 4) , x = 0" << endl;
    cout << "y = ";// prompt for answer
    cin >> input;// save answer in input
    cout << endl;// output newline
    if(input == 1234)// if input 1234
        return 20;// return 20 to main()
    while(input != a3){// while input isnt answer
        cout << "TRY AGAIN" << endl;// output try again
        cout << "\t5y = 3y + 2(3x^2 + 2y - 4) , x = 0" << endl;// output question
        cout << "y = ";// prompt for answer
        cin >> input;  // save answer in input
        cout << endl; // output newline
        if(input == 1234) // if input 1234
            return 20; // return 20 to main()
    }  // end while loop
    
    // output border
    cout << "--------------------------------------------" << endl << endl;
    // output question
    cout << "#4 Solve for y. \n\ty = 3x^2 + 4x - 3 , x = 2" << endl;
    cout << "y = ";// prompt for answer
    cin >> input;// save answer in input
    cout << endl;// output newline
    if(input == 1234)// if input 1234
        return 20;// return 20 to main()
    while(input != a4){// while input isnt answer
        cout << "TRY AGAIN" << endl;// output try again
        cout << "\ty = 3x^2 + 4x - 3 , x = 2" << endl;// output question
        cout << "y = ";// prompt for answer
        cin >> input;  // save answer in input
        cout << endl; // output newline
        if(input == 1234) // if input 1234
            return 20; // return 20 to main()
    }  // end while loop
    
    // output border
    cout << "--------------------------------------------" << endl << endl;
    // output question
    cout << "#5 Solve for x. \n\t4x = y(2y^3 + 3y) , y = 2" << endl;
    cout << "x = ";// prompt for answer
    cin >> input;// save answer in input
    cout << endl;// output newline
    if(input == 1234)// if input 1234
        return 20;// return 20 to main()
  
    while(input != a5){// while input isnt answer
        cout << "TRY AGAIN" << endl;// output try again
        cout << "\t4x = y(2y^3 + 3y) , y = 2" << endl;// output question
        cout << "x = ";// prompt for answer
        cin >> input;  // save answer in input
        cout << endl; // output newline
        if(input == 1234) // if input 1234
            return 20; // return 20 to main()
    }  // end while loop
    
    time(&end);  // time at end
    totalTime = end - start; // calculate totale time
    
    cout << "Time Taken: " << totalTime << " seconds." << endl; //output time
    
    return 20;  // return 20 to main()
}// end PlayPractice()

int DisplayMenu(){
    int option; // declare int
    cout << "                     Today's Lesson: " << endl;// output title
    cout << "              x-intercept and y-intercept" << endl;// output title
    cout << "             -----------------------------" << endl << endl;// output underline
    
    cout << "(1) TicTacToe Game " << endl;// output game 1 option
    cout << "    - 2 player game" << endl;// output info
    cout << "(2) Hangman Game" << endl;// output game 2 option
    cout << "(3) Math Practice" << endl;// output game 3 option
    cout << "(4) Exit" << endl << endl;// output exit option
    
    cout << "Select Option: "; // prompt for selection
    cin >> option;  // save input into int
    
    // while loop- while option isnt 1,2,3 and 4
    while(option != 1 && option != 2 && option != 3 && option != 4){
        cout << endl << "*** INVALID INPUT ***" << endl;// output warning
        cout << "(1) TicTacToe Game " << endl; // output game 1 option 
        cout << "    - 2 player game" << endl;// output info
        cout << "(2) Hangman Game" << endl;// output game 2 option
        cout << "(3) Math Practice" << endl;// output game 3 option
        cout << "(4) Exit" << endl;// output exit option
    
        cout << "Select Option: ";// prompt for selection
        cin >> option;// save input into int
    }// end while loop
    
    // output border
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;
    
    return option;  // return option to main()
}// end DisplayMenu()

void DisplayWelcome(string &userName){
    int option; // declare int
    // output title and username
    cout << "                   Welcome " << userName << "!" << endl << endl; 
    //output instructions
    cout << "Use your keyboard to navigate the game center. " << endl;
    cout << "(1) Continue    (2) Change name" << endl<< endl;//output options
    cout << "Select Option: ";// prompt for selection
    cin >> option;  // save input into int
    
    while(option != 1 && option != 2){  // while input isnt 1 and 2
        cout << endl << "*** INVALID INPUT ***" << endl;    // output warning
        cout << " (1) Continue    (2) Change name" << endl;//output options
        cout << "Select Option: ";// prompt for selection
        cin >> option;// save input into int
    }// end while loop
    
    if(option == 1){// if input is 1
        // output border
        cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;
    }// end if
    else if(option == 2){//else if input is 2
        cout << "Player Name: ";// prompt for name
        cin >> userName;// save name in string
    }// end else if
}// end DisplayWelcome()

string DisplayIntro(){
    string userName;    // declare string
    //output border
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;
    cout << "                   Math Game Center" << endl;// output title
    cout << "                  ------------------" << endl << endl;// output underline
    
    cout << "               Player Name: ";// prompt for name
    cin >> userName;    // save input into string
    // output border
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << endl;
    return userName;// return string to main()
}// end DisplayIntro()

int displayIntructions(int game){
    int option; // declare int
    cout << "Instructions: ";   // output instruction
    if(game == 1){  // if game is 1
        cout << "Choose a spot to place your key (O/X).\n"// output instruction
            << "Solve the math question and input your answer." << endl;// output instruction
        cout << "\"1234\" to return to the main menu at any time." << endl;// output instruction
    }// end if
    else if(game == 2){ // if game is 2
        cout << "Guess letters to find the hidden word\n"// output instruction
            << "before the drawing is complete." << endl;// output instruction
        cout << "\"E\" to return to the main menu at any time." << endl;// output instruction
    }// end else if
    else if(game == 3){ // if game is 3
        cout << "Solve 5 progressively difficult questions\n"// output instruction
            << "and input your answer." << endl;// output instruction
        cout << "\"1234\" to return to the main menu at any time." << endl;// output instruction
    }// end else if
    cout << "(1) Continue  (2) Return to Main Menu" << endl << endl;// output options
    cout << "Select option: ";  // prompt for selection
    cin >> option;  // save input into int
    
    while(option != 1 and option != 2){ // while loop - loops while invalidate input
        cout << endl << "*** INVALID INPUT ***" << endl;// output warning
        cout << " (1) Continue    (2) Return to Main Menu" << endl << endl;// output options
        cout << "Select Option: ";  // prompt for selection
        cin >> option;  // save input into int
    }// end while
    cout << endl;// output newline
    
    return option;// return int to main()
}// end displayIntructions()

void displayHang(int fails){
    cout << "       ____" << endl;// output hangman
    cout << "      |    |" << endl;// output hangman
    if(fails == 0){// if 0 incorrect guesses
        cout << "           |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
    }    // end if 
    if(fails == 1){// if 1 incorrect guesses
        cout << "      O    |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
    }   // end if
    if(fails == 2){// if 2 incorrect guesses
        cout << "      O    |" << endl;// output hangman
        cout << "      |    |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
    }   // end if
    if(fails == 3){// if 3 incorrect guesses
        cout << "      O    |" << endl;// output hangman
        cout << "     /|    |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
    }   // end if
    if(fails == 4){// if 4 incorrect guesses
        cout << "      O    |" << endl;// output hangman
        cout << "     /|\\   |" << endl;// output hangman
        cout << "           |" << endl;// output hangman
    }// end if
    if(fails == 5){// if 5 incorrect guesses
        cout << "      O    |" << endl;// output hangman
        cout << "     /|\\   |" << endl;// output hangman
        cout << "     /     |" << endl;// output hangman
    }   // end if
    if(fails == 6){// if 6 incorrect guesses
        cout << "      O    |" << endl;// output hangman
        cout << "     /|\\   |" << endl;// output hangman
        cout << "     / \\   |" << endl;// output hangman
    }   // end if
    cout << "         -----" << endl << endl;// output hangman
}   // end displayHang()

void displayTTT(char board[]) {
    // output top row
    cout << "        " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "       -----------" << endl;   // output border
    // output middle row
    cout << "        " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "       -----------" << endl;// output border
    // output bottom row
    cout << "        " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}// end displayTTT()

int isGameOver(char board[]) {
    int outcome;    // declare int
    
    // horizontal win
    for (int i = 0; i < 9; i += 3) {// for loop goes through each row
        // if complete row is equal to eachother
        if (board[i] == board[i+1] && board[i+1] == board[i+2]) {
            outcome = 2;// intialize int with 2(win)
            return outcome; // return int 
        }// end if
    }// end for loop
    
    // vertical win
    for (int i = 0; i < 3; i++) {// for loop goes through each column
        // if complete column is equal to eachother
        if (board[i] == board[i+3] && board[i+3] == board[i+6]) {
            outcome = 2;// intialize int with 2(win)
            return outcome; // return int 
        }// end if
    }// end for loop
    
    // diagonal win
    if (board[0] == board[4] && board[4] == board[8]) {// if diagonals are equal
        outcome = 2;// intialize int with 2(win)
        return outcome;// return int 
    }// end if
    if (board[2] == board[4] && board[4] == board[6]) {// if diagonals are equal
        outcome = 2;// intialize int with 2(win)
        return outcome;// return int 
    }// end if
    
    outcome = 3;// intialize int with 3(tie)
    return outcome;// return int
}// end isGameOver()

bool isCompleteBoard(char board[]){
    bool complete = false;// intialize and declare bool to false
    for (int i = 0; i < 9; i++) {  // for loop goes through 1-9
        if (board[i] != 'X' && board[i] != 'O') {// if each is full with a key
            return complete;    // return bool
        }// end if
    }// end for loop
    complete = true;// initialize bool to true
    return complete; // return bool
}// end isCompleteBoard()

bool equationXint(){
    srand(time(0)); //create unique seed
    // y = mx + b
    double m = (rand() % 5) + 1, b = (rand() % 11) - 5; // declare and intialize doubles
    if(fabs(b) < m){// if absolute value of yInt is less than slope
        b += (2) * m;   // add 2*m to b, avoid x-int being 0
    }// end if
    // compute x intercept and round to whole number
    double answer = round((-1) * b / m), input;// declare and initalize doubles
    
    cout << "What is the x-intercept?" << endl;// output question
    if(b < 0){// if b is negative
        cout << "   y = " << m << "x " << b << endl << endl;// output equation
        cout << "**Round to whole number**" << endl; // output rounding
        cout << "x-intercept: ";// prompt for answer
        cin >> input;// save input into double
        if(input == 1234)// if input is 1234
            return true;// return true
        cout << endl;// output endline
        if(input != answer){// if input isnt answer
            cout << " ** Incorrect **" << endl;// output incorrect
            cout << "Set y = 0, then solve for x. "<< endl; // output steps
            cout << "y = " << m << "x " << b << endl;// output equation
            cout << "0 = " << m << "x " << b << endl;// output equation
            cout << (-1) * b << " = " << m << "x " << endl;// output equation
            cout << (-1) * b << " / " << m << " = x " << endl;// output equation
            cout << answer << " = x " << endl;// output equation
            // output correct answer
            cout << fixed << setprecision(0) << "Answer --> x-intercept: " << answer << endl << endl; 
        }// end if
        else{// else - input is answer
            cout << "Correct !! :)" << endl << endl;// output correct
        }// end else
    }// end if
    else if(b > 0){// else if b is positive
        cout << "   y = " << m << "x + " << b << endl << endl;// output equation
        cout << "**Round to whole number**" << endl; // output rounding
        cout << "x-intercept: ";// prompt for answer
        cin >> input;// save input into double
        if(input == 1234)// if input is 1234
            return true;// return true
        cout << endl;// output endline
        if(input != answer){// if input isnt answer
            cout << " ** Incorrect **" << endl; // output incorrect
            cout << "Set y = 0, then solve for x. "<< endl; // output steps
            cout << "y = " << m << "x + " << b << endl;// output equation
            cout << "0 = " << m << "x + " << b << endl;// output equation
            cout << (-1) * b << " = " << m << "x " << endl;// output equation
            cout << (-1) * b << " / " << m << " = x " << endl;// output equation
            cout << answer << " = x " << endl;// output equation
            // output correct answer
            cout << fixed << setprecision(0) << "Answer --> x-intercept: " << answer << endl << endl; 
        }// end if
        else{// else - input is answer
            cout << "Correct !! :)" << endl << endl;// output correct
        }// end else
    }// end else if
    else{// else - b is 0
        cout << "   y = " << m << "x"<< endl << endl;// output equation
        cout << "**Round to whole number**" << endl; // output rounding
        cout << "x-intercept: ";// prompt for answer
        cin >> input;// save input into double
        if(input == 1234)// if input is 1234
            return true;// return true
        cout << endl;// output endline
        if(input != answer){// if input isnt answer
            cout << " ** Incorrect **" << endl;// output incorrect
            cout << "Set y = 0, then solve for x. "<< endl; // output steps
            cout << "y = " << m << "x"<< endl;// output equation
            cout << "0 = " << m << "x"<< endl;// output equation
            cout << "0 / " << m << " = x " << endl;// output equation
            cout << answer << " = x " << endl;// output equation
            // output correct answer
            cout << fixed << setprecision(0) << "Answer --> x-intercept: " << answer << endl << endl; 
        }// end if
        else{// else - input is answer
            cout << "Correct !! :)" << endl << endl;// output correct
        }// end else
    }// end else
    return false;// return false
}// end equationXint()

bool equationYint(){
    srand(time(0)); // create unique seed
    double m = (rand() % 6), b = (rand() % 11) - 5;// declare and intialize doubles
    double answer = b, input; // declare and initialize doubles
    
    cout << "What is the y-intercept?" << endl; // output question
    if(b < 0){ // if be is negative
        cout << "   y = " << m << "x " << b << endl << endl;// output equation
        cout << "**Round to whole number**" << endl; // output rounding
        cout << "y-intercept: ";// prompt for answer
        cin >> input;// save input into double
        if(input == 1234)// if input is 1234
            return true;// return true
        cout << endl;// output endline
        if(input != answer){// if input isnt answer
            cout << " ** Incorrect **" << endl;// output incorrect
            cout << "Set x = 0, then solve for y. "<< endl; // output steps
            cout << "y = " << m << "x " << b << endl;// output equation
            cout << "y = " << m << "(0) " << b << endl;// output equation
            cout << "y = " << b << endl;// output equation
            // output correct answer
            cout << fixed << setprecision(0) << "Answer --> y-intercept: " << answer << endl << endl; 
        }// end if
        else{// else - input is answer
            cout << "Correct !! :) " << endl << endl;// output correct
        }// end else
    }// end if
    else if(b > 0){// if b is positive
        cout << "   y = " << m << "x + " << b << endl << endl;// output equation
        cout << "**Round to whole number**" << endl; // output rounding
        cout << "y-intercept: ";// prompt for answer
        cin >> input;// save input into double
        if(input == 1234)// if input is 1234
            return true;// return true
        cout << endl;// output endline
        if(input != answer){// if input isnt answer
            cout << " ** Incorrect **" << endl;// output incorrect
            cout << "Set x = 0, then solve for y. "<< endl; // output steps
            cout << "y = " << m << "x +" << b << endl;// output equation
            cout << "y = " << m << "(0) +" << b << endl;// output equation
            cout << "y = " << b << endl;// output equation
            // output correct answer
            cout << fixed << setprecision(0) << "Answer --> y-intercept: " << answer << endl << endl; 
        }// end if
        else{// else - input is answer
            cout << "Correct !! :)" << endl << endl;// output correct
        }// end else
    }// end else if
    else{// else b is 0
        cout << "   y = " << m << "x " << endl << endl;// output equation
        cout << "**Round to whole number**" << endl; // output rounding
        cout << "y-intercept: ";// prompt for answer
        cin >> input;// save input into double
        if(input == 1234)// if input is 1234
            return true;// return true
        cout << endl;// output endline
        if(input != answer){// if input isnt answer
            cout << " ** Incorrect **" << endl;// output incorrect
            cout << "Set x = 0, then solve for y. "<< endl; // output steps
            cout << "y = " << m << "x "<< endl;// output equation
            cout << "y = " << m << "(0) " << endl;// output equation
            cout << "y = " << b << endl;// output equation
            // output correct answer
            cout << fixed << setprecision(0) << "Answer --> y-intercept: " << answer << endl << endl; 
        }// end if
        else{// else - input is answer
            cout << "Correct !! :)" << endl << endl;// output correct
        }// end else
    }// end else
    return false;// return false
}// end equationYint()

bool tableQuestion(int placeNum){
    int input, answer;// declare ints
    cout << "Find the y-int of the table" << endl;// ask question
    
    if(placeNum == 7){// if spot is 7
        cout << "  x |  y " << endl; // output table
        cout << "---------" << endl; // output table
        cout << " -1 |  -1 " << endl; // output table
        cout << "  0 |  2 " << endl; // output table
        cout << "  1 |  5 " << endl; // output table
        cout << "  2 |  8 " << endl << endl; // output table
        answer = 2;// initalize int with 2
    }// end if
    else if(placeNum == 8){// if spot is 8
        cout << "  x |  y " << endl; // output table
        cout << "---------" << endl; // output table
        cout << " -1 |  2 " << endl; // output table
        cout << "  0 |  4 " << endl; // output table
        cout << "  1 |  6 " << endl; // output table
        cout << "  2 |  0 " << endl << endl; // output table
        answer = 4;// initalize int with 4
    }// end else if
    else if(placeNum == 9){// if spot is 9
        cout << "  x |  y " << endl; // output table
        cout << "---------" << endl; // output table
        cout << " -1 |  -2 " << endl; // output table
        cout << "  0 |  0 " << endl; // output table
        cout << "  1 |  2 " << endl; // output table
        cout << "  2 |  4 " << endl << endl; // output table
        answer = 0;// initalize int with 0
    }// end else if
    cout << "y-intercept: "; // prompt for answer
    cin >> input;// save input in int
    if(input == 1234)   // if input is 1234
        return true;    // return true
    cout << endl;   // output newline
    if(input != answer){ // if input is not answer
        cout << " ** Incorrect **" << endl;// output incorrect
        cout << "Find the point where x = 0." << endl;// output steps
        cout << "The corresponding y value is the y-intercept" << endl;// output steps
        cout << "Answer --> y-intercept: " << answer << endl << endl; // output correct answer
    }// end if
    else{// else input is answer
        cout << "Correct !! :) " << endl << endl;// output correct
    }// end else 
    return false;// return false
} // end tableQuestion()





