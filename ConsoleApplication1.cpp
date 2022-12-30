#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;

bool is_digit(char symbol) {                       //является ли цифрой
	return (symbol >= '0' && symbol <= '9');
}
bool is_minus(char symbol) {
	return(symbol == '-');
}
bool x_znakov(string s, char znak) {                           //есть ли повторяющие знаки (++)
	size_t first_znak = s.find(znak);
	size_t last_znak = s.find_last_of(znak);
	if (last_znak != first_znak) {
		return false;
	}
	else {
		return true;
	}
}

bool razn_znaki(string s, char znak1, char znak2) {               //есть ли еще др знаки (+*)
	size_t index_znak1 = s.find(znak1);
	size_t index_znak2 = s.find(znak2);
	if (index_znak1 < s.size() && index_znak2 < s.size()) {
		return false;
	}
	else {
		return true;
	}
}

bool valid(string s) {                                                                         //валидность
	if (x_znakov(s, '+') && x_znakov(s, '*') && x_znakov(s, '^') && x_znakov(s, '/') && x_znakov(s, '%') &&
		razn_znaki(s, '+', '*') && razn_znaki(s, '+', '/') && razn_znaki(s, '+', '^') &&razn_znaki(s, '+', '%') &&
		 razn_znaki(s, '%', '*') && razn_znaki(s, '%', '/') && razn_znaki(s, '%', '^') &&
		razn_znaki(s, '*', '/') && razn_znaki(s, '*', ' ^ ') && razn_znaki(s, '/', ' ^ ')) {
		return true;
	}
	else {
		return false;
	}
}

string s_2number(string s) {                                                     //с 2мя числами(+ - * / ^ %)
	if (s.find('+') < s.size()) {
		size_t b = s.find('+');
		double x = atof(s.substr(0, b).c_str());
		double y = atof(s.substr(b + 1).c_str());
		return to_string(x + y);
	}

	else if (s.find('*') < s.size()) {
		size_t b = s.find('*');
		double x = atof(s.substr(0, b).c_str());
		double y = atof(s.substr(b + 1).c_str());
		return to_string(x * y);
	}
	else if (s.find('/') < s.size()) {
		size_t b = s.find('/');
		double x = atof(s.substr(0, b).c_str());
		double y = atof(s.substr(b + 1).c_str());
		if (y != 0) {
			return to_string(x / y);
		}
		else {
			return "error";
		}
	}
	else if (s.find('^') < s.size()) {
		size_t b = s.find('^');
		double x = atof(s.substr(0, b).c_str());
		double y = atof(s.substr(b + 1).c_str());
		return to_string(pow(x, y));
	}
	else if (s.find('%') < s.size()) {
		size_t b = s.find('%');
		int x = atof(s.substr(0, b).c_str());
		int y = atof(s.substr(b + 1).c_str());
		if (y != 0) {
			return to_string(x % y);
		}
		else {
			return "error";
		}
	}
	else if (s.find('-') < s.size()) {
		size_t b = s.find('-');
		double x = atof(s.substr(0, b).c_str());
		double y = atof(s.substr(b + 1).c_str());
		return to_string(x - y);
	}
}



string s_1number(string inputString) {                                            // c 1 числом   (exp sqrt neg log abs)  
	if (inputString.substr(0, 3) == "exp") {
		for (size_t i = 3; i < inputString.length(); i++)
		{
			if (!is_minus(inputString[i]) && inputString[i] != '.' && !is_digit(inputString[i])) {
				return "error";
			}
		}
		double x = atof(inputString.substr(3).c_str());
		return to_string(exp(x));
	}
	else if (inputString.substr(0, 4) == "sqrt") {
		for (size_t i = 4; i < inputString.length(); i++)
		{
			if (inputString[i] != '.' && !is_digit(inputString[i])) {
				return "error";
			}
		}
		double x = atof(inputString.substr(4).c_str());
		return to_string(sqrt(x));
	}
	else if (inputString.substr(0, 3) == "log") {
		for (size_t i = 3; i < inputString.length(); i++)
		{
			if (!is_minus(inputString[i]) && inputString[i] != '.' && !is_digit(inputString[i])) {
				return "error";
			}
		}
		double x = atof(inputString.substr(3).c_str());
		if (x > 0) {
			return to_string(log10(x));
		}
		else {
			return "error";
		}
	}
	else if (inputString.substr(0, 2) == "ln") {
		for (size_t i = 2; i < inputString.length(); i++)
		{
			if (!is_minus(inputString[i]) && inputString[i] != '.' && !is_digit(inputString[i])) {
				return "error";
			}
		}
		double x = atof(inputString.substr(2).c_str());
		if (x > 0) {
			return to_string(log(x));
		}
		else {
			return "error";
		}
	}
	else if (inputString.substr(0, 3) == "abs") {
		for (size_t i = 3; i < inputString.length(); i++)
		{
			if (inputString[i] != '-' && inputString[i] != '.' && !is_digit(inputString[i])) {
				return "error";
			}
		}
		double x = atof(inputString.substr(3).c_str());
		return to_string(abs(x));
	}
	else if (inputString.substr(0, 3) == "neg") {
		for (size_t i = 3; i < inputString.length(); i++)
		{
			if (inputString[i] != '-' && inputString[i] != '.' && !is_digit(inputString[i])) {
				return "error";
			}
		}
		double x = atof(inputString.substr(3).c_str());
		return to_string(-x);
	}
}

int main()
{
	/*setlocale(LC_ALL, "Russian");*/
	cout << "Happy New Year!" << endl;
	cout << "operations: +(plus); -(minus); *(umnozheniye); /(deleniye); ^(v stepeni); %(deleniye s ostatkom);"<<endl;
	cout << "exp(e v ctepeni); sqrt(kvadratnyy koren); neg(opposite); log(logarifm po osnovaniyu 10); ln(logarifm po osnovaniyu е) abs(module); cos(cosinus); sin(sinus)" << endl;
	cout << "drobnyye chisla vvodite cherez '.' "<<endl;
	cout << "dlya vykhoda iz programmy vvedite slovo 'exit'" << endl;

	for (size_t i = 0; ; i++)
	{
		string inputString;
		cin >> inputString;
		if (inputString == "exit") {
			return 0;
		}
		if (!valid(inputString)) {
			cout << "error";
			return 1;
		}
		bool b1s = false, b1e = false, b2s = false, b2e = false;
		bool tochka1 = false, tochka2 = false;
		for (size_t i = 0; i < inputString.length(); i++)
		{
			char currentSymbol = inputString.at(i);
			if (is_digit(currentSymbol)) {
				b1s = true;
				if (b1e) {
					b2s = true;
				}
			}
			else if (currentSymbol == '.') {
				if (b1s && !b1e && tochka1) {
					cout << "error";
					return 1;
				}
				else if (b1s && !b1e && !tochka1) {
					tochka1 = true;
					continue;
				}

				if (b2s && !b2e && tochka2) {
					cout << "error";
					return 1;
				}
				else if (b2s && !b2e && !tochka2) {
					tochka2 = true;
					continue;
				}
			}
			else if (b1s) {
				b1e = true;
				if (b2s) {
					b2e = true;
				}
			}
		}

		if (b1s) {
			b1e = true;
		}
		if (b2s) {
			b2e = true;
		}
		if (b1s && b1e && !b2s && !b2e) {
			cout << s_1number(inputString) << endl;
		}
		else if (b1s && b1e && b2s && b2e) {
			cout << s_2number(inputString) << endl;
		}
		else if (!b1s && !b1e && !b2s && !b2e) {
			cout << "error";
		}
		
	}
	
}