#include "symTable.h"

symTable::symTable()
{
	this->table["SP"] = 0;
	this->table["LCL"] = 1;
	this->table["ARG"] = 2;
	this->table["THIS"] = 3;
	this->table["THAT"] = 4;
	this->table["R0"] = 0;
	this->table["R1"] = 1;
	this->table["R2"] = 2;
	this->table["R3"] = 3;
	this->table["R4"] = 4;
	this->table["R5"] = 5;
	this->table["R6"] = 6;
	this->table["R7"] = 7;
	this->table["R8"] = 8;
	this->table["R9"] = 9;
	this->table["R10"] = 10;
	this->table["R11"] = 11;
	this->table["R12"] = 12;
	this->table["R13"] = 13;
	this->table["R14"] = 14;
	this->table["R15"] = 15;
	this->table["SCREEN"] = 16384;
	this->table["KBD"] = 24576;

	this->ramAddress=16;
	this->romAddress=0;
}
void symTable::addEntry(std::string symbol, int address)
{
	this->table[symbol] = address;
}

int symTable::getRamAddress()
{
	return(this->ramAddress);
}

int symTable::getRomAddress()
{
	return(this->romAddress);
}

bool symTable::contains(std::string symbol)
{
	return(this->table.find(symbol) != this->table.end());
}

int symTable::getAddress(std::string symbol)
{
	return(this->table[symbol]);
}

void symTable::incRom()
{
	this->romAddress++;
}

void symTable::incRam()
{
	this->ramAddress++;
}

symTable::~symTable()
{
	
}