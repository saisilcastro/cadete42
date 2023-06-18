/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:19:16 by elraira-          #+#    #+#             */
/*   Updated: 2023/06/17 21:02:05 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    {
        std::cout << RED << "-----------------------------------------"
            << "Testing Generic Animals" << RESET << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating Animal, Dog and Cat"
            << RESET << std::endl;
        const Animal* animal = new Animal();
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();

        std::cout << std::endl;
        std::cout << BLUE << "getType()" << RESET << std::endl;
        std::cout << dog->getType() << std::endl;
        std::cout << cat->getType() << std::endl;

        std::cout << std::endl;
        std::cout << BLUE << "makeSound()" << RESET << std::endl;
        cat->makeSound(); // will output the cat sound!
        dog->makeSound();
        animal->makeSound();

        std::cout << std::endl;
        std::cout << BLUE << "Delete Animal, Dog and Cat" << RESET << std::endl;
        delete animal;
        delete dog;
        delete cat;
    }
    {
        std::cout << std::endl;
        std::cout << RED << "-----------------------------------------"
            << "Testing Wrong Animals" << RESET << std::endl;
        std::cout << BLUE_BACKGROUND << "Creating WrongAnimal and WrongCat"
            << RESET << std::endl;
        const WrongAnimal* animal = new WrongAnimal();
        const WrongAnimal* cat = new WrongCat();
        const WrongCat* cat2 = new WrongCat();

        std::cout << std::endl;
        std::cout << BLUE << "getType()" << RESET << std::endl;
        std::cout << cat->getType() << std::endl;
        std::cout << cat2->getType() << std::endl;

        std::cout << std::endl;
        std::cout << BLUE << "makeSound()" << RESET << std::endl;
        cat->makeSound();
        animal->makeSound();
        cat2->makeSound();

        std::cout << std::endl;
        std::cout << BLUE << "Delete WrongAnimal and WrongCat" << RESET
            << std::endl;
        delete animal;
        delete cat;
		delete cat2;
    }
    return 0;
}
