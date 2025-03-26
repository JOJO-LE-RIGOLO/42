/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:11:56 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/26 14:01:16 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

ClapTrap::ClapTrap( string n ): name(n), health(100), energy(50), damage(20)
{
    cout << "ClapTrap " << name << " has created !" << endl;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap " << name << " has destroyed !" << endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
    if (this != &other){
        cout << "ClapTrap " << this->name << " is now " << other.name << " !" << endl;
        this->name = other.name;
        this->health = other.health;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    return *this;
}

ClapTrap::ClapTrap( ClapTrap const& copy )
{
    cout << "Copy constructor called" << endl;
    *this = copy;
}

void ClapTrap::attack( const string& target )
{
    if (this->damage == 0){
        cout << "ClapTrap " << this->name << " can't do damage !" << endl;
        return ;
    }
    if (this->energy <= 0){
        cout << "ClapTrap " << this->name << " has no energy to do anythings !" << endl;
        return ;
    }
    if (this->health <= 0){
        cout << "ClapTrap " << this->name << " has no health !" << endl;
        return ;
    }
    this->energy -= 1;
    cout << "ClapTrap "
        << this->name
        << " attacks "
        << target
        << ", causing "
        << this->damage
        << " points of damage !" << endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (this->health <= 0){
        cout << "ClapTrap " << this->name << " has no Health !" << endl;
        return ;
    }
    this->health -= amount;
    if (this->health < 0)
        this->health = 0;
    cout << "ClapTrap "
        << this->name
        << " take "
        << amount
        << " damage, now he have "
        << this->health
        << " Health !" <<endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->energy <= 0){
        cout << "ClapTrap " << this->name << " has no energy to do anythings !" << endl;
        return ;
    }
    if (this->health <= 0){
        cout << "ClapTrap " << this->name << " has no health !" << endl;
        return ;
    }
    if (this->health == 10){
        cout << "ClapTrap " << this->name << " has max Health !" << endl;
        return ;
    }
    this->health += amount;
    if (this->health > 100)
        this->health = 100;
    this->energy -= 1;
    cout << "ClapTrap "
        << this->name
        << " repaire him "
        << amount
        << " health, now he have "
        << this->health
        << " Health !" << endl;
}