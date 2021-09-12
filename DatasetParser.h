#ifndef DATASET_H
#define DATASET_H

#include <string>

class DatasetParser
{
public:
    DatasetParser() = default;
    ~DatasetParser() = default;

    DatasetParser(const std::string& filename);

    void loadFile();

private:
    const std::string m_filename;
};

#endif // DATASET_H
