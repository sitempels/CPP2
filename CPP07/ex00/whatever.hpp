
#ifndef		WHATEVER_HPP
# define	WHATEVER_HPP

template <typename T>
void	swap(T& param_1, T& param_2) {
	T tmp = param_1;
	param_1 = param_2;
	param_2 = tmp;
}

template <typename T>
const T&	min(const T& value_1, const T& value_2) {
	return (value_1 < value_2 ? value_1 : value_2);
}

template <typename T>
const T&	max(const T& value_1, const T& value_2) {
	return (value_1 > value_2 ? value_1 : value_2);
}

#endif
