#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <stdio.h>

using namespace std;

bool perevirka(char* fname);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[51];
	cout << "Введіть назву фізичного файлу: ";
	cin.getline(fname, sizeof(fname));
	cout << endl;

	bool b = perevirka(fname);

	if (b)
		cout << "Так є серед цих символів пара сусідніх букв “SQ” або ”QS”." << endl;
	else
		cout << "Ні не має серед цих символів пара сусідніх букв “SQ” або ”QS”." << endl;

	return 0;
}

bool perevirka(char* fname)
{
	FILE* perev_f;

	if ((perev_f = fopen(fname, "r")) == NULL)
	{
		cerr << "Помилка відкриття фізичного файлу '" << fname << "'" << endl;
		exit(1);
	}

	const int size = 41;
	char lit_r[size];

	while (!feof(perev_f))
	{
		fgets(lit_r, size - 1, perev_f);
		cout << "Літерний рядок зчитаний з фізичного файлу: ";
		cout << lit_r << endl << endl;
	}

	for (int i = 0; i < strlen(lit_r); i++)
	{
		if ((lit_r[i] == 'Q' && lit_r[i + 1] == 'S') || (lit_r[i] == 'S' && lit_r[i + 1] == 'Q'))
			return true;
	}
	return false;
}