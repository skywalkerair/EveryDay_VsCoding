#include"boss.h"
#include"worker.h"

Boss::Boss(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptName = did;
}


void Boss::showInfo()
{
	cout << "老板的编号：" << this->m_ID
		<< "\t 老板 姓名：" << this->m_Name
		<< "\t 岗位：" << this->getDeptName()
		<< "\t 岗位职责：规划整个公司的发展方向..." << endl;

}

string Boss::getDeptName()
{

	return string("老板");
}