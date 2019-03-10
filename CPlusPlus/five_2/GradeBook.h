#include<string>

class GradeBook
{
public:
    explicit GradeBook(std::string);
    void setCourseName(std::string);
    std::string getCourseName() const;
    void displayMessage() const;
    void determineClassAverage() const;

    //Chapter 5
    void inputGrades();
    void displayGradeReport() const;


private:
    std::string courseName;

    //Chapter 5
    unsigned int aCount;
    unsigned int bCount;
    unsigned int cCount;
    unsigned int dCount;
    unsigned int fCount;
};

