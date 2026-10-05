#pragma once

#include <deque>
#include <stack>

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