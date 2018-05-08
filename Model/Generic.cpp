#ifndef Generic_cpp
#define Generic_cpp

#include <iostream>
#include <string>

using namespace std;

class Generic {
public:
  inline static void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);
  inline static int readPosInt();
};

/**
    Searches a string inside another and replaces all occurrences with a third string.

    @param string to be modified, string to be searched inside, string to be replaced with.
    @return nothing.
*/
void Generic::findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr)
{
	// Get the first occurrence
	size_t pos = data.find(toSearch);

	// Repeat till end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		data.replace(pos, toSearch.size(), replaceStr);
		// Get the next occurrence from the current position
		pos =data.find(toSearch, pos + toSearch.size());
	}
}

/**
    Reads a positive int from the terminal.

    @param nothing.
    @return the read positive int.
*/
int Generic::readPosInt(){
  int x = -1;
	while(!(cin >> x) || x < 0){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Número inválido. Tente novamente: ";
	}

	return x;
}

#endif
