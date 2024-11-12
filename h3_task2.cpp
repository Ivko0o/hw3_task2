#include <iostream>
#include <string>
#include <new>

using namespace std;


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

		for (int i = 0; i < cryptation_Pairs; i++) {
	

			if (ch == letters[i]) {
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
		string text;
		getline(cin, text);

		letters[i] = text[0];

		words[i] = text.substr(2);
	}

}



