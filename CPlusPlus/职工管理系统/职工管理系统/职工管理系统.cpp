#include "workerManager.h"
#include<iostream>
#include"worker.h"
#include"Employee.h"
#include"manager.h"
#include"boss.h"

int main()
{
	
		
	//实例化管理者对象
	WorkerManager wm;
	
	int choice = 0;

	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出管理程序
			wm.exitSystem();
			break;
		case 1://增加职工信息
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://删除离职职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://按照编号排序
			break;
		case 7://清空所有文档
			break;
		default://清屏操作
			system("cls");
			break;
		}

	}
	
	
	

	system("pause");
	return 0;
}