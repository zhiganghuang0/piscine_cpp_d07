#ifndef _WOODY_H_
#define _WOODY_H_

#include <string>
#include <cctype>
#include "Toy.h"

class Woody : public Toy
{
	public:
		Woody(std::string const &name);
		Woody(std::string const &name, std::string const &filename);
		~Woody();
		void speak(std::string);
};

#endif
