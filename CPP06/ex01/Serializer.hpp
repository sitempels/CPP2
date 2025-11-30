
#ifndef		SERIALIZE_HPP
# define	SERIALIZE_HPP

/*Includes*/
# include <iostream>
# include <string>

typedef unsigned long uintptr_t;

/*Structures*/
typedef struct	Data {
	char	char_data;
	int		int_data;
	float	float_data;
}				Data;

/*Class*/
class	Serializer {
	private:
	/*Constructor - Copy Constructor - Destructor*/
		Serializer();
		Serializer(const Serializer& copy_from);
		~Serializer();
	
	/*Overloaded Operator*/
		Serializer&	operator=(const Serializer& other);

	public:
	/*Public Method*/
		static uintptr_t	serialize(Data* ptr) ;
		static Data*		deserialize(uintptr_t raw) ;
};

#endif
