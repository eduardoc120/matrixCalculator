#include <iostream>
#include <vector>
#include <algorithm>
#include "matrix_calculator.hpp"
#include "matrix_calculator.cpp"

using namespace std;

bool validateIntInput() {
    // Validation of the integer input
    if (cin.fail()) 
    {
        cout << "Invalid input. Please enter a valid integer." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

bool validateInputSize(int& data) 
{
    // validation of the matrix size that have to be more than 1
    if (!validateIntInput())
    {
        return false;
    }
    if (data < 1)
    {
        cout << "Error: the matrix should have at least 1 row and 1 column" << endl;
        return false;
    }
    return true;
}

int main()
{
    MatrixCalculator calculator;

    while (true)
    {
        int option = 0;

        cout << "Welcome to the matrix calculator!\n";
        cout << "--------------------------------------\n\n";
        cout << "1. Add\n2. Substract\n3. Multiply\n4. Divide\n5. Exit\n\n";
        cout << "Enter your choice: ";

        cin >> option;

        int options[] = {1, 2, 3, 4};

        int n = sizeof(options) / sizeof(*options);
 
        bool exists = find(options, options + n, option) != options + n;

        if (option == 5)
        {
            cout << "\nThank you for using the Matrix Calculator!\n";
            break;
        }

        if (!exists) {
            cout << "Invalid option" << endl;
            continue;
        }

        int rows = 0;
        int columns = 0;

    
        do 
        {
            cout << "Enter the number of matrix rows: ";
            cin >> rows;
        }
        while (!validateInputSize(rows));

        do 
        {
            cout << "Enter the number of matrix columns: ";
            cin >> columns;
        }
        while (!validateInputSize(columns));

        vector<vector<vector<int> > > matrix(2, vector<vector<int> >(rows, vector<int>(columns)));
        vector<vector<int> > resultMatrix(rows, std::vector<int>(columns));


        // Filling the matrix with user inputs

        cout << "Enter the items to the matrix" << endl;
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int p = 0; p < columns; p++)
                {
                    int input = 0;

                    do {
                        cout << "Matrix " << j+1;
                        cout << " Location (" << i << "," << p << "): ";
                        cin >> input;
                    } while (!validateIntInput());

                    matrix[j][i][p] = input;
                }
            }
        }


        switch (option)
        {
            case 1:
                resultMatrix = calculator.sum(matrix[0], matrix[1]);
                break;
            case 2:
                resultMatrix = calculator.substract(matrix[0], matrix[1]);
                break;
            case 3:
                resultMatrix = calculator.multiply(matrix[0], matrix[1]);
                break;
            case 4:
                resultMatrix = calculator.divide(matrix[0], matrix[1]);
                break;   
            default:
                cout << "Invalid option" << endl;
                break;
        }

        
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                if (i == 0) {
                    cout << "[ ";
                }
                for (int p = 0; p < rows; p++)
                {
                    if (p == 0) {
                        cout << "[ ";
                    }
                    cout << matrix[j][i][p] << " ";
                    if (p+1 == columns) {
                        cout << "] ";
                    }
                }
                if (i+1 == columns) {
                    cout << "]";
                }
            }
            if (j == 0) {
                cout << " + ";
            }
        }

        cout << " = ";
        for (int i = 0; i < columns; i++)
        {
            if (i == 0) {
                cout << "[ ";
            }
            for (int p = 0; p < rows; p++)
            {
                if (p == 0) {
                    cout << "[ ";
                }
                cout << resultMatrix[i][p] << " ";
                if (p+1 == columns) {
                    cout << "] ";
                }
                
            }
            if (i+1 == columns) {
                cout << "]";
            }
        }

        cout << endl;
        
    }

    

    return 0;
}
