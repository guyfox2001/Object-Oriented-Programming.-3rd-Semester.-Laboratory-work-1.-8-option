#pragma once
#include <set>
#include <iostream>
#include <cmath>
/*
	0 - ��� ������ ����
	1 - ����� ��� ������ ������: 1
	2 - ����� ��� ������ ������: 2
	3 - ����� ��� ������ ������: 3
	4 - ����� ��� ������ ������: 4
	5 - ����� ��� ������ ������: 5 
	6 - ����� ��� ������ ������: 6 
	7 - ����� ��� ������ ������: 7
	8 - ����� ��� ������ ������: 8
	9 - ����
	10 - ������
*/

class SaperGame
{
	public:
		int** GameMap;	 // � �������� �������
		int Size_Of_Map; // � �������� �������
		int Counts_Of_Flag;
		bool loose, win;//�������� ��������� �� �� �� ���� ��� �������
		int MinesNotDetected;
		std::set <std::pair<int, int> > opened_cells;// ���� �������� �������� ������
		SaperGame(int& size); // ����������� ��.����������
		void start_game(); // �������� ����
		void print_map();
		void print_cheat_map();
		void insert_flag(int& row, int& colum);
		void open_cell(int& row, int& colum);

		void Open_Null_Cells(int row, int colum);

};

