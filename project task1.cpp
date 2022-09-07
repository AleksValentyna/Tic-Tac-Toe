#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;


void board_show(char board[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << "     ";
		}
		cout << endl << endl;
	}
}


int main()
{
	cout << "   " << "Welcome to game!";
	cout << endl;
	cout << endl << " T I C -- T A C -- T O E -- G A M E" << endl;
	cout << "   " << "For player and computer" << endl;
	cout << endl;
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int x, y;
	bool userWin = false, compWin = false, tie = false, invalid = false;
	int move = 0;// переменная, кот отвечает за количество ходов
	const char player_mark = 'X', comp_mark = 'O', blank_mark = '*';
	char board[5][5] = {};
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			board[i][j] = blank_mark;

	do {
		if (invalid) {
			cout << "Invalid!!! Please select another cell and enter a number from 1 to 5" << endl << endl;
			invalid = false;
		}

	board_show(board);  //вивід поля з зірочками на екран

	cout << "You move. Please enter a number: ";
	cin >> x >> y;
	if (x >= 1 && y >= 1 && x <= 5 && y <= 5 && board[x - 1][y - 1] == blank_mark) {
		board[x - 1][y - 1] = player_mark; //тому що позиції в масиві починаються з "0", а не з "1"
		move++;

		if (move != 25) {
			do {
				x = rand() % 5; //0-4
				y = rand() % 5;
			} while (board[x][y] != blank_mark);
			board[x][y] = comp_mark;
			move++;
		}

		for (int i = 0; i <= 4; i++) {
			if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && 
				board[i][0] == board[i][4] && board[i][0] != blank_mark)
			{
				if (board[i][0] == player_mark) {
					userWin = true;
				}
				else {
					compWin = true;
				}
			}
			if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && 
				board[0][i] == board[4][i] && board[0][i] != blank_mark)
			{
				if (board[0][i] == player_mark) {
					userWin = true;
				}
				else {
					compWin = true;
				}
			}
		}
				
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && 
			board[0][0] == board[4][4] && board[0][0] != '*')
		{
			if (board[0][0] == player_mark) {
				userWin = true;
			}
			else {
				compWin = true;
			}

		}
		if (board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && 
			board[0][4] == board[4][0] && board[0][4] != blank_mark)
		{
			if (board[0][4] == player_mark) {
				userWin = true;
			}
			else {
				compWin = true;
			}

		}
	}
		else {
			invalid = true;
		}
			if (userWin == false && compWin == false && move == 25) {
			tie = true;
		}


		system("CLS"); //clining pole

	} while (userWin == false && compWin == false && tie == false);

	if (userWin == true) {
		cout << endl << "Congratulation! You have Won!" << endl;
		cout << endl;
	}
	if (compWin == true) {
		cout << "The Computer Won!" << endl;
		cout << endl;
	}
	
	if (tie == true) {
		cout << endl << "*** It's a draw! ***" << endl;
		cout << endl;

	}
	board_show(board);
	system("pause");
	return 0;
}






// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
