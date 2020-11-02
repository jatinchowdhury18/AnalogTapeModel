#include <fstream>
#include <vector>
#include <string>
#include <sstream>

namespace load_csv {

template<typename T>
std::vector<std::vector<T>> loadFile(std::ifstream& stream)
{
    std::vector<std::vector<T>> vec;

    std::string line;
    if(stream.is_open()) {
        while(std::getline(stream, line)) {
            std::stringstream ss(line);

            std::string number;
            std::vector<T> lineVec;
            while(std::getline(ss, number, ','))
                lineVec.push_back(static_cast<T>(std::stod(number)));

            vec.push_back(lineVec);
        }
            
        stream.close();
    }

    return vec;
}

} // namespace load_csv
