#pragma once
#include <set>
#include <iostream>
#include <cmath>
#include <Windows.h>
#include <time.h>
/*
	0 - мин вокруг нету
	1 - колво мин вокруг клетки: 1
	2 - колво мин вокруг клетки: 2
	3 - колво мин вокруг клетки: 3
	4 - колво мин вокруг клетки: 4
	5 - колво мин вокруг клетки: 5 
	6 - колво мин вокруг клетки: 6 
	7 - колво мин вокруг клетки: 7
	8 - колво мин вокруг клетки: 8
	9 - мина
	10 - Флажок
*/

class SaperGame
{
	public:
		int** GameMap;	 // В принципе логично
		int Size_Of_Map; // В принципе логично
		int FlagsIsRight;
		int MinesNotDetected;
		bool loose, win;//Проверка наткнулся ли ты на мину или выйграл
		std::set <std::pair<int, int> > opened_cells;// Сюда пихаются открытые клетки
		SaperGame(int& size); // Конструткор см.реализацию
		void start_game(); // Основное меню
		void print_map();
		void print_cheat_map();
		void insert_flag(int& row, int& colum);
		void open_cell(int& row, int& colum);
		void Open_Null_Cells(int row, int colum);

};

