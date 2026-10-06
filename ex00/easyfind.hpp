#pragma once

#include <algorithm>
#include <stdexcept>


/* // template <typename T>int easyfind(const T& container, int toFind);
template <typename T> int easyfind(const T &container, int toFind) {
  auto cursor = std::find(container.begin(), container.end(), toFind);
  if (cursor == container.end()) {
    throw std::runtime_error("Value not found in container");
  }
  return static_cast<int>(std::distance(container.begin(), cursor));
} */

// iterators let algorithms like find() access that data without knowing the container type

// returns a generic iterator to the element, not “the value’s index”
template<typename T> typename T::const_iterator easyfind(const T& container, int toFind) {
    auto it = std::find(container.begin(), container.end(), toFind);

    if (it == container.end())
        throw std::runtime_error("Not found");

    return it;
}

// std::vector<int>::iterator it = v.begin();


/*
Write a function template easyfind that accepts a type T. It takes two parameters:
the first one is of type T, and the second one is an integer.

Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.

If no occurrence is found, you can either throw an exception or return an error value
of your choice. 

If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as ex-
pected. */