template <typename Iterator, typename T>
Iterator fordJohnson::lowerBound(Iterator first, Iterator last, const T& value) {
		typedef typename std::iterator_traits<Iterator>::difference_type	diff;
		
		diff		count = std::distance(first, last);
		diff		step;
		Iterator	it;

		while (count > 0) {
			it = first;
			step = count / 2;
			std::advance(it, step);
			if (**it < value) {
				first = ++it;
				count -= step + 1;
				g_comp++;
			}
			else
				count = step;
		}
		return (first);
}
