/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:25:43 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 19:05:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        std::cout << BLUE << "Creating a Dog and a Cat on the heap:"
            << RESET << std::endl;
        const Dog* dog = new Dog();
        const Cat* cat= new Cat();
        /* will generate an error because AAnimal is an abstract class
        and abstract classes cannot be instantiated. */
        //const AAnimal* aanimal = new AAnimal();

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
        const AAnimal* animals[size];

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
            animals[i]->getBrain()->getIdeas(i);
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
        std::cout << BLUE << "Creating a Car using the cat constructor:"
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
    return 0;
}
