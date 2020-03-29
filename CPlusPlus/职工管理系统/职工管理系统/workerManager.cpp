#include "workerManager.h"
#include"worker.h"
#include"Employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{

	//1. �ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ�������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.���ļ�����������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��..." << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ�������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;

	}

	//3.�ļ����ڣ����Ҽ�¼����
	int num = this->getEmpNum();
	//cout << "ְ������Ϊ��" << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->init_Emp();

	/*for (int i = 0;i<this->m_EmpNum;i++)
	{
		cout << "ְ����ţ�"     << this->m_EmpArray[i]->m_ID
			 << "������"         << this->m_EmpArray[i]->m_Name
			 << "ְ����λ��ţ�" << this->m_EmpArray[i]->m_DeptName << endl;
	}*/

}

//��ʼ������
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
			//��ͨԱ��
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
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}

}

//ͳ���ļ�������
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in); //���ļ� ���ļ�

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
	cout << "************  ��ӭʹ��ְ������ϵͳ  ************" << endl;
	cout << "************     0. �˳��������    ************" << endl;
	cout << "************     1. ����ְ����Ϣ    ************" << endl;
	cout << "************     2. ��ʾְ����Ϣ    ************" << endl;
	cout << "************     3. ɾ����ְְ��    ************" << endl;
	cout << "************     4. �޸�ְ����Ϣ    ************" << endl;
	cout << "************     5. ����ְ����Ϣ    ************" << endl;
	cout << "************     6. ���ձ������    ************" << endl;
	cout << "************     7. ��������ĵ�    ************" << endl;
	cout << "************************************************" << endl;

}
//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
 
//������ְ��
void WorkerManager::Add_Emp()
{
	cout << "��������Ҫ��ӵ�Ա��������" << endl;
	
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
			cout << "�������" << i + 1 << "��ְ���ı�ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ����������" << endl;
			cin >> name;

			cout << "�������ְ���ĸ�λ:" << endl;
			cout << "1. ��ͨԱ�� " << endl;
			cout << "2. ���� " << endl;
			cout << "3. �ϰ� " << endl;
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
		//�����ļ���״̬���Ƿ����
		this->m_FileIsEmpty = false;

		cout << "���ְ���ɹ���" << endl;

		this->save();

	}
	else
	{
		cout << "������������������..." << endl;
	
	}
	

	system("pause");
	system("cls");

}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0;i<m_EmpNum;i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");

}

//�����ļ�
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


//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ��ְ��
		cout << "��������Ҫɾ���б�ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)
		{
			//˵����Ҫɾ�������ְ��
			for (int i = index;i<this->m_EmpNum-1; i++)
			{
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//��������
			//����ͬ�����ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
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

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << " �������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//�ͷŲ��ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;

			cout << "�������µ�������" << endl;
			cin >> newName;

			cout << "�������λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;

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

			//�������� ��������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;

			//������ļ���
			this->save();

		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	system("pause");
	system("cls");

}

//����ְ��
void WorkerManager::Find_Emp()
{

	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			//�����ж��Ƿ�鵽�ı�־
			bool flag = false;

			for (int i = 0;i<m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_EmpArray[i]->m_ID
						<< "��ְ����Ϣ���£�" << endl;
					flag = true;


					//������ʾ��Ϣ�ӿ�
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag = false)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
	}

	system("pause");
	system("cls");

}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1. ��ְ���Ž�������" << endl;
		cout << "2. ��ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0;i<m_EmpNum;i++)
		{
			int minOrMax = i;

			for (int j = i + 1;j < m_EmpNum;j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMax]->m_ID >this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else			//����
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

		cout << " ����ɹ��������Ľ��Ϊ��"<< endl;
		this->save();
		this->Show_Emp();

	}

}

//����ļ��Ĳ���
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ļ�
		ofstream ofs(FILENAME,ios::trunc); //ɾ���ļ�֮�����´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i<this->m_EmpNum;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}

		//ɾ����������ָ��
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;

	}


	cout << "��ճɹ���" << endl;

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