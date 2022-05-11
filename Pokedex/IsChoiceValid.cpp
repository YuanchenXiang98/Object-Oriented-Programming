#include <iostream>
#include <limits>
using namespace std;

int IsChoiceValid(int num) {
	// same with while(true)
	for (;;) {
		// ask user to enter
		if (cin >> num) {
			// this is what we want
			if (num <= 2 && num >= 1) {
				break;
			}
			// if they type what we do not want, then clear the input and ask them to re-enter
			else {
				cout << "Please Enter a valid integer number (in this case 1 or 2): ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		// if they type what we do not want, then clear the input and ask them to re-enter
		else {
			cout << "Please Enter a valid integer number (in this case 1 or 2): ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	// return the valid input
	return num;
}
