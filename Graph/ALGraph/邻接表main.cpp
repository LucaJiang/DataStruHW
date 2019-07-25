//graphmain.cpp
#include <iostream>
#include <string>
#include "ALGraph.cpp"
#include <fstream>
using namespace std;
const int MAXV = 40;

int main()
{
	//==================================================
	int numV;
	int arc[MAXV][MAXV];
	char name[MAXV];
	//read data
	fstream fin;
	cout << "Open file:";
	string filename;
	cin >> filename;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Can not open file:" << filename;
		cout << " Now, open file:data26.txt\n";
		fin.open("data26.txt");
	}
	if (!fin.fail())
	{
		cout << "Reading file:" << filename << "...\n";
		fin >> numV;
		for (int i = 0; i < numV; i++)
			for (int j = 0; j < numV ; j++)
			{
				fin >> arc[i][j];	
			}
		fin.close();
	}
	else
	{
		throw"can not open file";
	}

	for (int i = 0; i < numV; i++)
		name[i] = 'A' + i;

	//========================================================
//	int which;
//	int j;
//	string name;
	int choose = 1;
//	string a[5] = { "����","�廪","����","���ִ�ѧ","��������" };
	ALGraph<char> algraphTest(name, numV, MaxSize, arc);        //����ͼ
// 	while (choose == 1)                                      //����
// 	{
// 		cout << "��Ҫ���������Ϣ�밴0" << endl;		         //������Ҫ���еĲ��������
// 		cout << "��Ҫ�������һ��������Ϣ�밴1" << endl;
// 		cout << "��Ҫ���붥���밴2" << endl;
// 		cout << "��Ҫ�޸Ķ����밴3" << endl;
// 		cout << "��Ҫɾ�������밴4" << endl;
// 		cout << "��Ҫ������ȱ����밴5" << endl;
// 		cout << "��Ҫ������ȱ����밴6" << endl;
// 		cout << "��Ҫ�˳��밴7" << endl;
// //		cin >> which;
// // 		switch (which)                                        //����ѡ��
// // 		{
// // 		case 0:
// // 			for (j = 0; j < numV; j++)
// // 				cout << algraphTest.GetVex(j) << " ";              //�������
// // 			cout << endl;
// // 			break;
// // 		case 1:
// // 			int i;
// // 			cout << "�����붥�㣺" << endl;
// // 			cin >> i;
// // 			try
// // 			{
// // 				cout << algraphTest.GetVex(i) << endl;              //���i�����������
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 2:                                               //��ͼ�е�iλ�ò���һ����ֵΪname
// // 			cout << "�����붥�㼰���֣�" << endl;
// // 			cin >> i >> name;
// // 			try
// // 			{
// // 				//algraphTest.InsertVex(i, name);
// // 
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 3:                                               //�޸�ͼ��һ�����ֵ
// // 			cout << "�����붥�㼰���֣�" << endl;
// // 			cin >> i >> name;
// // 			try
// // 			{
// // 				//algraphTest.PutVex(i, name);
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 4:                                               //ɾ��ͼ��һ�����ֵ
// // 			cout << "�����붥�㣺" << endl;
// // 			cin >> i;
// // 			try
// // 			{
// // 				algraphTest.DeleteVex(i);
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 5:                                               //ͼ�������������
// // 			cout << "�����붥�㣺" << endl;
// // 			cin >> i;
// // 			cout << endl << "�ӵ�" << i << "������������ȱ���ͼ" << endl;
// // 			try
// // 			{
// // 				for (int ii = 0; ii < MaxSize; ii++) algraphTest.visited[ii] = 0;
// // 				algraphTest.DFSTraverse(i);
// // 			}
// // 			catch (char* s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 6:                                               //ͼ�Ĺ����������
// // 			cout << "�����붥�㣺" << endl;
// // 			cin >> i;
// // 			cout << endl << "�ӵ�" << i << "�����������ȱ���ͼ" << endl;
// // 			try
// // 			{
// // 				for (int ii = 0; ii < MaxSize; ii++) algraphTest.visited[ii] = 0;
// // 				algraphTest.BFSTraverse(i);
// // 			}
// // 			catch (char*s)
// // 			{
// // 				cout << s << endl;
// // 			}
// // 			break;
// // 		case 7:                                             //�˳�
// // 			choose = 0;
// // 			break;
// // 		}
// 	}

	cout << "matrix\n";
	algraphTest.List2Matrix();
	cout << "degree0:";
	cout<<algraphTest.CountOutdegree0();
	cout << "\n";
	algraphTest.InverseList();
	cout << "\nDFS:";
	algraphTest.DFS_nonrec();
	cout << endl;
	cout << algraphTest.hasPath_BFS(0, 3) << endl;
	cout << algraphTest.hasPath_DFS(0, 3) << endl;

	system("pause");
	return 0;
}
