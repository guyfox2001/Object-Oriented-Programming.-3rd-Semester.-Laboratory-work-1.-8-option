#include <iostream>
#include "SaperGame.h"
using namespace std;

int main() {
	int size = 19;
	SaperGame game(size);
	game.print_map();
	for (int i = 0; i < 5; ++i) {
		int ii, jj;
		cin >> ii >> jj;
		game.open_cell(ii, jj);
		game.print_map();
		cout << endl;
		/*game.print_cheat_map();*/
	}
}