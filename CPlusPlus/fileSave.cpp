#include<fstream>
using namespace std;

int main()
{
    ofstream outputFile;
    outputFile.open("test.txt");

    int a = 1;
    outputFile << "Hello"<<endl;
    outputFile << a <<endl;
    outputFile.close();

    return 0;
}