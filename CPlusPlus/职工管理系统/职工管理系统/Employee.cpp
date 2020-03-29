#include"Employee.h"


//构造函数
Employee::Employee(int id, string name, int did)
{
	//this 指针为什么放在这里
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptName = did;
}


void Employee::showInfo()
{
	cout << "职工的编号：" << this->m_ID
		<< "\t 职工姓名：" << this->m_Name
		<< "\t 岗位：" << this->getDeptName()
		<< "\t 岗位职责：完成经理交给的工作任务..." << endl;

}

string Employee::getDeptName()
{

	return string("员工");
}