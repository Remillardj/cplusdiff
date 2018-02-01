//Very very very inefficient program to remove multi word instances
//Could have been a lot easier with regular expressions, or another programming lang, but I digress

using namespace std;
#include<string>
#include<iostream>
#include<fstream>

//compares two words to see if they are the same
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

//returns a string with two words in it
//offset used for a start position to look for the next two words
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

//main script execution 
int main() {
	//input and output files
	ifstream in_file("sample.txt");
	ofstream out_file("output.txt");
	
	//used for multi-line text files
	string text = "";
	
	//string to hold the word(s) to replace
	string replace_word = "";
	
	//used for the split in to two words function
	int offset = 0;
	
	//used to tell the program where to put the end of the replacement
	int end_location;
	
	//used to redefine the max length of the line
	int full_length = 0;

	while (!in_file.eof()) {
		getline(in_file, text);
		text += '\n';
		full_length = text.length();
		//loop for splitting and analyzing two words, removing one if duplicate is found
		for (int i = 0; i < full_length - 1;) {
			//get the words to replace
			replace_word = word_compare(get_two_words(text, i), end_location);
			//replace them with the ones in the main string
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