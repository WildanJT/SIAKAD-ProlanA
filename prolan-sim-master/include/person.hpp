#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <iostream>

class person {
private:
	std::string id;
	std::string nama;
	int dd, mm, yy;

public:
	person(std::string id, std::string nama, int dd, int mm, int yy);

	void setId(std::string id);
	std::string getId();

	void setNama(std::string nama);
	std::string getNama();

	void setTglLahir(int dd, int mm, int yy);
	int getTglLahir();
	int getBulanLahir();
	int getTahunLahir();	
};


#endif
