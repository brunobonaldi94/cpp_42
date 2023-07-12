#ifndef CHAR_DATA_HPP
# define CHAR_DATA_HPP

#include "AData.hpp"

class CharData: public AData<char>
{
	public:
		CharData();
		CharData(std::string param);
		~CharData();
		CharData(CharData const &src);
		CharData & operator=(CharData const &rhs);

		char tryToConvert();
		void printConverted();
};

#endif
