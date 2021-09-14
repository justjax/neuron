#ifndef DATASET_H
#define DATASET_H

#include <eigen3/Eigen/Dense>

using Eigen::MatrixXf;
using Eigen::MatrixXi;

class Dataset
{
public:
    Dataset() = default;
    ~Dataset() = default;

    MatrixXf m_inputs;
    MatrixXi m_outputs;
    MatrixXi m_classes;
    int m_count;
    MatrixXf m_bias;
};

class Datasets
{
public:
    Datasets() = default;
    ~Datasets() = default;

private:
    int m_input_count;
    int m_output_count;
    Dataset m_training_set;
    Dataset m_validation_set;
    Dataset m_test_set;
};

#endif // DATASET_H
