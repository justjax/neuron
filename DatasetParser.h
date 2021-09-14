#ifndef DATASET_PARSER_H
#define DATASET_PARSER_H

#include "Dataset.h"

#include <string>

class DatasetParser
{
public:
    DatasetParser() = default;
    ~DatasetParser() = default;

    DatasetParser(const std::string& filename);

    Dataset parseFile();

private:
    const std::string m_filename;
    int m_file_rows;
    int m_file_columns = 7;
};

#endif // DATASET_PARSER_H
