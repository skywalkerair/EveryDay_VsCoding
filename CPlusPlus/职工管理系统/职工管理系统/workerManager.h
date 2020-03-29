/*
	����������
	1. ���û���ͨ�Ĳ˵�����
	2. ��ְ����ɾ�Ĳ����
	3. ���ļ��Ķ�д����
*/
#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include"worker.h"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//��ʾ�˵�
	void Show_Menu();

	//0.�˳�ϵͳ
	void exitSystem();

	//1.������ְ��
	void Add_Emp();

	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա���������ָ��
	Worker ** m_EmpArray;

	void save();

	//�ж��ļ��Ƿ�Ϊ���ļ��ı�־
	bool m_FileIsEmpty;

	//����ļ����ڣ�ͳ���ļ��е�����
	int getEmpNum();

	//��ʼ������
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();
};