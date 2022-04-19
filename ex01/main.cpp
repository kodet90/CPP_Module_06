#include "main.h"

uintptr_t	serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *	deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main()
{
	Data	data = {'c', "Hello world!", 42, NULL, 42.42f};
	data.d4 = &data;
	std::cout << &data << std::endl;

	uintptr_t serial = serialize(&data);
	std::cout << serial << std::endl;

	Data *	deserial = deserialize(serial);
	std::cout << deserial << std::endl;

	if (&data == deserial) {
		std::cout << "&data == deserial == " << &data << std::endl;
	}
	if (data.d1 == deserial->d1) {
		std::cout << "data.d1 == deserial->d1 == " << data.d1 << std::endl;
	}
	if (data.d2 == deserial->d2) {
		std::cout << "data.d2 == deserial->d2 == " << data.d2 << std::endl;
	}
	if (data.d3 == deserial->d3) {
		std::cout << "data.d3 == deserial->d3 == " << data.d3 << std::endl;
	}
	if (data.d4 == deserial->d4) {
		std::cout << "data.d4 == deserial->d4 == " << data.d4 << std::endl;
	}
	if (data.d5 == deserial->d5) {
		std::cout << "data.d5 == deserial->d5 == " << data.d5 << std::endl;
	}
	return 0;
}
