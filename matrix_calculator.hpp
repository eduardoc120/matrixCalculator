#ifndef MATRIX_CALCULATOR_HPP
#define MATRIX_CALCULATOR_HPP

#include <vector>

class MatrixCalculator
{
    public:
        std::vector<std::vector<int> > sum(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2);
        std::vector<std::vector<int> > substract(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2);
        std::vector<std::vector<int> > multiply(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2);
        std::vector<std::vector<int> > divide(const std::vector<std::vector<int> > matrix1, const std::vector<std::vector<int> > matrix2);
};

#endif /* MATRIX_CALCULATOR_HPP */
