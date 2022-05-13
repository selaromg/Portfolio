#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<char, string> mymap = {
		{'A', ".- "},
		{'B', " - ... "},
		{'C', "-.-. "},
		{'D', " - .. "},
		{'E', ". "},
		{'F', ".. - . "},
		{'G', "--. "},
		{'H', ".... "},
		{'I', ".. "},
		{'J', ".--- "},
		{'K', "-.- "},
		{'L', ".-.. "},
		{'M', "-- "},
		{'N', "-. "},
		{'O', "--- "},
		{'P', ".--. "},
		{'Q', "--.- "},
		{'R', ".-. "},
		{'S', "... "},
		{'T', "- "},
		{'U', "..- "},
		{'V', "...- "},
		{'W', ".-- "},
		{'X', "-..- "},
		{'Y', "-.-- "},
		{'Z', "--.. "},
		{'1', ".---- "},
		{'2', "..--- "},
		{'3', "...-- "},
		{'4', "....- "},
		{'5', "..... "},
		{'6', "-.... "},
		{'7', "--... "},
		{'8', "---.. "},
		{'9', "----. "},
		{'0', "----- "},
		{' ', "   "}

	};

	string sentence = "MY NAME IS GIGI AND I LOVE FC BARCELONA AND CANT WAIT FOR THEM TO PLAY ON SUNDAY";
	

	cout << sentence << endl;

	unsigned int i = 0;



	for (i; i < sentence.size(); i++) {
		cout << mymap.at(sentence[i]);
	}

}