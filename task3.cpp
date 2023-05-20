#include <iostream>
#include <fstream>

void checking_if_a_file_is_open_for_writing(std::ofstream& out_fish_in_basket) {	

	if (out_fish_in_basket.is_open()) {

		std::cout << "File \"basket.txt\" is open\n";

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}
}

void checking_if_a_file_is_open_for_reading(std::ifstream& in_fish_list) {

	if (in_fish_list.is_open()) {

		std::cout << "File \"river.txt\" is open\n";

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}
}

int main() {

	std::string type_of_fish_caught;
	std::string type_of_fish_caught_in_list;
	std::string completing_an_input_operation;

	std::ifstream in_fish_list;
	std::ofstream out_fish_in_basket;	

	out_fish_in_basket.open("D:\\Skillbox\\C++\\working\\Practice 20 (Writing to files)\\task3\\basket.txt", std::ios::app);
	checking_if_a_file_is_open_for_writing(out_fish_in_basket);
	
	do {			

		std::cout << "Enter the type of fish you will be catching: ";
		std::cin >> type_of_fish_caught;

		in_fish_list.open("D:\\Skillbox\\C++\\working\\Practice 20 (Writing to files)\\task3\\river.txt");
		checking_if_a_file_is_open_for_reading(in_fish_list);

		while (!in_fish_list.eof()) {				

			in_fish_list >> type_of_fish_caught_in_list;

			if (type_of_fish_caught == type_of_fish_caught_in_list) {			
								
				out_fish_in_basket << type_of_fish_caught;				
				break;

			}			
		}

		in_fish_list.close();
		type_of_fish_caught_in_list = "";

		std::cout << "Enter \"yes\" to continue fishing, enter any character if you want to end fishing: ";
		std::cin >> completing_an_input_operation;

		if (completing_an_input_operation == "yes" || completing_an_input_operation == "Yes") {

			out_fish_in_basket << std::endl;
			out_fish_in_basket.close();
		}

	} while (completing_an_input_operation == "yes" || completing_an_input_operation == "Yes");
	
}