#pragma once

#include <deque>
#include <stack>

// normally std::stack only has push(), pop(), top(), size() & empty()
// MutantStack is supposed to be also iterable
// so MutantStack inherits from std::stack and adds begin() & end()

template <typename T>
class MutantStack : public std::stack<T>
{
public:

    // Iterator type of the container used internally by std::stack
    using stack_iterator =
        typename std::stack<T>::container_type::iterator;

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other){
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    // Return an iterator to the first element of the underlying container
    stack_iterator begin() { return this->c.begin(); }
    // Return an iterator one position past the last element
    stack_iterator end() { return this->c.end(); }

    const stack_iterator begin() const { return this->c.begin(); }
    const stack_iterator end() const { return this->c.end(); }

};

/* Now, it’s time to move on to more serious things. Let’s develop something weird.
The std::stack container is very nice. Unfortunately, it is one of the only STL Con-
tainers that is NOT iterable. That’s too bad.

But why would we accept this? Especially if we can take the liberty of butchering the
original stack to create missing features.

To repair this injustice, you have to make the std::stack container iterable.
Write a MutantStack class. It will be implemented in terms of a std::stack.

It will offer all its member functions, plus an additional feature: iterators.
Of course, you will write and turn in your own tests to ensure everything works as
expected. */