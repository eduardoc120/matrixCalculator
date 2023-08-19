#include "../matrix_calculator.hpp"

#include <gtest/gtest.h>
#include <vector>

using namespace std;

MatrixCalculator calculator;

TEST(calcTests, sumMatrix) {

    vector<vector<int>> matrix1 = {{10, 20}};
    vector<vector<int>> matrix2 = {{10, 20}};
    vector<vector<int>> expected1 = {{20, 40}};

    vector<vector<int>> matrix3 = {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}};
    vector<vector<int>> matrix4 = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    vector<vector<int>> expected2 = {{11, 22, 33, 44, 55, 66, 77, 88, 99, 110}};

    vector<vector<int>> matrix5 = {{1, 3}};
    vector<vector<int>> matrix6 = {{1}};

    vector<vector<int>> result1 = calculator.sum(matrix1, matrix2);
    vector<vector<int>> result2 = calculator.sum(matrix3, matrix4);

    EXPECT_EQ(expected1, result1);
    EXPECT_EQ(expected2, result2);
    EXPECT_THROW(calculator.sum(matrix5, matrix6), runtime_error);
}

TEST(calcTests, substractMatrix) {
    
    vector<vector<int>> matrix1 = {{20, 40}};
    vector<vector<int>> matrix2 = {{10, 20}};
    vector<vector<int>> expected1 = {{10, 20}};

    vector<vector<int>> matrix3 = {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}};
    vector<vector<int>> matrix4 = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    vector<vector<int>> expected2 = {{9, 18, 27, 36, 45, 54, 63, 72, 81, 90}};
    
    vector<vector<int>> matrix5 = {{1, 3}};
    vector<vector<int>> matrix6 = {{1}};

    vector<vector<int>> result1 = calculator.substract(matrix1, matrix2);
    vector<vector<int>> result2 = calculator.substract(matrix3, matrix4);

    EXPECT_EQ(expected1, result1);
    EXPECT_EQ(expected2, result2);
    EXPECT_THROW(calculator.substract(matrix5, matrix6), runtime_error);
}

TEST(calcTests, MultiplyMatrix) {

    vector<vector<int>> matrix1 = {{5, 7}};
    vector<vector<int>> matrix2 = {{3, 2}};
    vector<vector<int>> expected1 = {{15, 14}};

    vector<vector<int>> matrix3 = {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}};
    vector<vector<int>> matrix4 = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    vector<vector<int>> expected2 = {{10, 40, 90, 160, 250, 360, 490, 640, 810, 1000}};

    vector<vector<int>> matrix5 = {{1, 3}};
    vector<vector<int>> matrix6 = {{1}};

    vector<vector<int>> result1 = calculator.multiply(matrix1, matrix2);
    vector<vector<int>> result2 = calculator.multiply(matrix3, matrix4);

    EXPECT_EQ(expected1, result1);
    EXPECT_EQ(expected2, result2);
    EXPECT_THROW(calculator.multiply(matrix5, matrix6), runtime_error);
}

TEST(calcTests, DivideMatrix) {

    vector<vector<int>> matrix1 = {{10, 6}};
    vector<vector<int>> matrix2 = {{2, 3}};
    vector<vector<int>> expected1 = {{5, 2}};

    vector<vector<int>> matrix3 = {{2, 6}};
    vector<vector<int>> matrix4 = {{0, 3}};

    vector<vector<int>> matrix5 = {{4, 6, 8, 10, 12, 14, 16, 18, 20, 24}};
    vector<vector<int>> matrix6 = {{2, 3, 4, 5, 6, 7, 8, 9, 10, 12}};
    vector<vector<int>> expected3 = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};

    vector<vector<int>> matrix7 = {{1, 3}};
    vector<vector<int>> matrix8 = {{1}};

    vector<vector<int>> result1 = calculator.divide(matrix1, matrix2);
    vector<vector<int>> result3 = calculator.divide(matrix5, matrix6);

    EXPECT_EQ(expected1, result1);
    EXPECT_THROW(calculator.divide(matrix3, matrix4), runtime_error);
    EXPECT_EQ(expected3, result3);
    EXPECT_THROW(calculator.divide(matrix7, matrix8), runtime_error);

}
