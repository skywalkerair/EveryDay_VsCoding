#include"manager.h"
#include"worker.h"

Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptName = did;
}


void Manager::showInfo()
{
	cout << "经理的编号：" << this->m_ID
		<< "\t 经理姓名：" << this->m_Name
		<< "\t 岗位：" << this->getDeptName()
		<< "\t 岗位职责：提出需求，并布置任务..." << endl;

}

string Manager::getDeptName()
{

	return string("经理");
}