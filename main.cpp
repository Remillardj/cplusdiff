using namespace std;
#include<string>
#include<iostream>
#include<fstream>


string word_compare(string words, int &end_location) {

	int twospace = 0;
	string word_one = "",
		   word_two = "";
	end_location = words.length();
	for (int i = 0; i <= words.length(); i++) {
		if (words[i] == ' ') {
			word_one = words.substr(0, i);
			word_two = words.substr(i + 1, words.length());
			if (word_one == word_two) 
				return word_one;
		}
	}
	return words;
}

string get_two_words(string format, int &offset) {
	int temp = 0;

	int length = format.length();
	if (offset >= length)
		return "";

	int twospace = 0;

	int i = offset;

	while (twospace != 2 && i <= format.length()) {
		if (format[i] == ' ') {
			twospace++;
			if (twospace == 2)
				break;
			temp = i;
		}
		else if(format[i] == '\n') {
			temp = offset;
			offset = i;
			return format.substr(temp, i - temp);
		}
		i++;
	}
	string ret_string = format.substr(offset, i - offset);
	offset = temp + 1;
	return ret_string;
}


int main() {
	ifstream in_file("sample.txt");
	ofstream out_file("output.txt");
	string text = "";
	string replace_word = "";
	int offset = 0;
	int end_location;
	int full_length = 0;

	while (!in_file.eof()) {
		getline(in_file, text);
		text += '\n';
		full_length = text.length();
		for (int i = 0; i < full_length - 1;) {
			replace_word = word_compare(get_two_words(text, i), end_location);
			text.replace(offset, end_location, replace_word);
			offset = i;
			full_length = text.length();
		}
		out_file << text;
	}
	in_file.close();
	out_file.close();

	return 0;
}