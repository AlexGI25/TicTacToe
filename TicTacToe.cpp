#include <iostream>
#include <string>
using namespace std;

char mapa[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
int row;
int coloana;
string player1 = " ";
string player2 = " ";
char token = 'X';
bool egal=false;

void initializare()
{
	


	cout << "   |   |   " << endl;
	cout << " " << mapa[0][0] << " | " << mapa[0][1] << " | " << mapa[0][2] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << mapa[1][0] << " | " << mapa[1][1] << " | " << mapa[1][2] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;
	cout << " " << mapa[2][0] << " | " << mapa[2][1] << " | " << mapa[2][2] << endl;
	cout << "   |   |   " << endl;

}

void function()
{
	int digit;
	if (token == 'X')
	{
		cout << player1 << " please enter!";
			cin >> digit;
	}
	if (token == '0')
	{
		cout << player2 << " please enter!";
		cin >> digit;
	}
	if (digit == 1)
	{
		row = 0;
		coloana = 0;
		
	}
	if (digit == 2)
	{
		row = 0;
		coloana = 1;

	}
	if (digit == 3)
	{
		row = 0;
		coloana = 2;

	}
	if (digit == 4)
	{
		row = 1;
		coloana = 0;

	}
	if (digit == 5)
	{
		row = 1;
		coloana = 1;

	}
	if (digit == 6)
	{
		row = 1;
		coloana = 2;

	}
	if (digit == 7)
	{
		row = 2;
		coloana = 0;

	}
	if (digit == 8)
	{
		row = 2;
		coloana = 1;

	}
	if (digit == 9)
	{
		row = 2;
		coloana = 2;

	}
	else if(digit<1||digit>9)
	{
		cout << "Invalid choice!" << endl;
	}
	if (token == 'X' && mapa[row][coloana] != 'X' && mapa[row][coloana]!='0')
	{
		mapa[row][coloana] = 'X';
		token = '0';
	}
	else	if (token == '0' && mapa[row][coloana] != 'X' && mapa[row][coloana] != '0')
	{
		mapa[row][coloana] = '0';
		token = 'X';
	}
	else
	{
		cout << "There is no empty space!" << endl;
		function();
	}
	initializare();


}
bool functionthree()
{
	for (int i = 0; i < 3; i++)
	{
		if (mapa[i][0] == mapa[i][1] && mapa[i][0] == mapa[i][2] || mapa[0][i] == mapa[1][i] && mapa[0][i] == mapa[2][i])
			return true;
	}
	if (mapa[0][0] == mapa[1][1] && mapa[0][0] == mapa[2][2] || mapa[0][2] == mapa[1][1] && mapa[0][2] == mapa[2][0])
		return true;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (mapa[i][j] != 'X' && mapa[i][j] != '0')
			{
				return false;
			}
		}
	}
	
	 egal = true;
	 return false;
}

int main()
{
	cout << "Enter the name of the first player: ";
	getline(cin, player1);
	cout << "Enter the name of the second player: ";
	getline(cin, player2);
	cout << player1 << " plays first!" << endl;
	cout << player2 << " plays second!" << endl;
	initializare();
	while (!functionthree())
	{
		
		function();
		functionthree();

	}
	if (token == 'X' && egal == false)
	{
		cout << player2 << " wins!!!" << endl;
	}
	else if (token == '0' && egal == false)
	{
		cout << player1 << " wins!!!" << endl;
	}
	else
	{
		cout << "There is a draw!" << endl;
	}
}