#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Celsius to Fahrenheit Conversion
double celsiusToFahrenheit(double degrees);

// Fahrenheit to Celsius Conversion
double fahrenheitToCelsius(double degrees);

// Input and verify temperature
double inputDegrees(string prompt);

// Input and verify character from list of characers
char inputOption(string prompt, string options, bool lower=true);

// Main
int main(int argc, char** argv) {
	char repeat = 'y';
	while (repeat == 'y') {
		cout << "Temperature Conversion" << endl;
		cout << "----------------------" << endl;
		double degrees = inputDegrees("Temperature? ");
		char scale = inputOption("Scale? (c/f) ","cCfF");
		cout << fixed << setprecision(2) << showpoint;
		if (scale == 'f') {
			double celsius = fahrenheitToCelsius(degrees);
			cout << degrees << " degrees Fahrenheit is " << celsius << " degrees Celsius." << endl;
		}
		else {
			double fahrenheit = celsiusToFahrenheit(degrees);
			cout << degrees << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;
		}
		repeat = inputOption("Repeat? (y/n) ","yYnN");
		cout << endl;
	}
	return 0;
}

// Celsius to Fahrenheit Conversion
double celsiusToFahrenheit(double degrees) {
	return degrees * (9.0 / 5.0) + 32.0;
}

// Fahrenheit to Celsius Conversion
double fahrenheitToCelsius(double degrees) {
	return (degrees - 32.0) * 5.0 / 9.0;
}

// Output prompt and clear buffer
void outputPrompt(string prompt) {
	cout << prompt;
	cin.clear();
	cin.sync();
}

// Input and verify temperature
double inputDegrees(string prompt) {
	string buf;
	while(true) {
		outputPrompt(prompt);
		getline(cin, buf);
		try {
			string::size_type siz;
			double num = stod(buf, &siz);
			if(siz == buf.length())
				return num;
		}
		catch(...) {
		}
		cout << "Please re-enter. ";
	}
}

// Input and verify character option
char inputOption(string prompt, string options, bool lower) {
	outputPrompt(prompt);
	char result = cin.get();
	while(options.find_first_of(result) == string::npos) {
		cout << "Please re-enter. ";
		cout << prompt;
		cin.clear(); cin.sync();
		result = cin.get();
	}
	return lower == true ? tolower(result) : result;
}
