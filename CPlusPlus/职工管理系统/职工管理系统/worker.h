/*
	ְ�����ࣺ��ͨԱ���������ϰ�
	������ְ������һ���ࣨworker���У����ö�̬����ְͬ������
	ְ�������ԣ�ְ����ţ�ְ��������ְ�����ڲ��ű��
	ְ������Ϊ����λְ����Ϣ��������ȡ��λ����
*/

#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ��������
class Worker
{
public:

	//��Ϊ��
	//��ʾְλ��Ϣ����
	virtual void showInfo() = 0;

	//��ȡ��λ������
	virtual string getDeptName() = 0;


	//ְ�����
	int m_ID;
	//ְ������
	string m_Name;
	//ְ�����ڵĲ���
	int  m_DeptName;
};