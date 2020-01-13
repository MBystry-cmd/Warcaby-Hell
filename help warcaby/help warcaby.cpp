#include <iostream>
using namespace std;
int kolejnosc = 1;
char tab[8][8] = { ' ','o',' ','o',' ','o',' ','o',
  'o', ' ','o', ' ','o', ' ','o', ' ',
  ' ','o',' ','o',' ','o',' ','o',
  ' ', ' ',' ',' ',' ',' ',' ',' ',
  ' ', ' ',' ',' ',' ',' ',' ',' ',
  'x',' ','x',' ','x',' ','x',' ',
  ' ','x',' ','x',' ','x',' ','x',
  'x',' ','x',' ','x',' ','x',' ',
};
void RysujPlansze() {
	int i, j;
	cout << "    1   2   3   4   5   6   7   8 " << endl;
	for (i = 0; i < 8; i++)
	{
		cout << "  ---------------------------------" << endl;
		cout << i + 1;
		for (j = 0; j < 8; j++)
		{
			cout << " | ";
			cout << tab[i][j];
		}
		cout << " | " << endl;
	}
	cout << "  ---------------------------------" << endl;
}
void RuchBialych() {
	int x1, x2, y1, y2;
	cout << "Wiersz pionka:" << endl;
	cin >> x1;
	x1--;

	cout << "Kolumna pionka:" << endl;
	cin >> y1;
	y1--;
	if (tab[x1][y1] == 'o') {
		cout << "Do jakiego wiersza" << endl;
		cin >> x2;
		x2--;
		cout << "Do jakiej kolumny" << endl;
		cin >> y2;
		y2--;
		if (tab[x2][y2] == ' ')
		{
			if (((x2 - x1 == -1) && (y2 - y1 == 1)) || ((x2 - x1 == 1) && (y2 - y1 == -1)) || ((x2 - x1 == 1) && (y2 - y1 == 1)))
			{

				tab[x1][y1] = ' ';
				tab[x2][y2] = 'o';
			}
			else 
			{ 
				cout << "Pionek moze ruszac sie tylko o 1 na ukos" << endl;
				kolejnosc--;
			}
		}
		else {
			if (tab[x2][y2] == 'o') {

				cout << "Wybrane pole jest zajete przez twojego pionka" << endl;
				kolejnosc--;
			}
			else {
				if ((tab[x2][y2] == 'x') && (tab[x2++][y2++] == ' ')) {
					tab[x1][y1] = ' ';
					tab[x2][y2] = ' ';
					tab[x2++][y2++] = 'o';
				}

			}
		}
	}
	else {

		cout << "Wybierz bialego pionka" << endl;
		kolejnosc--;
	}

}
void RuchCzarnych() {
	int x1, x2, y1, y2;
	cout << "Wiersz pionka:" << endl;
	cin >> x1;
	x1--;

	cout << "Kolumna pionka:" << endl;
	cin >> y1;
	y1--;
	if (tab[x1][y1] == 'x') {
		cout << "Do jakiego wiersza" << endl;
		cin >> x2;
		x2--;
		cout << "Do jakiej kolumny" << endl;
		cin >> y2;
		y2--;
		if (tab[x2][y2] == ' ')
		{
			if (((x2 - x1 == -1) && (y2 - y1 == 1)) || ((x2 - x1 == 1) && (y2 - y1 == -1)) || ((x2 - x1 == 1) && (y2 - y1 == 1)))
			{

				tab[x1][y1] = ' ';
				tab[x2][y2] = 'x';
			}
			else { cout << "Pionek moze ruszac sie tylko o 1 na ukos" << endl; }
		}
		else {
			if (tab[x2][y2] == 'x') {

				cout << "Wybrane pole jest zajete przez twojego pionka" << endl;
			}
			else {
				if ((tab[x2][y2] == 'o') && (tab[x2++][y2++] == ' ')) {
					tab[x1][y1] = ' ';
					tab[x2][y2] = ' ';
					tab[x2++][y2++] = 'x';
				}

			}
		}
	}
	else {

		cout << "Wybierz czarnego pionka" << endl;
	}

}




int main()
{
	int x1, y1, x2, y2;
	RysujPlansze();
	do {
		kolejnosc++;
		if (kolejnosc % 2 == 0) {
			RuchBialych();

		}
		else {
			RuchCzarnych();
		}


		RysujPlansze();
	} while (1);
	


}
