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
	this->Size_Of_Map = size - 1;
	this->GameMap = new int* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		this->GameMap[i] = new int[size - 1];
		for (int j =0; j<size-1; j++){
			this->GameMap[i][j] = 0;
		}
	}
	int rand_i, rand_j;
	for (int i = 0; i < 25; i++) { // здесь на поле добавятся 25 мин
		do {
			rand_i = rand() % size;
			rand_j = rand() % size;
			if (this->GameMap[rand_i][rand_j] == 0) {
				this->GameMap[rand_i][rand_j] = 9;
				break;
			}
			else {
				continue;
			}
		} while (true);
	}
}
