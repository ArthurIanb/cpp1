#include <iostream>
#include <map>
#include <ctime>
#include <string>
using namespace std;


map<string, string> phrases = 
{
	{"listening to cds", "������� �����"},
	{"going to art galleries", "������ � �������"},
	{"painting pictures", "�������� �������"},
	{"reading books/magazines", "������ ����� / �������"},
	{"going to the cinema", "������ � ����"},
	{"eating out", "�������"},
	{"designing your own clothes", "��������� ����������� ������"},
	{"writing novels", "������ ������"},
	{"watching dvds", "�������� ���"},
	{"going to fashion shows", "������ �� ������ ����"},
	{"watching a game", "�������� ����"},
	{"playing computer games", "������ � ���� ����"},
	{"working out at a gym", "������������� � ����"},
	{"playing a musical instrument", "������ �� ����������� �����������"}
	

};

map<string, string>::iterator getPhraseNumber(int k)
{
	setlocale(0, "ru");
	map<string, string>::iterator iter = phrases.begin();
	for (int i = 0; i < k-1; i++)
		iter++;
	return iter;
}

int getRandTo14()
{
	return rand() % 14+1;
}

void Work()
{
	char st[200];
	setlocale(0, "ru");
	while (true) {
		map<string, string>::iterator randPhrases = getPhraseNumber(getRandTo14());
		cout << "Phrase on russia: " << randPhrases->second;
		cout << "\nAns: ";
		
		cin.getline(st, 200, '\n');
		if (strcmp(st, "s")==0)
			continue;
		if(strcmp(st, "e") == 0)
			break;
		if (st == randPhrases->first)
			cout << "Correct\n";
		else
		{
			cout << "The correct: " << randPhrases->first << '\n';
		}
	}
}



int main()
{
	srand(time(NULL));
	
	Work();
	
	return 0;
}

