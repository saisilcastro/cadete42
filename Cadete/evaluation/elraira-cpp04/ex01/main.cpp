/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:20:59 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 21:21:39 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main(void)
{
    {
        std::cout << BLUE << "Creating a Dog and a Cat on the heap:"
            << RESET << std::endl;
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << std::endl;
        std::cout << BLUE << "Creating a Dog and a Cat on the stack:"
            << RESET << std::endl;
        Dog dog2;
        Cat cat2;

        std::cout << std::endl;
        std::cout << BLUE << "Deleting the animals:" << RESET << std::endl;
        delete dog;
        delete cat;

        std::cout << std::endl;
        std::cout << BLUE << "Exiting the scope:" << RESET << std::endl;
    }
    {
        std::cout << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating an array of 30 animals:"
            << RESET << std::endl;
        const int size = 30;
        const Animal* animals[size];

        std::cout << std::endl;
        std::cout << BLUE << "Filling the array with 15 Dogs and 15 Cats:"
            << RESET << std::endl;
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                std::cout << YELLOW << i << ": " << RESET;
                animals[i] = new Dog();
            } else {
                std::cout << YELLOW << i << ": " << RESET;
                animals[i] = new Cat();
            }
        }

        std::cout << std::endl;
        std::cout << BLUE << "Making all the animals speak:" << RESET
            << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << YELLOW << i << ": " << RESET;
            animals[i]->makeSound();
        }

        std::cout << std::endl;
        std::cout << BLUE << "Deleting the animals:" << RESET << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << YELLOW << i << ": " << RESET;
            delete animals[i];
        }
    }
    {
        std::cout << std::endl;
        std::cout << BLUE << "Creating a Cat using the cat constructor:"
            << RESET << std::endl;
        Cat* cat = new Cat();

        std::cout << std::endl;
        std::cout << BLUE << "Cat's type: " << RESET << std::endl;
        std::cout << cat->getType() << std::endl;
        std::cout << BLUE << "Cat's sound: " << RESET << std::endl;
        cat->makeSound();

        std::cout << std::endl;
        std::cout << BLUE << "Cat's brain ideas: " << RESET << std::endl;
        for (int i = 0; i < 101; i++) {
            std::cout << YELLOW << i << ": " << RESET;
            cat->getBrain()->getIdeas(i);
        }

        std::cout << std::endl;
        std::cout << BLUE << "Deleting the cat:" << RESET << std::endl;
        delete cat;
    }
    {
        std::cout << std::endl;
        std::cout << RED << "-----------------------------------------"
            << "Testing deep copy vs shallow copy" << RESET << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating a Dog and a Cat"
            << RESET << std::endl;
        Dog dog;
		Cat cat;

        std::cout << std::endl;
        std::cout << BLUE << "Creating a copy of the Dog and the Cat"
            << RESET << std::endl;
        Cat catCopy(cat);
		Dog dogCopy(dog);

        std::cout << std::endl;
        std::cout << BLUE << "Checking if the copy and the original have the "
            << "same Brain" << RESET << std::endl;
        std::cout << "Dog: " << dog.getBrain() << std::endl;
        std::cout << "Dog2: " << dogCopy.getBrain() << std::endl;
        std::cout << "Cat: " << cat.getBrain() << std::endl;
        std::cout << "Cat2: " << catCopy.getBrain() << std::endl;

		std::cout << std::endl;
        std::cout << BLUE << "Exiting the scope:" << RESET << std::endl;
    }
    return 0;
}
