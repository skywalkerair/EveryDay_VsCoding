/*
	创建管理类
	1. 与用户沟通的菜单界面
	2. 对职工增删改查操作
	3. 与文件的读写交互
*/
#pragma once   //防止头文件重复包含
#include<iostream>
using namespace std;
#include"worker.h"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//显示菜单
	void Show_Menu();

	//0.退出系统
	void exitSystem();

	//1.增加新职工
	void Add_Emp();

	//记录文件中的人数个数
	int m_EmpNum;

	//员工共数组的指针
	Worker ** m_EmpArray;

	void save();

	//判断文件是否为空文件的标志
	bool m_FileIsEmpty;

	//如果文件存在，统计文件中的人数
	int getEmpNum();

	//初始化数组
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();
};