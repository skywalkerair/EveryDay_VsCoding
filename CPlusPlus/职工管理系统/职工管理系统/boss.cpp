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
	cout << "�ϰ�ı�ţ�" << this->m_ID
		<< "\t �ϰ� ������" << this->m_Name
		<< "\t ��λ��" << this->getDeptName()
		<< "\t ��λְ�𣺹滮������˾�ķ�չ����..." << endl;

}

string Boss::getDeptName()
{

	return string("�ϰ�");
}