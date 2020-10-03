#include <iostream>
#include "SaperGame.h"
using namespace std;

int main() {
	int size;
	cout << "Enter the size of the playing field\n";
	cin >> size;
	SaperGame game(size);
	while (true)// гейм луп
	{
		game.print_map();
		int row, column, oper = 0;
		while (true)
		{
			cout << "Enter an action \n";
			cout << "1. Insert Flag\n";
			cout << "2. Open Cell\n";
			cin >> oper;
			if (oper != 1 && oper != 2) { cout << "ERROR! Reenter an action\n"; continue; }
			break;
		}
		switch (oper) {
		case 1:
			while (true)
			{
				cout << "Enter a cell (first a row, then a column)\n";
				cin >> row >> column;
				if (row > size) {
					cerr << "ERROR! You entered a rows value greater than " << size << '\n';
					continue;
				}
				if (column > size) {
					cerr << "ERROR! You entered a colums value greater than " << size << '\n';
					continue;
				}
				break;
			}
			game.insert_flag(row, column);
			break;
		case 2:
			while (true)
			{
				cout << "Enter a cell (first a row, then a column)\n";
				cin >> row >> column;
				if (row > size) {
					cerr << "ERROR! You entered a rows value greater than " << size << '\n';
					continue;
				}
				if (column > size) {
					cerr << "ERROR! You entered a colums value greater than " << size << '\n';
					continue;
				}
				break;
			}
			game.open_cell(row, column);
			break;
		}
		if (game.loose == true) {
			game.print_map();
			cout << "You're loose!!!\n";
			break;
		}
		if (game.win == true) {
			game.print_map();
			cout << "You're win!!!\n";
			break;
		}
	}
	system("pause");
}