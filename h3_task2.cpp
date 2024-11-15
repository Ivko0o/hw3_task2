#include <iostream>
#include <string>
#include <new>

using namespace std;

char toLower(char ch);
void Table(char*& letters, string*& words, int& cryptation_Pairs);
void TextEncryption(char* letters, string* words, int cryptation_Pairs);

int main() {

	char* letters = nullptr;
	string* words = nullptr;
	int cryptation_Pairs = 0;

	Table(letters, words, cryptation_Pairs);
	TextEncryption(letters, words, cryptation_Pairs);


	delete[] letters;
	delete[] words;
}

void TextEncryption(char* letters, string* words, int cryptation_Pairs) {
	string user_Text;

	cout << "Enter the text that you want to encrypt" << endl;
	getline(cin, user_Text);

	for (char ch : user_Text){

		bool found = false;
		char lower_ch = toLower(ch);

		for (int i = 0; i < cryptation_Pairs; i++) {
	

			if (lower_ch == letters[i]) {
				cout << words[i];
				found = true;
				break;
			}
		}
		if (!found) {
			cout << ch;
		}

	}

}


//This fucntion creates the cryptation table
void Table(char*& letters, string*& words, int& cryptation_Pairs) {

	//This will be used to create the number of pairs
	cout << "Enter a number of cryptation pairs to be created: ";
	cin >> cryptation_Pairs;
	cin.ignore();

	letters = new char[cryptation_Pairs];
	words = new string[cryptation_Pairs];

	cout << "Enter cryptation pairs (e.g. a ala): " << endl;
	for (int i = 0; i < cryptation_Pairs; i++) {
		while (true) {
			string text;
			getline(cin, text);

			if (text.length() < 3 || text[1] != ' ') {
				cout << "Error: Input must be in the format 'a ala'. Try again:";
				continue;
			}

			letters[i] = toLower(text[0]);
			string word = text.substr(2);

			if (word.length() < 1 || word.length() > 10) {
				cout << "Error: The word must be between 1 and 10 characters. Try again: " << endl;
				continue;
			}

			words[i] = word;
			break;
		}
	}

}

//This is needed so the program doesn`t make difference between upper and lower case letters
char toLower(char ch) {
	if (ch >= 'A' && ch <= 'Z') {
		return ch + ('a' - 'A');  
	}
	return ch;
}


