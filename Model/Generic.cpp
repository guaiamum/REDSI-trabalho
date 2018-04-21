#ifndef Generic_cpp
#define Generic_cpp

#include <string>

class Generic {
public:
  inline static void findAndReplaceAll(std::string & data, std::string toSearch, std::string replaceStr);
};

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

#endif
