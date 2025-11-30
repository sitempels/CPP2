
#include "Serializer.hpp"

int	main(void) {
	Data	data;
	data.char_data = 'a';
	data.int_data = 19;
	data.float_data = 25.2f;

	uintptr_t	serial = Serializer::serialize(&data);
	Data*		unserial = Serializer::deserialize(serial);

	std::cout << "Serialized value:\t" << serial << std::endl;
	std::cout << "Deserialized value:\t" << reinterpret_cast<uintptr_t>(unserial) << std::endl;
	std::cout << std::endl;
	std::cout << std::hex << "Serialized value:\t0x" << serial << std::endl;
	std::cout << "Deserialized value:\t" << unserial << std::endl;
	std::cout << std::endl;
	std::cout << "Serialized value:\t" << data.char_data << ' ' << data.int_data << ' ' << data.float_data << std::endl;
	std::cout << "Deserialized value:\t" << unserial->char_data << ' ' << unserial->int_data << ' ' << unserial->float_data << std::endl;
}
