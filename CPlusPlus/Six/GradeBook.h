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
    void inputGrades_five();
    void displayGradeReport_five() const;

    //Chapter 6
    int maximun(int,int,int) const;
    void inputGrades_six();
    void displayGradeReport_six() const;


private:
    std::string courseName;

    //Chapter 5
    unsigned int aCount;
    unsigned int bCount;
    unsigned int cCount;
    unsigned int dCount;
    unsigned int fCount;

    //Chapter 6
    int maximumGrade;
};

