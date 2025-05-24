#include <iostream>
#include <fstream>
#include <string>

void replaceLine(const std::string& filename, const std::string& searchLine, const std::string& newLine) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Failed to open input file: " << filename << std::endl;
        return;
    }

    std::ofstream tempFile("temp.txt");
    if (!tempFile) {
        std::cerr << "Failed to create temporary file." << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    bool replaced = false;

    while (std::getline(inputFile, line)) {
        if (line == searchLine) {
            tempFile << newLine << std::endl;
            replaced = true;
        } else {
            tempFile << line << std::endl;
        }
    }

    inputFile.close();
    tempFile.close();

    if (!replaced) {
        std::cerr << "Line not found in the file." << std::endl;
        std::remove("temp.txt");
        return;
    }

   

    std::cout << "Line replaced successfully." << std::endl;
}

int main()
{
    std::string filename = "database.txt";
    std::string searchLine = "Shaheer";
    std::string newLine = "This is the replacement line";

    replaceLine(filename, searchLine, newLine);

    return 0;
}