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
	cout << "����ı�ţ�" << this->m_ID
		<< "\t ����������" << this->m_Name
		<< "\t ��λ��" << this->getDeptName()
		<< "\t ��λְ��������󣬲���������..." << endl;

}

string Manager::getDeptName()
{

	return string("����");
}