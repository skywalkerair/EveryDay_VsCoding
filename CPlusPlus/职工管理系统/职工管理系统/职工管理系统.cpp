#include "workerManager.h"
#include<iostream>
#include"worker.h"
#include"Employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	
		
	//ʵ���������߶���
	WorkerManager wm;
	
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳��������
			wm.exitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ����ְְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6://���ձ������
			break;
		case 7://��������ĵ�
			break;
		default://��������
			system("cls");
			break;
		}

	}
	
	
	

	system("pause");
	return 0;
}