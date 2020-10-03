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
	srand(time(NULL));
	this->Size_Of_Map = size;
	this->GameMap = new int* [this->Size_Of_Map + 2];
	for (int i = 0; i < size + 2; i++) {
		this->GameMap[i] = new int[this->Size_Of_Map + 2];
		for (int j =0; j<size + 2; j++){
			this->GameMap[i][j] = 0;
		}
	}
	int rand_i, rand_j;
	this->FlagsIsRight = 0;
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
			/*if (this->opened_cells.find(std::make_pair(i, j))!= this->opened_cells.end())
				std::cout << this->GameMap[i][j] << ' ';
			else {
				if (this->GameMap[i][j] == 0 && this->opened_cells.find(std::make_pair(i, j)) != this->opened_cells.end())
					std::cout << "N" << ' ';
				else
					std::cout << "X" << ' ';
			}	*/
			if (this->GameMap[i][j] == 10) {
				std::cout << 'F' << ' ';
				continue;
			}
			if (this->opened_cells.find(std::make_pair(i, j)) == this->opened_cells.end()) {
				std::cout << 'X' << ' ';
			}
			else {
				if (this->GameMap[i][j] == 0) {
					std::cout << 'N' << ' ';
				}
				if (this->GameMap[i][j] > 0 && this->GameMap[i][j] < 9) {
					std::cout << this->GameMap[i][j] << ' ' ;
				}
				if (this->GameMap[i][j] == 9) {
					std::cout << 'M' << ' ';

				}
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
	if (this->GameMap[row][colum] == 10) {
		std::cerr << "That cell has alredy been marked a flag\n";
		Sleep(2000);
		return;
	}
	if (this->opened_cells.find(std::make_pair(row, colum)) != this->opened_cells.end()) {
		std::cerr << "That cell has alredy been opened\n";
		Sleep(2000);
		return;
	}
	switch (this->GameMap[row][colum])
	{
	case 0:
		std::cerr << "That cell cell is not a mine\n";
		this->Open_Null_Cells(row, colum);
		break;
	case 9:
		this->MinesNotDetected--; this->FlagsIsRight++;
		this->GameMap[row][colum] = 10;
		break;
	default:
		std::cerr << "That cell cell is not a mine\n";
		Sleep(2000);
		this->opened_cells.insert(std::make_pair(row, colum));
		if (this->MinesNotDetected == 0 || std::pow(this->Size_Of_Map, 2) - this->opened_cells.size() == this->MinesNotDetected + this->FlagsIsRight)
			this->win = true;
		break;
	}
}

void SaperGame::open_cell(int& row, int& colum)
{
	if (this->GameMap[row][colum] == 10) {
		std::cerr << "That cell has alredy been marked a flag\n";
		Sleep(2000);
		return;
	}
	if (this->opened_cells.find(std::make_pair(row, colum)) != this->opened_cells.end()) {
		std::cerr << "That cell has alredy been opened\n";
		Sleep(2000);

		return;
	}
	switch (this->GameMap[row][colum])
	{
	case 0:
		this->Open_Null_Cells(row, colum);
		break;
	case 9:
		this->opened_cells.insert(std::make_pair(row, colum));
		this->loose = true;
		break;
	default:
		this->opened_cells.insert(std::make_pair(row, colum));
		if (this->MinesNotDetected == 0 || std::pow(this->Size_Of_Map, 2) - this->opened_cells.size() == this->MinesNotDetected + this->FlagsIsRight)
			this->win = true;
		break;
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
