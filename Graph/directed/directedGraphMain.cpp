//ʵ���2019-05-20 ʵ���2019-05-27 ʵ��ʮ2019-06-03
//��������ͼ(��Ȩ��)���ڽӾ���ʵ��ͼ�ĸ����㷨;
//����޸�2019-06-06
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "directedGraph.cpp"
using namespace std;

int main()
{//Init
	int numV;
	int arc[MAXV*MAXV];
	//read data
	fstream fin;
	cout << "Open file:";
	string filename;
	cin >> filename;
	fin.open(filename);
	if (!fin.is_open())
	{
		cout << "Can not open file:"<<filename;
		cout << " Now, open file:datasp.txt\n";
		filename = "datasp.txt";
		fin.open(filename);
	}
	if (!fin.fail())
	{
		cout << "Reading file:"<<filename<<"...\n";
		fin >> numV;
		for (int i = 0; i < numV*numV; i++)
			fin >> arc[i];
	}
	else
		throw"can not open file";
	
	string name[MAXV];
	if (fin.get()!=-1)
	{
		for (int i = 0; i < numV ; i++)
			fin >> name[i];
	} 
	else
	{
		char tempname[2] = {'0','\0'};
		for (int i = 0; i < numV ; i++)
		{
			tempname[0] = 'A' + i;
			name[i] = tempname;
		}
	}
	directedGraph<string, int>mygraph(numV, name, arc);
	fin.close();
	//------------------------- ��һ��------------------------------
// 	if(!mygraph.isCity())
// 	{
// 		mygraph.Info();
// 		cout << "DFS:";
// 		mygraph.Traverse(0, 1);
// 		cout << "BFS:";
// 		mygraph.Traverse(0, 0);
// 		cout << "D&BFS:";
// 		mygraph.Traverse(0, 0.4);
// 		cout << "DFS_Tree:\n";
// 		mygraph.DFS_T(0);
// 	}
// 	//--------------------------�ڶ���-----------------------------
// 	cout << "Prim:\n";
// 	mygraph.Prim();
// 	cout << "Kruskal:\n";
// 	mygraph.Kruskal();
// 	cout << "another method of MST\n";
// 	mygraph.BreakCycle();
// 	//��������������ڽӾ����Ϊ��С���������ڽӾ���
// 	//--------------------------������-------------------------------
// 	cout << "Approximate TSP:\n";
// 	mygraph.Traverse(0, 1);
//------------------------------ʵ��ʮ��һ��--------------------------
	cout << "Dijkstra:\n";
	mygraph.Dijkstra(1);
	cout << "\nFloyd:\n";
	mygraph.Floyd();
	  
	system("pause");
	return 0;
}
