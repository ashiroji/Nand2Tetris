#ifndef CODE
#define CODE 

#include <map>
#include <string>
class code
{
public:
	code();
	std::string dest(const std::string& d);
	std::string comp(const std::string& c);
	std::string jump(const std::string& j);
	~code();

private:
	std::map<std::string, std::string> destMap;

	std::map<std::string, std::string> compMap;

	std::map<std::string, std::string> jumpMap;	
};


#endif	