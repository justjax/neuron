#include "DatasetParser.h"

#include <eigen3/Eigen/Dense>

#include <fstream>
#include <iostream>
#include <sstream>

DatasetParser::DatasetParser(const std::string& filename) : m_filename(filename)
{

}

void DatasetParser::loadFile()
{
    std::ifstream ifs;
    ifs.open(m_filename);

    std::string line;
    int row_idx = 0, col_idx = 0;
    Eigen::MatrixXf mat;

    while (std::getline(ifs, line)) {

        std::stringstream ss(line);
        float val;

        while (ss >> val) {
            std::cout << val << std::endl;
//            mat(row_idx, col_idx) = val;
            col_idx += 1;
        }
        row_idx += 1;
        col_idx = 0;
    }

    ifs.close();
}
