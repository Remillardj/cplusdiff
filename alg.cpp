#include<string>
#include<iostream>

string toParse = "";

using namespace std;



for (int i = 0; i <= toParse.length(); i++) {

}

string word_compare(string words) {

  int twospace = 0;
  string word_one = "",
         word_two = "";
  for(int i = 0; i <= words.length(); i++) {

    
  }
}





string get_two_words(string format, int offset = 0) {
  int twospace = 0;
  string two_words = "";

  int i = offset;
  while(!twospace && i <= format.length()) {
    if(format[i] == ' ') {
      twospace++;
    }
    if(twospace == 2) {
      break;
    }
  }
  string two_words = str.substr(offset, i)
}
