#include "matrix_calculator.hpp"
#include <vector>
#include <stdexcept>

std::vector<std::vector<int> > MatrixCalculator::sum(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        throw std::runtime_error("Different matrix sizes");
    }

    const int rows = matrix1.size();
    const int columns = matrix1[0].size();

    std::vector<std::vector<int> > resultMatrix(rows, std::vector<int>(columns));


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return resultMatrix;
}

std::vector<std::vector<int> > MatrixCalculator::substract(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2)
{

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        throw std::runtime_error("Different matrix sizes");
    }

    const int rows = matrix1.size();
    const int columns = matrix1[0].size();

    std::vector<std::vector<int> > resultMatrix(rows, std::vector<int>(columns));


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return resultMatrix;
}

std::vector<std::vector<int> > MatrixCalculator::multiply(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2)
{
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        throw std::runtime_error("Different matrix sizes");
    }

    const int rows = matrix1.size();
    const int columns = matrix1[0].size();

    std::vector<std::vector<int> > resultMatrix(rows, std::vector<int>(columns));


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }

    return resultMatrix;
}

std::vector<std::vector<int> > MatrixCalculator::divide(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2)
{

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        throw std::runtime_error("Different matrix sizes");
    }

    const int rows = matrix1.size();
    const int columns = matrix1[0].size();

    std::vector<std::vector<int> > resultMatrix(rows, std::vector<int>(columns));


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix2[i][j] != 0) {
                resultMatrix[i][j] = matrix1[i][j] / matrix2[i][j];
            } else {
                throw std::runtime_error("Divisor cannot be zero");
            }
            
        }
    }

    return resultMatrix;
}
