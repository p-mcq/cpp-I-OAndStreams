#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

std::fstream fileToCheck;
std::string wordToMatch = "";
bool caseSensitive = false;
int wordCount = 0;
std::vector<std::string> matchingWords;

bool TryOpenFile(const std::string &fileName)
{
    fileToCheck.open(fileName, std::ios::in);
    if (!fileToCheck)
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return false;
    }
    return true;
}

std::string ToLower(const std::string &word)
{
    std::string lowerWord = word;
    for (char &c : lowerWord)
    {
        c = std::tolower(c);
    }
    return lowerWord;
}

void DebugCheckWordForMatch(std::string word, std::string wordToMatch)
{
    if (!caseSensitive)
    {
        word = ToLower(word);
        wordToMatch = ToLower(wordToMatch);
    }

    // check to see of word to match is contained inside of word
    if (word.find(wordToMatch) != std::string::npos)
    {
        std::cout << "Match found: " << wordToMatch << " is in " << word << std::endl;
    }
    else
    {
        std::cout << "Match not found: " << wordToMatch << " is not in " << word << std::endl;
    }
}

void CheckWordForMatch(std::string &word)
{
    if (!caseSensitive)
    {
        word = ToLower(word);
        wordToMatch = ToLower(wordToMatch);
    }
    // check to see of word to match is contained inside of word
    if (word.find(wordToMatch) != std::string::npos)
    {
        matchingWords.push_back(word);
        wordCount++;
    }
}

void ReadFile()
{
    // Count how many words are in the file in total
    int totalWordCount = 0;
    std::string line;
    while (std::getline(fileToCheck, line))
    {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            CheckWordForMatch(word);
            totalWordCount++;
        }
    }
    std::cout << "Total words in file: " << totalWordCount << std::endl;
    std::cout << "The word " << wordToMatch << " was found " << wordCount << " times." << std::endl;
    for (std::string word : matchingWords)
    {
        std::cout << word << std::endl;
    }
}

void UserInputAndParameters()
{
    std::cout << "Enter the word to match: ";
    std::cin >> wordToMatch;

    std::cout << "Would you like the search to be case sensitive? (y/n): ";
    char caseSensitiveResponse;
    std::cin >> caseSensitiveResponse;
    if (caseSensitiveResponse == 'y')
    {
        caseSensitive = true;
    }
    else
    {
        caseSensitive = false;
    }
}

int main()
{
    UserInputAndParameters();

    // Open the file for reading
    if (!TryOpenFile("romeoandjuliet.txt"))
    {
        return 1;
    }

    ReadFile();

    fileToCheck.close();
    return 0;
}
