#include "Util.h"

#include <fstream>

OptString ReadFile(std::string_view& path)
{	
	if (std::ifstream is{path, std::ios::binary | std::ios::ate}) {
		auto pos = is.tellg();
		std::string str(std::streamoff(pos), 0);
		// Position type is opaque. It can be converted to a useable offset with
    // std::streamoff(). This happens implicitly in is.read() below.
    // Likewise, it could also be omitted above.
		is.seekg(0);
		if (is.read(&str[0], pos)) {
			return str;
		}
	}
	return {};
}

int TrimTrailing(std::string& s)
{
	int res = s.length();
	for (auto it = s.crbegin(); it != s.crend(); it++)
	{
		if (!std::isspace(*it)) 
		{
			break;
		}
		res--;
	}
	return res;
}
