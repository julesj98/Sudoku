/*
 *
 * Julian Cordova, Michael Nunn, Santiago Romero, Matthew Sabin, Philip Laussermair
 * Submitted: 04/23/2018
 * Group 31
 * Term Project
 * Magic Square Sudoku
 *
 * Welcome to our reproduction of the complex and exciting game of Sudoku! Using the logic behind the idea of producing magic squares,
 * our group was able to construct a program that closely resembles Sudoku.
 *
 */

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <ctime>

/*
 * Below are alternative methods that our team was considering
 * using in the project, included here to better document our
 * thinking process throughout this project.
 *
/*
int addCorrects(int numCorrect)
{

    numCorrect = numCorrect++;
	return numCorrect;

}

int addWrongs(int numWrong)
{

    numWrong = numWrong++;
	return numWrong;

}

int addGuess(int playerGuess)
{

    playerGuess = playerGuess++;
	return playerGuess;

}

*/

double calcGuessAvg(int numCorrect, int numWrong) {
	double guessAvg = ((double)numCorrect / (double)numWrong) * 100;
	return guessAvg;
}


int main()
{
	int numCorrect = 0;
	int numWrong = 0;
	int playerGuess = 0;

    //Print out menu
    std::cout << "Welcome to Magic Square Sudoku!" << "\n\n";
    int userOption;
    std::cout << "Main Menu: Please select an option ('1', '2', '3', or '4')\n";
    std::cout << "1. View instructions\n";
    std::cout << "2. View answer key\n";
    std::cout << "3. Play game\n";
    std::cout << "4. Exit program\n";
    std::cin >> userOption;

  	while (userOption != 1 && userOption != 2 && userOption != 3 && userOption!= 4)
    {
        std::cout << "Invalid input, please enter either '1', '2', '3', or '4': ";
        std::cin >> userOption;
    }

        switch (userOption)
        {
            case 1: {
                std::cout << "INSTRUCTIONS: First you must determine the size of your board. When deciding on the size remember "
                        "that as the board size gets larger the game gets more difficult.\nThe number you enter determines the "
                        "number of rows and columns in the matrix. For example, if you enter '5', a 5x5 matrix will be created. "
                        "After you decide on the size,\nyou must shuffle the board. After the board is created and shuffled the "
                        "game will begin. You will be prompted to guess numbers to complete the magic square. The game will\nlet "
                        "you know when you are correct or incorrect. In the case of a correct guess, you will get to move on to "
                        "the next open space. In the case of an incorrect guess you\nwill keep guessing until you are correct. "
                        "You will have the option of getting a hint if you need one. Once the game is over your stats will be "
                        "printed and you will\nhave the option to play again or exit the game. If you want to quit at any point, "
                        "just type 'quit' and the program will terminate. \n\n";
                std::cout << "Please select another option:\n";
                std::cout << "1. View instructions\n";
                std::cout << "2. View answer key\n";
                std::cout << "3. Play game\n";
                std::cout << "4. Exit program\n";

                std::cin >> userOption;
                while (userOption != 1 && userOption != 2 && userOption != 3 && userOption!= 4)
                {
                    std::cout << "Invalid input, please enter either '1', '2', '3', or '4': ";
                    std::cin >> userOption;
                }
                break;
            }
            case 2: {
                std::cout << "Welcome to the answer key.\n";
                int nValue;// Get nValue of magic square from user
                std::cout << "Enter the size of the board (either '5', '7', or '9'): ";
                std::cin >> nValue;
                if (nValue == 99)
                {
                    std::cout << "You quit. Have a nice day!";
                }

                while (nValue != 3 && nValue != 5 && nValue != 7)
                {
                    std::cout << "Invalid input, please enter either '5', '7', or '9': ";
                    std::cin >> nValue;
                }

                std::cout << "\n";
                int matrix1[nValue][nValue];
                memset(matrix1, 0, sizeof(matrix1));
                int row = 0;
                int column = nValue / 2;
                matrix1[row][column] = 1;

                for (int i = 2; i <= nValue * nValue; i++)
                {
                    if (row - 1 < 0)
                    {
                        row = nValue - 1;
                    }
                    else
                    {
                        row--;
                    }
                    if (column + 1 == nValue)
                    {
                        column = 0;
                    }
                    else
                    {
                        column++;
                    }
                    if (matrix1[row][column] != 0)
                    {
                        column--;
                        row +=2;
                        if (row - 1 < 0)
                        {
                            row = nValue - 1;
                        }
                        if (row >= nValue)
                        {
                            row = 1;
                        }
                        if (column < 0)
                        {
                            column = nValue - 1;
                        }
                    }
                    matrix1[row][column] = i;
                }

                int shuffle;
                std::cout << "Enter the way you would like to see the board shuffled (integer between 1 and 10): \n";
                std::cin >> shuffle;
                while (shuffle < 1 && shuffle > 10)
                {
                    std::cout << "Invalid input, please enter an integer between 1 and 10: ";
                    std::cin >> nValue;
                }
                switch (nValue)
                {
                    case 1: {
                        // Print matrix1 and sums
                        std::cout << "Board #1 is:\n" << "\n";


                      for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix1[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";
                        int sum = 0;
                        int add = 0;

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix1[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";

                      for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix1[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix1[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix1[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 2: {
                        // Create and populate matrix2 by inverting the values of matrix1
                        int matrix2[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix2, 0, sizeof(matrix2));

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix2[i][j] = (nValue * nValue + 1) - matrix1[i][j];
                            }
                        }
                        // Print matrix2 and sums
                        std::cout << "Board #2 is:\n" << "\n";

                      for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix2[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix2[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";

                      for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix2[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix2[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix2[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 3: {
                        // Create and populate matrix3 by rotating matrix1
                        int matrix3[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix3, 0, sizeof(matrix3));

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = i; j < nValue; j++)
                            {
                                matrix3[i][j] = matrix1[j][i];
                                matrix3[j][i] = matrix1[i][j];
                            }
                        }
                        // Print matrix3 and sums
                        std::cout << "Board #3 is:\n" << "\n";

                      for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix3[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix3[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";

                      for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix3[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix3[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix3[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 4: {
                        // Create and populate matrix4 by flipping matrix1 vertically
                        int matrix4[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix4, 0, sizeof(matrix4));

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix4[i][j] = matrix1[i][nValue - 1 - j];
                            }
                        }
                        // Print matrix4 and sums
                        std::cout << "Board #4 is:\n" << "\n";

                      for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix4[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix4[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";

                      for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix4[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix4[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix4[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 5: {
                        // Create and populate matrix5 by flipping matrix1 horizontally
                        int matrix5[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix5, 0, sizeof(matrix5));

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix5[j][i] = matrix1[nValue - 1 - j][i];
                            }
                        }
                        // Print matrix5 and sums
                        std::cout << "Board #5 is:\n" << "\n";

                      for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix5[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";

                      for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix5[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";

                      for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix5[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";

                      for (int i = 0; i < nValue; i++)
                        {
                            add = matrix5[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix5[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 6: {
                        // Create and populate matrix6
                        int matrix6[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix6, 0, sizeof(matrix6));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix6[i][j] = matrix1[nValue - 1 - j][nValue - 1 - i];
                            }
                        }
                        // Print matrix6 and sums
                        std::cout << "Board #6 is:\n" << "\n";
                        for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix6[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix6[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";
                        for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix6[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix6[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix6[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 7: {
                        // Create and populate matrix7
                        int matrix7[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix7, 0, sizeof(matrix7));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix7[i][j] = matrix1[j][nValue - 1 - i];
                            }
                        }
                        // Print matrix7 and sums
                        std::cout << "Board #7 is:\n" << "\n";
                        for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix7[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix7[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";
                        for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix7[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix7[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix7[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 8: {
                        // Create and populate matrix8
                        int matrix8[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix8, 0, sizeof(matrix8));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix8[j][i] = matrix1[nValue - 1 - i][j];
                            }
                        }
                        // Print matrix8 and sums
                        std::cout << "Board #8 is:\n" << "\n";
                        for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix8[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix8[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";
                        for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix8[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix8[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix8[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 9: {
                        // Create and populate matrix9
                        int matrix9[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        memset(matrix9, 0, sizeof(matrix9));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix9[j][i] = matrix1[nValue - 1 - i][j];
                            }
                        }
                        int temp;
                        for (int i; i < nValue; i++)
                        {
                            temp = matrix9[i][0];
                            matrix9[i][0] = matrix9[i][nValue-1];
                            matrix9[i][nValue-1] = temp;
                        }

                        // Print matrix9 and sums
                        std::cout << "Board #9 is:\n" << "\n";
                        for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix9[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";
                        for (int i = 0; i < nValue; i++) {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix9[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";
                        for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix9[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix9[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix9[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        sum = 0;
                        break;
                    }
                    case 10: {
                        // Create and populate matrix10
                        int matrix10[nValue][nValue];
                        int sum = 0;
                        int add = 0;
                        int temp;
                        memset(matrix10, 0, sizeof(matrix10));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix10[j][i] = matrix1[nValue - 1 - i][j];
                            }
                        }
                        for (int i; i < nValue; i++)
                        {
                            temp = matrix10[0][i];
                            matrix10[0][i] = matrix10[nValue-1][i];
                            matrix10[nValue-1][i] = temp;
                        }
                        // Print matrix10 and sums
                        std::cout << "Board #10 is:\n" << "\n";
                        for (int i = 0; i < nValue; i++)
                        {
                            std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                std::cout << matrix10[i][j];
                                std::cout << "  ";
                            }
                            std::cout << "\n";
                        }
                        std::cout << "\n";
                        std::cout << "Checking the sums of every row:      ";
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                add = matrix10[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every column:   ";
                        for (int j = 0; j < nValue; j++)
                        {
                            for (int i = 0; i < nValue; i++)
                            {
                                add = matrix10[i][j];
                                sum += add;
                            }
                            std::cout << sum << " ";
                            sum = 0;
                        }
                        std::cout << "\n" << "Checking the sums of every diagonal: ";
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix10[i][i];
                            sum += add;
                        }
                        std::cout << sum << " ";
                        sum = 0;
                        for (int i = 0; i < nValue; i++)
                        {
                            add = matrix10[nValue - 1 - i][i];
                            sum += add;
                        }
                        std::cout << sum << " \n" << "\n";
                        break;
                    }
                }
                std::cout << "Please select another option:\n";
                std::cout << "1. View instructions\n";
                std::cout << "2. View answer key\n";
                std::cout << "3. Play game\n";
                std::cout << "4. Exit program\n";
                std::cin >> userOption;
                while (userOption != 1 && userOption != 2 && userOption != 3 && userOption!= 4)
                {
                    std::cout << "Invalid input, please enter either '1', '2', '3', or '4': ";
                    std::cin >> userOption;
                }
                break;
          	}
            case 3: {
                std::cout << "Please enter either 5, 7, or 9: " << "\n";
                std::cout << "- Easy (5)"<< "\n";
                std::cout << "- Medium (7)"<< "\n";
                std::cout << "- Hard (9)"<< "\n";
                std::cout << "To exit at any point type '99'\n";
                int nValue;// Get nValue of magic square from user
                std::cin >> nValue;
                if (nValue == 99)
                {
                    std::cout << "You quit. Have a nice day!";
                    return 0;
                }
                while (nValue != 5 && nValue != 7 && nValue != 9)
                {
                    std::cout << "Invalid input, please enter either 5, 7, or 9: ";
                    std::cin >> nValue;
                }
                if (nValue == 99)
                {
                    std::cout << "You quit. Have a nice day!";
                }
                switch (nValue) {
                    case 5: {
                        std::cout << "Easy difficulty selected\n\n";
                        break;
                    }
                    case 7: {
                        std::cout << "Medium difficulty selected\n\n";
                        break;
                    }
                    case 9: {
                        std::cout << "Hard difficulty selected\n\n";
                        break;
                    }
                    case 99: {
                        std::cout << "You quit. Have a nice day!";
                        return 0;
                    }
                }
                std::cout << "Please enter a number between 1 and 10 "//Shuffling matrix for user
                        "to determine how your board will be shuffled:" << "\n";
                int choice;
                std::cin >> choice;
                if (choice == 99) {
                    std::cout << "You quit. Have a nice day!";
                    return 0;
                }
                std::cout << "\n";
                std::cout << "Here is your board. Every column, row, and diagonal must add up to ";
                switch (nValue)
                {
                    case 5: {
                        std::cout << "65. ";
                        break;
                    }
                    case 7: {
                        std::cout << "175. ";
                        break;
                    }
                    case 9: {
                        std::cout << "369. ";
                        break;
                    }
                }
                std::cout << "Good Luck!" << "\n";
                srand(time(0));
                int a = rand() % nValue;
                int b = rand() % nValue;
                int c = rand() % nValue;
                int d = rand() % nValue;
                int e = rand() % nValue;
                int f = rand() % nValue;
                int g = rand() % nValue;
                int h = rand() % nValue;
                while (e==g)//these while loops ensure that there will always be 4 randomly selected numbers for the user to guess
                {
                    e = rand() % nValue;
                }
                while ((c==e) || (c == g))
                {
                    c = rand() % nValue;
                }
                while ((a==c) || (a == e) || (a==g))
                {
                    a = rand() % nValue;
                }
                // Matrix that will be used after switch statement to store the USERS selected magic
                // square. Check the print statements of each possible magic square to see where
                // "matrix" is receiving its values from.
                int matrix[nValue][nValue];
                int matrixOG[nValue][nValue];// Matrix for the CORRECT magic square. Useful for debugging
                switch (choice) {
                    case 1: {
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            } else {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row += 2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix1[i][j];
                            }
                        }
                        matrix1[a][b] = -1;
                        matrix1[c][d] = -2;
                        matrix1[e][f] = -3;
                        matrix1[g][h] = -4;
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix1[i][j];
                            }
                        }
                        break;
                    }
                    case 2: {
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;

                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            } else {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row += 2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix2[nValue][nValue];
                        memset(matrix2, 0, sizeof(matrix2));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix2[i][j] = (nValue * nValue + 1) - matrix1[i][j];
                            }
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix2[i][j];
                            }
                        }
                        matrix2[a][b] = -1;
                        matrix2[c][d] = -2;
                        matrix2[e][f] = -3;
                        matrix2[g][h] = -4;
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix2[i][j];
                            }
                        }
                        break;
                    }
                    case 3: {
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));

                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix3[nValue][nValue];
                        memset(matrix3, 0, sizeof(matrix3));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = i; j < nValue; j++)
                            {
                                matrix3[i][j] = matrix1[j][i];
                                matrix3[j][i] = matrix1[i][j];
                            }
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix3[i][j];
                            }
                        }
                        matrix3[a][b] = -1;
                        matrix3[c][d] = -2;
                        matrix3[e][f] = -3;
                        matrix3[g][h] = -4;
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix3[i][j];
                            }
                        }
                        break;
                    }
                    case 4: {
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix4[nValue][nValue];
                        memset(matrix4, 0, sizeof(matrix4));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix4[i][j] = matrix1[i][nValue - 1 - j];
                            }
                        }

                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix4[i][j];
                            }
                        }
                        matrix4[a][b] = -1;
                        matrix4[c][d] = -2;
                        matrix4[e][f] = -3;
                        matrix4[g][h] = -4;

                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix4[i][j];
                            }
                        }
                        std::cout << "\n";
                        break;
                    }
                    case 5: {
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;

                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix5[nValue][nValue];
                        memset(matrix5, 0, sizeof(matrix5));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix5[j][i] = matrix1[nValue - 1 - j][i];
                            }
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix5[i][j];
                            }
                        }
                        matrix5[a][b] = -1;
                        matrix5[c][d] = -2;
                        matrix5[e][f] = -3;
                        matrix5[g][h] = -4;
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix5[i][j];
                            }
                        }
                        break;
                    }
                    case 6: {
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix6[nValue][nValue];
                        memset(matrix6, 0, sizeof(matrix6));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix6[i][j] = matrix1[nValue - 1 - j][nValue - 1 - i];
                            }
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix6[i][j];
                            }
                        }
                        matrix6[a][b] = -1;
                        matrix6[c][d] = -2;
                        matrix6[e][f] = -3;
                        matrix6[g][h] = -4;
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix6[i][j];
                            }
                        }
                        break;
                    }
                    case 7: {
                        // Create the initial matrix
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix7[nValue][nValue];
                        memset(matrix7, 0, sizeof(matrix7));
                        for (int i = 0; i < nValue; i++) {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix7[i][j] = matrix1[j][nValue - 1 - i];
                            }
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix7[i][j];
                            }
                        }
                        matrix7[a][b] = -1;
                        matrix7[c][d] = -2;
                        matrix7[e][f] = -3;
                        matrix7[g][h] = -4;

                        // Print matrix7
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix7[i][j];
                            }
                        }
                        break;
                    }
                    case 8: {
                        // Create the initial matrix
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        // Create and populate matrix8
                        int matrix8[nValue][nValue];
                        memset(matrix8, 0, sizeof(matrix8));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix8[j][i] = matrix1[nValue - 1 - i][j];
                            }
                        }

                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix8[i][j];
                            }
                        }
                        matrix8[a][b] = -1;
                        matrix8[c][d] = -2;
                        matrix8[e][f] = -3;
                        matrix8[g][h] = -4;

                        // Print matrix8
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix8[i][j];
                            }

                        }
                        break;
                    }
                    case 9: {
                        // Create the initial matrix
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;
                        for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0)
                            {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        // Create and populate matrix9
                        int matrix9[nValue][nValue];
                        memset(matrix9, 0, sizeof(matrix9));
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix9[j][i] = matrix1[nValue - 1 - i][j];
                            }
                        }
                        int temp;
                        for (int i; i < nValue; i++)
                        {
                            temp = matrix9[i][0];
                            matrix9[i][0] = matrix9[i][nValue-1];
                            matrix9[i][nValue-1] = temp;
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix9[i][j];
                            }
                        }
                        matrix9[a][b] = -1;
                        matrix9[c][d] = -2;
                        matrix9[e][f] = -3;
                        matrix9[g][h] = -4;

                        for (int i = 0; i < nValue; i++)
                        {
                            //std::cout << "  ";
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix9[i][j];
                            }
                        }
                        break;
                    }
                    case 10: {
                        // Create the initial matrix
                        int matrix1[nValue][nValue];
                        memset(matrix1, 0, sizeof(matrix1));
                        int row = 0;
                        int column = nValue / 2;
                        matrix1[row][column] = 1;

                      for (int i = 2; i <= nValue * nValue; i++)
                        {
                            if (row - 1 < 0) {
                                row = nValue - 1;
                            }
                            else
                            {
                                row--;
                            }
                            if (column + 1 == nValue)
                            {
                                column = 0;
                            }
                            else
                            {
                                column++;
                            }
                            if (matrix1[row][column] != 0)
                            {
                                column--;
                                row +=2;
                                if (row - 1 < 0)
                                {
                                    row = nValue - 1;
                                }
                                if (row >= nValue)
                                {
                                    row = 1;
                                }
                                if (column < 0)
                                {
                                    column = nValue - 1;
                                }
                            }
                            matrix1[row][column] = i;
                        }
                        int matrix10[nValue][nValue];
                        memset(matrix10, 0, sizeof(matrix10));
                        int temp;
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix10[j][i] = matrix1[nValue - 1 - i][j];
                            }
                        }
                        for (int i; i < nValue; i++) {
                            temp = matrix10[0][i];
                            matrix10[0][i] = matrix10[nValue-1][i];
                            matrix10[nValue-1][i] = temp;
                        }
                        // Storing the correct board into matrixOG
                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrixOG[i][j] = matrix1[i][j];
                            }
                        }
                        matrix10[a][b] = -1;
                        matrix10[c][d] = -2;
                        matrix10[e][f] = -3;
                        matrix10[g][h] = -4;

                        for (int i = 0; i < nValue; i++)
                        {
                            for (int j = 0; j < nValue; j++)
                            {
                                matrix[i][j] = matrix10[i][j];
                            }
                        }
                        break;
                    }
                    case 99: {
                        return 0;
                    }
                }
                bool guess = true;
                int maxAttempts = 4;
                int playerAttempts = 0;
                while (guess)// The while loop that continues until the player either wins or decides to quit
                {
                    for (int i = 0; i < nValue; i++)
                    {
                        std::cout << "  ";

                        for (int j = 0; j < nValue; j++)
                        {

                            if (matrix[i][j] < 0)
                            {

                                std::cout << "X";
                                std::cout << "  ";

                            }

                            else
                            {

                                std::cout << matrix[i][j];
                                std::cout << "  ";

                            }

                        }

                        std::cout << "\n";

                    }

                    std::cout << "\n";
                    std::string x;
                    std::string y;//Coordinates for the user's position selection (x,y)
                    int xCheck;
                    int yCheck;
                    std::cout << "Time to choose which box you would like to fill in!\n";

                    // Checking for valid input of user-entered x coordinate
                    bool checkInputX = false;

                    while (!checkInputX)
                    {

                        std::cout << "How many squares to the right would you "
                                "like to go? (Enter a number 0 through " << nValue - 1 << ")\n";

                        std::cin >> x;

                        if (x == "99")
                        {

                            std::cout << "You quit. Have a nice day!";
                            return 0;

                        }
                        // Converts the first character and second character of the x-coordinate string to an integer type
                        // Only checks second character if the size of the string is greater than 1
                        xCheck = x.at(0) - '0';

                        /* 1. First char has to be a number
                         * 2. Number can't be more than 2 characters long
                         * 3. First char, when converted to int, CAN'T be greater than the magic square size MINUS 1
                         * 4. Can't be less than 0
                         */

                        if (!isdigit(x.at(0)) || x.size() > 1 || xCheck > nValue - 1 || xCheck < 0)
                        {

                            std::cout << "ERROR: Invalid input. Please try again!\n";
                            std::cin.ignore();
                            std::cin.clear();
                            continue;

                        }

                        else
                        {

                            if (xCheck == b || xCheck == d || xCheck == f || xCheck == h)
                            {

                               checkInputX = true;

                            }

                            else {

                                std::cout << "Please try again! Choose an empty spot with an 'X' \n";

                            }

                        }

                    }
                    // Checking for valid input of user-entered y coordinate
                    bool checkInputY = false;

                    while (!checkInputY)
                    {

                        std::cout << "How many squares down would you "
                                "like to go? (Enter a number 0 through " << nValue - 1 << ")\n";
                        std::cin >> y;

                        if (y == "99")
                        {

                            std::cout << "You quit. Have a nice day!";
                            return 0;

                        }

                        // Converts the first and second character of the x-coordinate string to an integer type
                        // Only checks second character if the size of the string is greater than 1
                        yCheck = y.at(0) - '0';

                        /* 1. First char has to be a number
                         * 2. Number can't be more than 2 characters long
                         * 3. First char, when converted to int, CAN'T be greater than the magic square size MINUS 1
                         * 4. Can't be less than 0
                         */

                        if (!isdigit(y.at(0)) || y.size() > 1 || yCheck > nValue - 1 || yCheck < 0)
                        {

                            std::cout << "ERROR: Invalid input. Please try again!\n";
                            std::cin.ignore();
                            std::cin.clear();
                            continue;

                        }

                        else
                        {

                            if (yCheck == a || yCheck == c || yCheck == e || yCheck == g)
                            {

                                checkInputY = true;

                            }

                            else
                            {

                                std::cout << "Please try again! Choose an empty spot with an 'X' \n";

                            }

                        }

                    }

                    bool guessingNum = true;

                    // Loops until the user guesses the right number at the specified location on the board
                    while (guessingNum)
                    {

                        std::cout << "You chose coordinate (" << xCheck << "," << yCheck << "). \n"
                                "Now please enter your guess: \n";
                        std::string numGuess;

                        //Checking for valid input of user-entered guess
                        bool checkInputNum = false;

                        while (!checkInputNum)
                        {

                            std::cin >> numGuess;

                            if (numGuess == "99")
                            {

                                std::cout << "You quit. Have a nice day!";
                                return 0;

                            }

                            unsigned int i = 0;
                            bool correctInput = true;

                            while (i < numGuess.size() && correctInput)
                            {

                                if (!isdigit(numGuess.at(0)))
                                {

                                    std::cout << "ERROR: Invalid input. Please try again!\n";
                                    std::cin.ignore();
                                    std::cin.clear();
                                    correctInput = false;

                                }

                                i++;

                            }

                            if (correctInput)
                            {

                               checkInputNum = true;

                            }

                        }


                      	std::stringstream toInt(numGuess);//Converting the guess from a string to an integer
                        int numGuessInt = 0;
                        toInt >> numGuessInt;

                        std::cout << "GUESS: " << numGuessInt << "\n";


                      	//Checking to see if the number matches the number in the correct magic square at that position
                        if (numGuessInt == matrixOG[yCheck][xCheck])
                        {

                            std::cout << "You are correct!!\n\n";
                            numCorrect++;
                            playerGuess++;
                            matrix[yCheck][xCheck] = numGuessInt;
                            guessingNum = false;
                            playerAttempts=playerAttempts+1;

                          if (playerAttempts == maxAttempts)
                            {

                            for (int i = 0; i < nValue; i++)
                              {

                              	std::cout << "  ";

                              	for (int j = 0; j < nValue; j++)
                                    {

                                  	if (matrix[i][j] < 0)
                                        {

                                      	std::cout << "X";
                                        std::cout << "  ";

                                    	}

                                  	else
                                        {
                                        std::cout << matrix[i][j];
                                        std::cout << "  ";

                                    	}

                                }

                              	std::cout << "\n";

                            }

                            std::cout << "\n";
                          	std::cout << "Here are your statistics for your game:\n"
                              			"Total number of guesses: " << playerGuess << "\n"
                              			"Number of correct guesses: " << numCorrect << "\n"
										"Number of incorrect guesses: " << numWrong << "\n"
										"Percentage correct: " << calcGuessAvg(numCorrect, numWrong) << "%\n";
                            std::cout << "You have completed the board. Thanks for playing!";
                            return 0;

                        }

                    }

                    else
                    {

                        std::cout << "Sorry, but that's incorrect! Please try again\n\n";
                        numWrong++;
                        playerGuess++;

                    }

                }

            }

            break;

        }
        case 4: {
            std::cout << "Program terminated. Have a nice day!";
            break;

        }

    }

    return 0;

}
