#include "DatasetParser.h"
#include "Dataset.h"

#include <eigen3/Eigen/Dense>

#include <fstream>
#include <iostream>
#include <sstream>

DatasetParser::DatasetParser(const std::string& filename) : m_filename(filename)
{
    std::ifstream ifs;
    ifs.open(m_filename);
    m_file_rows = std::count(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>(), '\n');
    std::cout << "Lines count " << m_file_rows << std::endl;
    ifs.close();
}

Dataset DatasetParser::parseFile()
{
    Dataset dataset;
    std::ifstream ifs;
    ifs.open(m_filename);

    std::string line;
    int row_idx = 0, col_idx = 0;
    int first_output_index = 4;
    Eigen::MatrixXf input_mat(m_file_rows, 4);
    Eigen::MatrixXi output_mat(m_file_rows, 3);

    while (std::getline(ifs, line)) {
        std::stringstream ss(line);
        float val;
        while (ss >> val) {
            std::cout << val << std::endl;
            if (col_idx < first_output_index) {
                input_mat(row_idx, col_idx) = val;
                std::cout << input_mat(row_idx, col_idx) << std::endl;
            } else {
                output_mat(row_idx, col_idx - 4) = val;
            }
            col_idx += 1;
        }
        row_idx += 1;
        col_idx = 0;
    }

    ifs.close();

    dataset.m_inputs = input_mat;
    dataset.m_outputs = output_mat;

    std::cout << input_mat << std::endl;

    return dataset;
}
