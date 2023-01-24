#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

struct Car
{
	std::string car_name;
	unsigned int car_age;
	unsigned long long cost;
};

int get_int(void);
void get_info(void);
void save_data(std::string filename, Car* catalog, int size);
void display(Car*, int size);


int main(void) {
	int n = 0;
	std::cout << "How many cars you want input\n"; n = get_int();
	abs(n);
	Car* catalog = new Car[n];
	std::cout << "Enter the parameters of car\n";
	for (int i = 0; i < n; i++) {
		std::cout << "Car#" << i + 1 << '\n';
		std::cout << "Enter the car name: ";
		std::getline(std::cin, catalog[i].car_name);
		std::cout << "Enter the car age: ";
		catalog[i].car_age = get_int();
		std::cout << "Enter the car cost: ";
		catalog[i].cost = get_int();
	}

	short choice = 0;
	get_info();
	choice = get_int();
	std::ofstream File;
	while (choice) {
		switch (choice) {
		case 0: std::cout << "Program is stoped\n"; break;
		case 1:
			File.open("DATA.txt");
			save_data("DATA.txt", catalog, n);
			std::cout << "DATA SAVED\n";
			break;
		case 2:
			display(catalog, n);
			break;
		default:
			std::cout << "Invalid input\n";
			break;
		}
		choice = get_int();
	}
	if (File.is_open()) {
		File.close();
	}
	return 0;
}

int get_int(void) {
	int n;
	while (!(std::cin >> n)) {
		std::cin.clear();
		while (std::cin.get() != '\n') {
			continue;
		}
		std::cout << "Warning, not correct input\n";
	}
	std::cin.get();
	return n;
}

void get_info(void) {
	std::cout << "WRITE 1 TO SAVE THE DATA\n"
		<< "WRITE 2 TO SHOW THE DATA\n"
		<< "WRITE 0 TO EXIT THE PROGRAM\n";
}

void save_data(std::string filename, Car* catalog, int size) {
	std::ofstream File;
	File.open(filename);
	File << "CATALOG CARS: " << size << '\n';
	for (int i = 0; i < size; i++) {
		File << "CAR#" << i + 1 << "\n\n";
		File << "CAR_NAME: " << catalog[i].car_name << '\n';
		File << "CAR_AGE: " << catalog[i].car_age << '\n';
		File << "CAR_COST: " << catalog[i].cost << '\n';
	}
	File.close();
}

void display(Car* catalog, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "Car name: " << catalog[i].car_name << '\n';
		std::cout << "Car value: " << catalog[i].cost << '\n';
		std::cout << "Car age: " << catalog[i].car_age << '\n';
	}
}