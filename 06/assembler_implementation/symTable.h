#ifndef SYMBOL
#define SYMBOL
#include <map>
#include <string>
class symTable
{
public:
	symTable();
	void addEntry(std::string symbol, int address);
	bool contains(std::string symbol);
	int getAddress(std::string symbol);
	int getRamAddress();
	int getRomAddress();
	void incRom();
	void incRam();
	~symTable();
private:
	std::map<std::string, int> table;
	int ramAddress;	
	int romAddress;
};

#endif