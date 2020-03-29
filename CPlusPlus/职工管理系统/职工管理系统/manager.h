#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker
{
public:

	Manager(int id, string name, int did);

	//显示职位信息描述
	virtual void showInfo();

	virtual string getDeptName();



};