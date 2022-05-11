#include <iostream>
#include <map>
#include <ctime>
#include <string>
using namespace std;


map<string, string> phrases = 
{
	{"listening to cds", "слушать диски"},
	{"going to art galleries", "ходить в галереи"},
	{"painting pictures", "рисовать картины"},
	{"reading books/magazines", "читать книги / журналы"},
	{"going to the cinema", "ходить в кино"},
	{"eating out", "обедать"},
	{"designing your own clothes", "дизайнить собственную одежду"},
	{"writing novels", "писать романы"},
	{"watching dvds", "смотреть двд"},
	{"going to fashion shows", "ходить на показы моды"},
	{"watching a game", "смотреть игру"},
	{"playing computer games", "играть в комп игры"},
	{"working out at a gym", "тренироваться в зале"},
	{"playing a musical instrument", "играть на музыкальном инструменте"}
	

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

