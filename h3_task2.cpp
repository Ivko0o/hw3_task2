#include <iostream>
#include <string>
#include <new>

using namespace std;

char toLower(char ch);
void CryptationTable(char*& letters, string*& words, int& cryptation_Pairs);
void TextEncryption(char* letters, string* words, int cryptation_Pairs);
void DecryptingText(string* words, char* letters, int cryptation_Pairs);

int main() {

	char* letters = nullptr;
	string* words = nullptr;
	int cryptation_Pairs = 0;

	CryptationTable(letters, words, cryptation_Pairs);
	TextEncryption(letters, words, cryptation_Pairs);
	DecryptingText(words, letters, cryptation_Pairs);


	delete[] letters;
	delete[] words;
}

//This fucntion creates the cryptation table
void CryptationTable(char*& letters, string*& words, int& cryptation_Pairs) {

	//This will be used to create the number of pairs
	cout << "Enter a number of cryptation pairs to be created: ";
	cin >> cryptation_Pairs;
	cin.ignore();

	letters = new char[cryptation_Pairs];
	words = new string[cryptation_Pairs];

	//This will be used to create the pairs
	cout << "Enter cryptation pairs (e.g. a ala): " << endl;
	for (int i = 0; i < cryptation_Pairs; i++) {
		while (true) {
			string text;
			getline(cin, text);

			if (text.length() < 3 || text[1] != ' ') {
				cout << "Error: Input must be in the format 'a ala'. Try again:" << endl;
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

// This function encrypts the given text
void TextEncryption(char* letters, string* words, int cryptation_Pairs) {
	int number_Of_Lines = 0;

	cout << "Enter the number of lines that you want to encrypt: ";
	cin >> number_Of_Lines;
	cin.ignore();
	cout << endl;

	for (int a = 0; a < number_Of_Lines; a++) {
		cout << "Enter the text that you want to crypt: ";
			string user_Text;
			getline(cin, user_Text);

			//This checks if the entered text is smaller then a 1000 symbols
			while (true) {
				if (user_Text.length() > 1000 || user_Text.length() == 0) {
					cout << "Too many words! Try again!" << endl;
					getline(cin, user_Text);
				}
					break;
			}

			for (char ch : user_Text) {

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
			cout << endl << endl;
		}

}

//This function will take some crypted text and decrypt it
void DecryptingText(string* words, char* letters, int cryptation_Pairs) {

	int number_Of_Lines = 0;

	cout << "Enter the number of lines that you want to de-crypt: ";
	cin >> number_Of_Lines;
	cin.ignore(); 

	for (int a = 0; a < number_Of_Lines; a++) {
		string user_Text;
		cout << "Enter the encrypted text to de-crypt it: ";
		getline(cin, user_Text);

		//This checks if the entered text is smaller then a 1000 symbols
		while (true) {
			if (user_Text.length() > 1000 || user_Text.length() == 0) {
				cout << "Too many words! Try again!" << endl;
				getline(cin, user_Text);
			}
			break;
		}

		string decrypted_Text = "";

		for (int i = 0; i < user_Text.length(); ) {
			bool matched = false;

			for (int j = 0; j < cryptation_Pairs; j++) {
				if (user_Text.substr(i, words[j].length()) == words[j]) {
					decrypted_Text += letters[j];
					i += words[j].length(); 
					matched = true;
					break;
				}
			}

			if (!matched) {
				decrypted_Text += user_Text[i];
				i++; 
			}
		}

		cout << "Decrypted text: " << decrypted_Text << endl;
	}
	

}


