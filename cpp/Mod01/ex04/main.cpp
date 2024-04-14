#include <iostream>
#include <string>
#include <fstream>

std::string    replacestring(std::string line, std::string rep_word, std::string rep_by)
{
    size_t pos = 0;
    while ((pos = line.find(rep_word, pos)) != std::string::npos)
    {
        line.erase(pos, rep_word.length());
        line.insert(pos, rep_by);
        pos += rep_by.length();
    }
    return(line);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong Arguments" << std::endl;
        return(0);
    }
    std::string ext = ".replace";
    std::string replace_word = argv[2]; 
    std::string replace_by = argv[3]; 
    std::ifstream read_file(argv[1]);
    if (!read_file.is_open())
    {
        std::cout << "WRONG FILE" << std::endl;
        exit(0);
    }
    std::ofstream write_file(argv[1]+ext);
    std::string line;
    while(std::getline(read_file, line)){
        write_file << replacestring(line, replace_word, replace_by);
        write_file << std::endl; 
    }
}