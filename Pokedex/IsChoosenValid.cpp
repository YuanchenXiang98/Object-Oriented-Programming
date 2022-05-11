#include <iostream>
#include <limits>
using namespace std;

int IsChoosenValid(int num) {
	// same with while(true)
	for (;;) {
		// ask user to enter
		if (cin >> num) {
			// this is what we want
			if (num <= 5 && num >= 0) {
				break;
			}
			// if they type what we do not want, then clear the input and ask them to re-enter
			else {
				cout << "Please Enter a valid integer number (in this case 0-5): ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		// if they type what we do not want, then clear the input and ask them to re-enter
		else {
			cout << "Please Enter a valid integer number (in this case 0-5): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	// return the valid input
	return num;
}
