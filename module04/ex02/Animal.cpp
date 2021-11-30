#include "Animal.hpp"

/*
**	ANIMAL
*/

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	std::cout << "Default Animal constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Parameter Animal constructor called." << std::endl;
}

Animal::Animal( const Animal & src )
{
	this->_type = src._type;
	std::cout << "Copy Animal constructor called." << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Animal const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Animal::makeSound(void) const {
	std::cout << "E... Ed.... Edward....." << std::endl;
}

std::string		Animal::getType(void) const {
	return this->_type;
}

void			Animal::printIdeas(void) const {
	std::cout << "I have no Idea." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/*
**	DOG
*/

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : _brain(new Brain)
{
	std::cout << "Default Dog constructor called." << std::endl;
	this->_type = "Dog";
}

Dog::Dog( const Dog & src ) : _brain(new Brain(*src._brain))
{
	std::cout << "Copy Dog constructor called." << std::endl;
	this->_type = src._type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_brain = rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Dog::makeSound(void) const {
	std::cout << "Woof. I have a knife." << std::endl;
}

void			Dog::printIdeas(void) const {
	std::cout << *this->_brain << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/*
**	CAT
*/

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : _brain(new Brain)
{
	std::cout << "Default Cat constructor called." << std::endl;
	this->_type = "Cat";
}

Cat::Cat( const Cat & src ) : _brain(new Brain(*src._brain))
{
	std::cout << "Copy Cat constructor called." << std::endl;
	this->_type = src._type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
		this->_brain = rhs._brain;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Cat::makeSound(void) const {
	std::cout << "Meow. Feed me human." << std::endl;
}

void			Cat::printIdeas(void) const {
	std::cout << *this->_brain << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */