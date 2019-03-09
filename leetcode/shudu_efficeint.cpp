/*
 * @Author: Skywalker
 * @Date: 2018-12-05 09:58:56
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:12:37
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

//function:judge the vector is the right
class Solution {
public:
    bool isValidSudoku(vector<vector<string> > &board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false));
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};

int main()
{
   vector<vector<string> >input=
    {
        {"8","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };

    Solution aa;
    bool m;
    m = aa.isValidSudoku(input);
    cout<< "result:"<<m<<endl;
    return 0;
}