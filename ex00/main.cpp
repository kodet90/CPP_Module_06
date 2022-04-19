#include "main.h"

template<typename T>
void	charConvert(T const x)
{
	std::cout << "char: ";
	if (x >= std::numeric_limits<char>::min() && x <= std::numeric_limits<char>::max())
	{
		char	c = static_cast<char>(x);
		if (isprint(c))
		{
			std::cout << c;
		}
		else
		{
			std::cout << "Non displayable";
		}
	}
	else
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

template<typename T>
void	intConvert(T const x)
{
	std::cout << "int: ";
	if (x >= std::numeric_limits<int>::min() && x <= std::numeric_limits<int>::max())
	{
		int	i = static_cast<int>(x);
		std::cout << i;
	}
	else
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

template<typename T>
void	floatConvert(T const x)
{
	std::cout << "float: ";
	if (std::isnan(x) || std::isinf(x) || (x >= -std::numeric_limits<float>::max() && x <= std::numeric_limits<float>::max()))
	{
		float	f = static_cast<float>(x);
		std::cout << f << "f";
	}
	else if (x < -std::numeric_limits<float>::max())
	{
		std::cout << "-inff";
	}
	else if (x > std::numeric_limits<float>::max())
	{
		std::cout << "inff";
	}
	else
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

template<typename T>
void	doubleConvert(T const x)
{
	std::cout << "double: ";
	if (std::isnan(x) || std::isinf(x) || (x >= -std::numeric_limits<double>::max() && x <= std::numeric_limits<double>::max()))
	{
		double	d = static_cast<double>(x);
		std::cout << d;
	}
	else
	{
		std::cout << "impossible";
	}
	std::cout << std::endl;
}

template<typename T>
void	allConvert(T const x)
{
	charConvert<T>(x);
	intConvert<T>(x);
	floatConvert<T>(x);
	doubleConvert<T>(x);
}

bool	convert(char * str)
{
	char *	endptr;
	errno = 0;
	long	l = strtol(str, &endptr, 10);
	if (!*endptr)
	{
		std::cout << "Detected type: int" << std::endl;
		if (l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max() && (l != 0 || !errno))
		{
			int i = static_cast<int>(l);
			allConvert<int>(i);
			return true;
		}
		return false;
	}
	errno = 0;
	double	d = strtod(str, &endptr);
	if (!*endptr)
	{
		std::cout << "Detected type: double" << std::endl;
		if (d != 0 || !errno)
		{
			allConvert<double>(d);
			return true;
		}
		return false;
	}
	errno = 0;
	float	f = strtof(str, &endptr);
	if (!*endptr || (*endptr == 'f' && !*(endptr + 1)))
	{
		std::cout << "Detected type: float" << std::endl;
		if (d != 0 || !errno)
		{
			allConvert(f);
			return true;
		}
		return false;
	}
	char	c = *str;
	if (isprint(c) && !str[1])
	{
		std::cout << "Detected type: char" << std::endl;
		allConvert<char>(c);
		return true;
	}
	std::cout << "Detected type: other" << std::endl;
	return false;
}

int main(int ac, char *av[])
{
	if (ac != 2 || !*av[1])
	{
		std::cerr << "Argument expected:" << std::endl
		<< "char: ’a’, ’ ’, ’b’..." << std::endl
		<< "int: 0, -42, 42..." << std::endl
		<< "float: 0.0f, -4.2f, 4.2f... -inff, +inff and nanf" << std::endl
		<< "double: 0.0, -4.2, 4.2... -inf, +inf and nan" << std::endl;
		return 1;
	}
	std::cout << std::fixed;
	std::cout.precision(1);
	if (!convert(av[1]))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return 2;
	}
	return 0;
}
