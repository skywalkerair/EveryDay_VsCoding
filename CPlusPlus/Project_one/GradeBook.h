/*
 * @Author: Skywalker
 * @Date: 2019-02-17 16:34:06
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2019-03-04 21:22:38
 * @Description: Head file
 * @Version: Version_1.0
 */
#include<string>

class GradeBook
{
public:
    explicit GradeBook(std::string);
    //GradeBook(std::string,std::string);

    //course
    void setCourseName(std::string);
    std::string getCourseName() const;
    void displayMessage() const;
    void determineClassAverage() const;
    //chapter 5
    void inputGrades();//input arbitrary number of gredes from user
    void displayGradeReport() const;
    
private:
    std::string courseName;
    unsigned int aCount;
    unsigned int bCount;
    unsigned int cCount;
    unsigned int dCount;
    unsigned int eCoune;
    
};

