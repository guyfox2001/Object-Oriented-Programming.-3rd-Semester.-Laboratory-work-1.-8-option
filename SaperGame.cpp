#include "SaperGame.h"

SaperGame::SaperGame(int& size)
{
	/*
		Конструткор это плюшка,
		которая сразу определит в данном случае
		размер поля, создаст поле по указателю,
		и зарандомит расположение мин.Если интересно 
		и нужно спроси потом сам
	*/
	this->Size_Of_Map = size;
	this->GameMap = new int* [this->Size_Of_Map + 2];
	for (int i = 0; i < size + 2; i++) {
		this->GameMap[i] = new int[this->Size_Of_Map + 2];
		for (int j =0; j<size + 2; j++){
			this->GameMap[i][j] = 0;
		}
	}
	int rand_i, rand_j;
	this->MinesNotDetected = (int)(size * size / 5);
	for (int i = 0; i < this->MinesNotDetected; i++) { // здесь на поле добавятся 25 мин
		do {
			rand_i = rand() % size + 1;
			rand_j = rand() % size + 1;
			if (this->GameMap[rand_i][rand_j] == 0) {
				this->GameMap[rand_i][rand_j] = 9;
				break;
			}
			else {
				continue;
			}
		} while (true);
	}
	for (int i = 1; i < size+1; i++) {
		for (int j = 1, countMines = 0; j < size+1; j++) {
			if (this->GameMap[i][j] != 9) {
				if (this->GameMap[i - 1][j] == 9)countMines++;    // Проверка соседних ячеек
				if (this->GameMap[i - 1][j - 1] == 9)countMines++;// Проверка соседних ячеек
				if (this->GameMap[i - 1][j + 1] == 9)countMines++;// Проверка соседних ячеек
				if (this->GameMap[i][j + 1] == 9)countMines++;	  // Проверка соседних ячеек
				if (this->GameMap[i][j - 1] == 9)countMines++;	  // Проверка соседних ячеек
				if (this->GameMap[i + 1][j] == 9)countMines++;	  // Проверка соседних ячеек
				if (this->GameMap[i + 1][j + 1] == 9)countMines++;// Проверка соседних ячеек
				if (this->GameMap[i + 1][j - 1] == 9)countMines++;// Проверка соседних ячеек
				this->GameMap[i][j] = countMines;
				countMines = 0;
			}
		}
	}
}

void SaperGame::start_game()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "Добро пожаловать в сапёр!\n";
}

void SaperGame::print_map()
{
	system("cls");
	for (int i = 1; i < this->Size_Of_Map+1; i++) {
		for (int j = 1; j < this->Size_Of_Map+1; j++) {
			if (this->opened_cells.find(std::make_pair(i, j))!= this->opened_cells.end())
				std::cout << this->GameMap[i][j] << ' ';
			else {
				if (this->GameMap[i][j] == 0 && this->opened_cells.find(std::make_pair(i, j)) != this->opened_cells.end())
					std::cout << "N" << ' ';
				else
					std::cout << "X" << ' ';
			}	
		}
		std::cout << '\n';
	}

}

void SaperGame::print_cheat_map()
{
	for (int i = 1; i < this->Size_Of_Map + 1; i++) {
		for (int j = 1; j < this->Size_Of_Map + 1; j++) {
			std::cout << this->GameMap[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void SaperGame::insert_flag(int& row, int& colum)
{

}

void SaperGame::open_cell(int& row, int& colum)
{
	if (this->GameMap[row][colum] == 0)this->Open_Null_Cells(row, colum);
	if (this->GameMap[row][colum] == 9)this->loose = true;
	if (this->GameMap[row][colum] > 0 && this->GameMap[row][colum] < 9) {
		this->opened_cells.insert(std::make_pair(row, colum));
	}
	if (std::pow(this->Size_Of_Map, 2) - this->opened_cells.size() == this->MinesNotDetected) {
		this->win = true;
	}
}

void SaperGame::Open_Null_Cells(int row, int colum)
{
	if (this->opened_cells.find(std::make_pair(row, colum)) == this->opened_cells.end()) {
		if (this->GameMap[row][colum] != 0) {
			this->opened_cells.insert(std::make_pair(row, colum));
			return;
		}
		else {
			this->opened_cells.insert(std::make_pair(row, colum));
			if (row - 1 != 0)Open_Null_Cells(row - 1, colum);
			if (row + 1 != this->Size_Of_Map + 1)Open_Null_Cells(row + 1, colum);
			if (colum + 1 != this->Size_Of_Map + 1)Open_Null_Cells(row, colum + 1);
			if (colum - 1 != 0)Open_Null_Cells(row, colum - 1);
			if (row - 1 != 0 && colum - 1 != 0) Open_Null_Cells(row - 1, colum - 1);
			if (row - 1 != 0 && colum + 1 != this->Size_Of_Map + 1) Open_Null_Cells(row - 1, colum + 1);
			if (row + 1 != this->Size_Of_Map + 1 && colum - 1 != 0) Open_Null_Cells(row + 1, colum - 1);
			if (row + 1 != this->Size_Of_Map + 1 && colum + 1 != this->Size_Of_Map + 1) Open_Null_Cells(row + 1, colum + 1);
			return;
		}
	}
}
