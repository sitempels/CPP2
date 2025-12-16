
#ifndef		ITER_HPP
# define	ITER_HPP

template <typename T>
void	iter(T* adress, const size_t len, void (*f)(T& param)) {
