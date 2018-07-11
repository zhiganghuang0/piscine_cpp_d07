#ifndef _TOY_H_
#define _TOY_H_

#include <iostream>
#include <string>
#include "Picture.h"

class Toy
{
public:
		enum ToyType
		{
			BASIC_TOY = 0,
			ALIEN = 1,
			BUZZ = 2,
			WOODY = 3
		};

		class Error
		{
			public:
				Error();
				enum ErrorType
				{
					UNKNOWN = 0,
					PICTURE = 1,
					SPEAK = 2
				};

				std::string const& what() const;
				std::string const& where() const;
				ErrorType type;
				void clear();
				void record(ErrorType ty, std::string const& what, std::string const& where);
				
			private:
				std::string _what;
				std::string _where;
		};

		Toy();
		Toy(Toy const& other);
		Toy(ToyType type, std::string const& name, std::string const& filename);
		virtual ~Toy() {}
		Toy& operator=(Toy const& other);

		ToyType getType() const;
		std::string const& getName() const;
		void setName(std::string const& name);
		bool setAscii(std::string const& filename);
		std::string const& getAscii() const;

		virtual bool speak(std::string const& speech);
		virtual bool speak_es(std::string const& speech);

		Toy& operator<<(std::string const& file);
		Error& getLastError();
		
	protected:
		ToyType _type;
		std::string _name;
		Picture _picture;
		Error _error;
};

std::ostream& operator<<(std::ostream& stream, Toy const& toy);

#endif
