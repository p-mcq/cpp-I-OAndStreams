#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

std::fstream responseFile;

// Test Formatting
const int totalWidth{38};
const int nameWidth{19};
const int gradeWidth{19};

bool TryOpenFile()
{
    responseFile.open("responses.txt", std::ios::in);
    if (!responseFile)
    {
        std::cerr << "File could not be opened" << std::endl;
        return false;
    }
    return true;
}

std::string GetAnswers()
{
    std::string answers{""};
    if (std::getline(responseFile, answers))
    {
        return answers;
    }
    return "";
}

std::tuple<std::string, std::string> GetStudent()
{
    std::string _studentName{""};
    std::string _studentAnswers{""};

    std::getline(responseFile, _studentName);
    std::getline(responseFile, _studentAnswers);

    return std::make_tuple(_studentName, _studentAnswers);
}

void GradeStudent(const std::string _answers, const std::string _studentName, const std::string _studentGrades)
{
    int correctAnswers{0};

    for (int i = 0; i < _studentGrades.length(); i++)
    {
        if (_answers[i] == _studentGrades[i])
        {
            correctAnswers++;
        }
    }

    std::string grade{std::to_string(correctAnswers) + "/" + std::to_string(_studentGrades.length())};

    std::cout << std::left << std::setw(nameWidth) << _studentName
              << std::right << std::setw(gradeWidth) << grade << std::endl;
}

int main()
{
    if (!TryOpenFile())
    {
        return 1;
    }

    std::string answers{GetAnswers()};
    std::string studentName{""};
    std::string studentGrades{""};

    std::cout << std::left << std::setw(nameWidth) << "Student Name"
              << std::right << std::setw(gradeWidth) << "Student Grades" << std::endl;

    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    while (!responseFile.eof())
    {
        std::tie(studentName, studentGrades) = GetStudent();
        GradeStudent(answers, studentName, studentGrades);
    }

    std::cout << std::setw(totalWidth) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    responseFile.close();
    return 0;
}
