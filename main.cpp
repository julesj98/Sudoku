#include <iostream>
#include <string.h>
#include <cstdlib>
#include <sstream>

int main() {
    //Print out menu
    std::cout << "Welcome to Magic Square Sudoku!" << "\n";
    std::cout << "Please enter an odd number between 3 and 15 to determine the size of your Sudoku grid:" << "\n";
    std::cout << "- Easy (3)"<< "\n";
    std::cout << "- Medium (5-7)"<< "\n";
    std::cout << "- Hard (9-11)"<< "\n";
    std::cout << "- Impossible (13-15)"<< "\n";

    // Get nValue of magic square from user
    int nValue;
    std::cin >> nValue;
    while (nValue % 2 == 0 || nValue < 3 || nValue > 15) {
        std::cout << "Invalid input, please enter an odd number between 3 and 15: ";
        std::cin >> nValue;
    }
    std::cout << "\n";

    //Shuffling matrix for user
    std::cout << "Please enter a number between 1 and 10 (between 1 and 8 for grid size 3) "
            "to determine how your board will be shuffled:" << "\n";
    int choice;
    std::cin >> choice;
    std::cout << "\n";

    std::cout << "Here is your board. Every column, row, and diagonal must add up to ";
    switch (nValue) {
        case 3: {
            std::cout << "15. ";
            break;
        }
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
        case 11: {
            std::cout << "671. ";
            break;
        }
        case 13: {
            std::cout << "1105. ";
            break;
        }
        case 15: {
            std::cout << "1695. ";
            break;
        }
    }
    std::cout << "Good Luck!" << "\n" << "\n";

	int a = rand() % nValue;
    int b = rand() % nValue;
    int c = rand() % nValue;
    int d = rand() % nValue;
    int e = rand() % nValue;
    int f = rand() % nValue;
    int g = rand() % nValue;
    int h = rand() % nValue;

    // Matrix that will be used after switch statement to store the USERS selected magic
    // square. Check the print statements of each possible magic square to see where
    // "matrix" is receiving its values from.
    int matrix[nValue][nValue];

    // Matrix for the CORERCT magic square
    int matrixOG[nValue][nValue];

    switch (choice) {
        case 1: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                } else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                } else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row += 2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }

            // Storing the correct board into matrixOG
            for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix1[i][j];
				}
			}

          	matrix1[a][b] = -1;
			matrix1[c][d] = -2;
			matrix1[e][f] = -3;
			matrix1[g][h] = -4;

            // Print matrix1
            std::cout << "Board #1 is:\n" << "\n";

            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix1[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix1[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 2: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));
            int row = 0;
            int column = nValue / 2;
            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                } else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                } else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row += 2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix2 by inverting the values of matrix1
            int matrix2[nValue][nValue];
            memset(matrix2, 0, sizeof(matrix2));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix2[i][j] = (nValue * nValue + 1) - matrix1[i][j];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix2[i][j];
				}
			}

          	matrix2[a][b] = -1;
			matrix2[c][d] = -2;
			matrix2[e][f] = -3;
			matrix2[g][h] = -4;

            // Print matrix2 and sums
            std::cout << "Board #2 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix2[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix2[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 3: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix3 by rotating matrix1
            int matrix3[nValue][nValue];
            memset(matrix3, 0, sizeof(matrix3));
            for (int i = 0; i < nValue; i++) {
                for (int j = i; j < nValue; j++) {
                    matrix3[i][j] = matrix1[j][i];
                    matrix3[j][i] = matrix1[i][j];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix3[i][j];
				}
			}

          	matrix3[a][b] = -1;
			matrix3[c][d] = -2;
			matrix3[e][f] = -3;
			matrix3[g][h] = -4;

            // Print matrix3
            std::cout << "Board #3 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix3[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix3[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 4: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix4 by flipping matrix1 vertically
            int matrix4[nValue][nValue];
            memset(matrix4, 0, sizeof(matrix4));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix4[i][j] = matrix1[i][nValue - 1 - j];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix4[i][j];
				}
			}

          	matrix4[a][b] = -1;
			matrix4[c][d] = -2;
			matrix4[e][f] = -3;
			matrix4[g][h] = -4;

            // Print matrix4
            std::cout << "Board #4 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix4[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix4[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 5: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix5 by flipping matrix1 horizontally
            int matrix5[nValue][nValue];
            memset(matrix5, 0, sizeof(matrix5));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix5[j][i] = matrix1[nValue - 1 - j][i];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix5[i][j];
				}
			}

          	matrix5[a][b] = -1;
			matrix5[c][d] = -2;
			matrix5[e][f] = -3;
			matrix5[g][h] = -4;

            // Print matrix5
            std::cout << "Variation #5 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix5[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix5[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 6: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix6
            int matrix6[nValue][nValue];
            memset(matrix6, 0, sizeof(matrix6));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix6[i][j] = matrix1[nValue - 1 - j][nValue - 1 - i];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix6[i][j];
				}
			}

          	matrix6[a][b] = -1;
			matrix6[c][d] = -2;
			matrix6[e][f] = -3;
			matrix6[g][h] = -4;

            // Print matrix6
            std::cout << "Variation #6 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix6[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix6[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 7: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix7
            int matrix7[nValue][nValue];
            memset(matrix7, 0, sizeof(matrix7));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix7[i][j] = matrix1[j][nValue - 1 - i];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix7[i][j];
				}
			}

         	matrix7[a][b] = -1;
			matrix7[c][d] = -2;
			matrix7[e][f] = -3;
			matrix7[g][h] = -4;

            // Print matrix7
            std::cout << "Board #7 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix7[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix7[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 8: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix8
            int matrix8[nValue][nValue];
            memset(matrix8, 0, sizeof(matrix8));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix8[j][i] = matrix1[nValue - 1 - i][j];
                }
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix8[i][j];
				}
			}

         	matrix8[a][b] = -1;
			matrix8[c][d] = -2;
			matrix8[e][f] = -3;
			matrix8[g][h] = -4;

            // Print matrix8
            std::cout << "Variation #8 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix8[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix8[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 9: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix9
            int matrix9[nValue][nValue];
            memset(matrix9, 0, sizeof(matrix9));
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix9[j][i] = matrix1[nValue - 1 - i][j];
                }
            }
            int temp;
            for (int i; i < nValue; i++) {
                temp = matrix9[i][0];
                matrix9[i][0] = matrix9[i][nValue-1];
                matrix9[i][nValue-1] = temp;
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix9[i][j];
				}
			}

          	matrix9[a][b] = -1;
			matrix9[c][d] = -2;
			matrix9[e][f] = -3;
			matrix9[g][h] = -4;

            // Print matrix9
            std::cout << "Board #9 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix9[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix9[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
        case 10: {
            // Create the initial matrix
            int matrix1[nValue][nValue];
            memset(matrix1, 0, sizeof(matrix1));

            int row = 0;
            int column = nValue / 2;

            // Populate the first matrix
            matrix1[row][column] = 1;

            for (int i = 2; i <= nValue * nValue; i++) {
                if (row - 1 < 0) {
                    row = nValue - 1;
                }
                else {
                    row--;
                }
                if (column + 1 == nValue) {
                    column = 0;
                }
                else {
                    column++;
                }
                if (matrix1[row][column] != 0) {
                    column--;
                    row +=2;
                    if (row - 1 < 0) {
                        row = nValue - 1;
                    }
                    if (row >= nValue) {
                        row = 1;
                    }
                    if (column < 0) {
                        column = nValue - 1;
                    }
                }
                matrix1[row][column] = i;
            }
            // Create and populate matrix10
            int matrix10[nValue][nValue];
            memset(matrix10, 0, sizeof(matrix10));
            int temp;
            for (int i = 0; i < nValue; i++) {
                for (int j = 0; j < nValue; j++) {
                    matrix10[j][i] = matrix1[nValue - 1 - i][j];
                }
            }
            for (int i; i < nValue; i++) {
                temp = matrix10[0][i];
                matrix10[0][i] = matrix10[nValue-1][i];
                matrix10[nValue-1][i] = temp;
            }

            // Storing the correct board into matrixOG
			for (int i = 0; i < nValue; i++) {
				for (int j = 0; j < nValue; j++) {
					matrixOG[i][j] = matrix1[i][j];
				}
			}

          	matrix10[a][b] = -1;
			matrix10[c][d] = -2;
			matrix10[e][f] = -3;
			matrix10[g][h] = -4;

            // Print matrix10
            std::cout << "Board #10 is:\n" << "\n";
            for (int i = 0; i < nValue; i++) {
                std::cout << "  ";
                for (int j = 0; j < nValue; j++) {
                    std::cout << matrix10[i][j];
                    std::cout << "  ";
                    matrix[i][j] = matrix10[i][j];
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            break;
        }
    }

    std::cout << "THE MATRIX is:\n" << "\n";
                for (int i = 0; i < nValue; i++) {
                    std::cout << "  ";
                    for (int j = 0; j < nValue; j++) {
                        std::cout << matrixOG[i][j];
                        std::cout << "  ";
                    }
                    std::cout << "\n";
                }
                std::cout << "\n";
    //START
    bool guess = true;

    // The while loop that continues until the player either wins or decides to quit
    while (guess) {

    		std::cout << "Here's your board:\n" << "\n";
    		for (int i = 0; i < nValue; i++) {
    			std::cout << "  ";
    	        	for (int j = 0; j < nValue; j++) {
    	        		if (matrix[i][j] < 0) {
    	        			std::cout << "X";
    	        		    std::cout << "  ";
    	        		}
    	        		else {
							std::cout << matrix[i][j];
							std::cout << "  ";
    	        		}
    	            }
    	            std::cout << "\n";
    	     }
    	     std::cout << "\n";

    	     //Coordinates for the user's position selection (x,y)
    	     std::string x;
    	     std::string y;
    	     int xCheck;
    	     int yCheck;

    	     std::cout << "Time to choose which box you would like to fill in!\n";

    	     // Checking for valid input of user-entered x coordinate
    	     bool checkInputX = false;
    	     while (!checkInputX) {
    	    	 std::cout << "How many squares to the right would you "
    	    	     	    		 "like to go? (Enter a number 0 through " << nValue - 1 << ")\n\n";

    	    	 std::cin >> x;

    	    	 // Converts the first character and second character of the x-coordinate string to an integer type
    	    	 // Only checks second character if the size of the string is greater than 1
    	    	 xCheck = x.at(0) - '0';

    	    	 /* 1. First char has to be a number
    	    	  * 2. Number can't be more than 2 characters long
    	    	  * 3. First char, when converted to int, CAN'T be greater than the magic square size MINUS 1
    	    	  * 4. Can't be less than 0
    	    	  */
    	    	 if (!isdigit(x.at(0)) || x.size() > 1 || xCheck > nValue - 1 || xCheck < 0) {

    	    		 std::cout << "ERROR: Invalid input. Please try again!\n";
    	    		 std::cin.ignore();
    	    		 std::cin.clear();
    	    		 continue;
    	    	 }

    	    	 else {
    	    		 if (xCheck == b || xCheck == d || xCheck == f || xCheck == h) {
						 checkInputX = true;
					 }
    	    		 else {
    	    			 std::cout << "Please try again! Choose an empty spot with an 'X' \n";
    	    		 }
    	    	 }
    	     }

    	     // Checking for valid input of user-entered y coordinate
			 bool checkInputY = false;
			 while (!checkInputY) {
				std::cout << "How many squares down would you "
							 "like to go? (Enter a number 0 through " << nValue - 1 << ")\n\n";

				std::cin >> y;

				// Converts the first and second character of the x-coordinate string to an integer type
				// Only checks second character if the size of the string is greater than 1
				yCheck = y.at(0) - '0';

				/* 1. First char has to be a number
			     * 2. Number can't be more than 2 characters long
			     * 3. First char, when converted to int, CAN'T be greater than the magic square size MINUS 1
			     * 4. Can't be less than 0
			     */
				if (!isdigit(y.at(0)) || y.size() > 1 || yCheck > nValue - 1 || yCheck < 0) {
					std::cout << "ERROR: Invalid input. Please try again!\n";
					std::cin.ignore();
					std::cin.clear();
					continue;
				}

				else {
					if (yCheck == a || yCheck == c || yCheck == e || yCheck == g) {
						checkInputY = true;
					}
					else {
						std::cout << "Please try again! Choose an empty spot with an 'X' \n";
					}
				}
			}


    	    bool guessingNum = true;

    	    // Loops until the user guesses the right number at the specified location on the board
    	    while (guessingNum) {
				std::cout << "You chose coordinate (" << xCheck << "," << yCheck << "). \n"
						"Now please enter your guess: \n";
				std::string numGuess;

				//Checking for valid input of user-entered guess
				bool checkInputNum = false;
				while (!checkInputNum) {

					std::cin >> numGuess;
					unsigned int i = 0;
					bool correctInput = true;

					while (i < numGuess.size() && correctInput) {
						if (!isdigit(numGuess.at(0))) {
							std::cout << "ERROR: Invalid input. Please try again!\n";
							std::cin.ignore();
							std::cin.clear();
							correctInput = false;
						}

						i++;
					}

					if (correctInput) {
						checkInputNum = true;
					}
				}

				//Converting the guess from a string to an integer
				std::stringstream toInt(numGuess);
				int numGuessInt = 0;
				toInt >> numGuessInt;

				std::cout << "GUESS: " << numGuessInt << "\n\n";
				std::cout << "ANSWER: " << matrixOG[yCheck][xCheck] << "\n\n";

				//Checking to see if the number matches the number in the correct magic square at that position
				if (numGuessInt == matrixOG[yCheck][xCheck]) {
					std::cout << "You are correct!!\n\n";
					matrix[yCheck][xCheck] = numGuessInt;
					guessingNum = false;
				}
				else {
					std::cout << "Sorry, but that's incorrect! Please try again\n\n";
				}


    	    }

     }
    //END


    return 0;
}
