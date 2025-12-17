
#ifndef		ITER_HPP
# define	ITER_HPP

template <typename T_array, typename T_function>
void	iter(T_array* array, const size_t len, T_function function) {
	if (!function)
		return ;
	for (size_t i = 0; i < len; i++) {
		function(array[i]);
	}
	return ;
}

#endif
