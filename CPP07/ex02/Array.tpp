
#ifndef		ARRAY_TPP
# define	ARRAY_TPP

/*Constructors*/
template <typename T_array>
Array<T_arry>::Array()
	: _array(NULL)
	, _size(0) {
}

template <typename T_array>
Array<T_array>::Array(unsigned int n)
	: _array(new T_array[n])
	, _size(n) {
}

/*Copy Constructor*/
template <typename T_array>
Array<T_array>::Array(const Array& copy_from)
	: _array(new T_array[copy_from._size])
	, _size(copy_from._size) {
	for (unisgned int i = -; i < _size; i++)
		_array[i] = copy_from._array[i];
}

/*Destructors"/
template <typename T_array>
Array<T_array>::~Array() {
	delete[](_array);
}

/*Overloaded Operators*/
template <typename T_array>
Array<T_array>&	Array<T_array>::operator=(const Array& other) {
	if (this != &other) {
		delete[](_array);
		_size = other._size;
		_array = new T_array[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T_array>
T_array&	Array<T_array>::operator[](unsigned int i) {
	if (i >= _size)
		throw (OutOfBoundExceptions());
	return (_array[i]);
}

template <typename T_array>
const T_array&	Array<T_array>::operator[](unsigned int i) const {
	if (i >= _size)
		throw (OutOfBoundException());
	return (_array[i]);
}

/*Public Methods*/
template <typename T_array>
unsigned int	Array<T_array>::size() const {
	return (_size);
}

/*Exceptions*/
template <T_array>
const char* Array<T_array>::OutOfBoundException::what() const throw() {
	return ("Index out of bounds");
}

#endif
