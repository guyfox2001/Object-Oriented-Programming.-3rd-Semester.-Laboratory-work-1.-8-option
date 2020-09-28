#pragma once
#include <set>
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
		bool loose; //�������� ��������� �� �� �� ����
		std::set <std::pair<int, int> > opened_cells;// ���� �������� �������� ������
		SaperGame(int& size); // ����������� ��.����������
		void start_game(); // �������� ����
		void insert_random_mine();
		void insert_flag(int& row, int& colum);
		void open_cell(int& row, int& colum);

};

