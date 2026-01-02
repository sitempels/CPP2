
#include	"MutantStack.hpp"
#include	<list>

int	main(void) {
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << " ";
		std::cout << mstack.size() << std::endl;

		mstack.pop();

		std::cout << mstack.top() << " ";
		std::cout << mstack.size() << std::endl;
	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(78);
		mstack.push(98);
		mstack.push(35);
		mstack.push(987);
		mstack.push(34);
		mstack.push(0);

		MutantStack<int>::iterator	it = mstack.begin();
		MutantStack<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int>	s(mstack);

		MutantStack<int>::reverse_iterator	rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator	rite = mstack.rend();

		while (rit != rite) {
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
	}
	{
		std::list<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << " ";
		std::cout << mstack.size() << std::endl;

		mstack.pop_back();

		std::cout << mstack.back() << " ";
		std::cout << mstack.size() << std::endl;
	
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(78);
		mstack.push_back(98);
		mstack.push_back(35);
		mstack.push_back(987);
		mstack.push_back(34);
		mstack.push_back(0);

		std::list<int>::iterator	it = mstack.begin();
		std::list<int>::iterator	ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::list<int>::reverse_iterator	rit = mstack.rbegin();
		std::list<int>::reverse_iterator	rite = mstack.rend();

		while (rit != rite) {
			std::cout << *rit << " ";
			++rit;
		}
		std::cout << std::endl;
	}

	return (0);
}
