#include <iostream>
#include <eigen3/Eigen/Dense>
#include <sciplot/sciplot.hpp>

#include "DatasetParser.h"
#include "Dataset.h"

using namespace sciplot;
using namespace std;

Eigen::MatrixXi output_to_class(Eigen::MatrixXi output) {
    int rows_size = output.rows();
    int cols_size = output.cols();
    Eigen::Matrix<int, Eigen::Dynamic, 1> output_class(rows_size, 1);
    for (auto row_idx = 0; row_idx < rows_size; row_idx++) {
        int class_val = 1;
        for (auto col_idx = 0; col_idx < cols_size; col_idx++) {
            if (output(row_idx, col_idx) != 0) {
                output_class(row_idx, 0) = class_val;
                continue;
            }
            class_val++;
        }
    }
    return output_class;
}

Eigen::MatrixXi class_to_output(Eigen::MatrixXi class_vec)
{
    int row_size = class_vec.rows();
    int col_size = class_vec.maxCoeff();

    Eigen::MatrixXi out = Eigen::MatrixXi::Zero(row_size, col_size);
    for (auto row_idx = 0; row_idx < row_size; row_idx++) {
        int coef = class_vec(row_idx, 0);
        out(row_idx, coef - 1) = 1;
    }
    return out;
}

int main(int argc, char** argv)
{
    Eigen::MatrixXi mat(4,3);
    mat << 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0;
    cout << mat << endl;
    cout << "-------" << endl;

    Eigen::MatrixXi out = output_to_class(mat);
    cout << out << endl;

    Eigen::MatrixXi output = class_to_output(out);
    cout << "-------" << endl;
    cout << output << endl;

    DatasetParser parser("/home/justjack/workspace/NeuralNetwork/Neuron/data/iris_training.dat");
    parser.loadFile();
}
