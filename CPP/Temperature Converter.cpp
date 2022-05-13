#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//function to convert temps
float FahrenheitToCelcius(float temperature) {
	return (5 * (temperature - 32) / 9);	//had to rearrange formula to prevent answer as 0
}

int main() {
	ifstream inFS;	//reading file
	ofstream otFS;	//writing file

	inFS.open("FahrenheitTemperature.txt");
	otFS.open("CelsiusTemperature.txt");

	string data;
	float temp;
	while (inFS >> data >> temp) {
		otFS << data << " " << setprecision(2) << FahrenheitToCelcius(temp) << endl;
	}

	inFS.close();
	otFS.close();
	
}