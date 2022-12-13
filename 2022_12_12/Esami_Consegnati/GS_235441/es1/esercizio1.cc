// argv: input e output
// no duplicati
// stampare stringe con numero di occorrenze

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct String {
	char string[100];
	int repetitions;
};

bool Check(char s[]) {
	bool ok = true;
	for (int i = 0; i < (int)strlen(s); i++) {
		if (s[i] < 'a' || s[i] > 'z') {
			ok = false;
			break;
		}
	}
	return ok;
}

int main(int argc, char **argv)  {
	
	if (argc != 3) {
		cout << "usage: ./a.out <input.txt> <output.txt>"; // usare cerr
		return -1; // usare exit()
	}
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	// Non apri gli stream !
	if (input.fail() || output.fail()) {
		cout << "Error opening files";
		return -1;
	}

	char s[100] = {};
	String unique[100];
	int n_unique = 0;
	while (input >> s) {
		
		// Checks if all characters are lowercase	
		if(Check(s)) {

			bool is_unique = true;
			for (int i = 0; i < n_unique; i++) {
				if (strcmp(s, unique[i].string) == 0) {
					
					// The string is not unique so
					// It's repetition is increased
					is_unique = false;
					unique[i].repetitions++;
					break;
				}
			}

			if (is_unique) {

				// Add to the array of unique strings
				strcpy(unique[n_unique].string, s);
				unique[n_unique].repetitions = 1;
				n_unique++;
			}
		}
	}

	// Printing
	for (int i = 0; i < n_unique; i++) {
		output << unique[i].string << ": " << unique[i].repetitions << endl;
	}

	input.close();
	output.close();
	return 0;
}
