#include <vector>
#include <string>

std::string& leftTrim(std::string& str, const std::string chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::vector<std::string> split(std::string line, std::string delimiter)
{
    leftTrim(line, " ");
    size_t pos = 0;
    std::vector<std::string> entityDescription;
    while ( (pos = line.find(delimiter)) != std::string::npos)
    {
        entityDescription.push_back(line.substr(0, pos));
        line.erase(0, pos + delimiter.length());
    }
    if (!line.empty())
        entityDescription.push_back(line);

    return entityDescription;
}