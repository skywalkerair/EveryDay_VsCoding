#include "workerManager.h"
#include"worker.h"
#include"Employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{

	//1. 文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组的指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.当文件存在且数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空..." << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组的指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}

	//3.文件存在，并且记录数据
	int num = this->getEmpNum();
	//cout << "职工人数为：" << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->init_Emp();

	/*for (int i = 0;i<this->m_EmpNum;i++)
	{
		cout << "职工编号："     << this->m_EmpArray[i]->m_ID
			 << "姓名："         << this->m_EmpArray[i]->m_Name
			 << "职工岗位编号：" << this->m_EmpArray[i]->m_DeptName << endl;
	}*/

}

//初始化数组
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker * worker = NULL;
		if (did == 1)
		{
			//普通员工
			worker = new Employee(id,name,did);
		}
		else if (did == 2)
		{
			worker = new Manager(id,name,did);
		}
		else
		{
			worker = new Boss(id,name,did);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}

}

//统计文件中人数
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in); //打开文件 读文件

	int id;
	string name;
	int did;
	int num = 0;

	while (ifs >> id && ifs>>name && ifs>>did)
	{
		num++;
	}


	return num;
}


void WorkerManager::Show_Menu()
{
	cout << "************************************************" << endl;
	cout << "************  欢迎使用职工管理系统  ************" << endl;
	cout << "************     0. 退出管理程序    ************" << endl;
	cout << "************     1. 增加职工信息    ************" << endl;
	cout << "************     2. 显示职工信息    ************" << endl;
	cout << "************     3. 删除离职职工    ************" << endl;
	cout << "************     4. 修改职工信息    ************" << endl;
	cout << "************     5. 查找职工信息    ************" << endl;
	cout << "************     6. 按照编号排序    ************" << endl;
	cout << "************     7. 清空所有文档    ************" << endl;
	cout << "************************************************" << endl;

}
//退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
 
//增加新职工
void WorkerManager::Add_Emp()
{
	cout << "请输入需要添加的员工个数：" << endl;
	
	int addNum = 0;

	cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;

		Worker ** newSpace = new Worker*[newSize];
		
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i<this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		for (int i = 0; i<addNum; i++)
		{
			int id;
			string name;
			int did;
			cout << "请输入第" << i + 1 << "个职工的编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
			cin >> name;

			cout << "请输入该职工的岗位:" << endl;
			cout << "1. 普通员工 " << endl;
			cout << "2. 经理 " << endl;
			cout << "3. 老板 " << endl;
			cin >> did;

			Worker * worker = NULL;

			switch (did)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id,name,3);
				break;
			}
		
			newSpace[this->m_EmpNum + i] = worker;
		}
		
		delete[]this->m_EmpArray;

		this->m_EmpArray = newSpace;

		this->m_EmpNum = newSize;
		//更新文件的状态，是否存在
		this->m_FileIsEmpty = false;

		cout << "添加职工成功！" << endl;

		this->save();

	}
	else
	{
		cout << "输入有误，请重新输入..." << endl;
	
	}
	

	system("pause");
	system("cls");

}

//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0;i<m_EmpNum;i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");

}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for (int i = 0;i<this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << ""
			<< this->m_EmpArray[i]->m_DeptName << ""
			<< endl;
	}

	ofs.close();

}


//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
		//按照职工编号删除职工
		cout << "请输入想要删除中编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			//说明需要删除掉这个职工
			for (int i = index;i<this->m_EmpNum-1; i++)
			{
				//数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新数组
			//数据同步到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工！" << endl;
		}
	}

	system("pause");
	system("cls");

}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0;i <this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			return i;
			break;
		}
	}
	return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << " 请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//释放查找到编号的职工
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新的姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;

			cin >> dSelect;

			Worker *worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId,newName,dSelect);
				break;
			case 2:
				worker = new Manager(newId,newName,dSelect);
				break;
			case 3:
				worker = new Boss(newId,newName,dSelect);
				break;
			default:
				break;
			}

			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功！" << endl;

			//保存进文件中
			this->save();

		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}

	system("pause");
	system("cls");

}

//查找职工
void WorkerManager::Find_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//找到职工
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}

		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			//加入判断是否查到的标志
			bool flag = false;

			for (int i = 0;i<m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工编号为："
						<< this->m_EmpArray[i]->m_ID
						<< "号职工信息如下：" << endl;
					flag = true;


					//调用显示信息接口
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag = false)
			{
				cout << "查找失败，查无此人！" << endl;
			}

		}
		else
		{
			cout << "输入的选项有误！" << endl;
		}
	}

	system("pause");
	system("cls");

}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1. 按职工号进行升序" << endl;
		cout << "2. 按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0;i<m_EmpNum;i++)
		{
			int minOrMax = i;

			for (int j = i + 1;j < m_EmpNum;j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_ID >this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else			//降序
				{
					if (this->m_EmpArray[minOrMax]->m_ID <this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}

			if (i!=minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		
		}

		cout << " 排序成功！排序后的结果为："<< endl;
		this->save();
		this->Show_Emp();

	}

}

//清空文件的操作
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1. 确认" << endl;
	cout << "2. 返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME,ios::trunc); //删除文件之后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i<this->m_EmpNum;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		//删除堆区数组指针
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

	}


	cout << "清空成功！" << endl;

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0;i<this-> m_EmpNum;i++)
		{
			if (this->m_EmpArray[i]!=NULL)
			{
				delete this->m_EmpArray[i];
			}
			
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}