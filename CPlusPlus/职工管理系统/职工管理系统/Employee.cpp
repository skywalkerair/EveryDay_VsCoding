#include"Employee.h"


//���캯��
Employee::Employee(int id, string name, int did)
{
	//this ָ��Ϊʲô��������
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptName = did;
}


void Employee::showInfo()
{
	cout << "ְ���ı�ţ�" << this->m_ID
		<< "\t ְ��������" << this->m_Name
		<< "\t ��λ��" << this->getDeptName()
		<< "\t ��λְ����ɾ������Ĺ�������..." << endl;

}

string Employee::getDeptName()
{

	return string("Ա��");
}