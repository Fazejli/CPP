/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:13 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 09:45:16 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
int	main()
{
	ClapTrap	trapA("Bob");
	ScavTrap	trapB("Tom");

	std::cout << "\n" << trapA.getName() << trapA << "			" << trapB.getName() << trapB << "\n" << std::endl;
	//std::cout << trapB.getAttackDamage() << std::endl;
	trapA.attack(trapB.getName());
	trapB.takeDamage(2);
	
	std::cout << "\n" << trapA.getName() << trapA << "			" << trapB.getName() << trapB << "\n" << std::endl;

	trapB.beRepaired(2);
	std::cout << "\n" << trapA.getName() << trapA << "			" << trapB.getName() << trapB.getHitPoints() << "\n" << std::endl;
	
	return (0);
}*/

int main()
{
    std::cout << "=== Test 1: Construction Chaining ===" << std::endl;
    ScavTrap s("Scav1");
    
    std::cout << "\n\n=== Test 2: Default Constructor ===" << std::endl;
    ScavTrap s2;
    
    std::cout << "\n\n=== Test 3: Copy Constructor ===" << std::endl;
    ScavTrap s3(s);
    
    std::cout << "\n\n=== Test 4: ScavTrap S1 info ===" << std::endl;
    std::cout << "Name: " << s.getName() << std::endl;
    std::cout << "HP: " << s.getHitPoints() << std::endl;
    std::cout << "Energy: " << s.getNrjPoints() << std::endl;
    std::cout << "Attack: " << s.getAttackDamage() << std::endl;
    
    std::cout << "\n\n=== Test 5: ScavTrap Attack ===" << std::endl;
    std::cout << s.getName() << " energy before: " << s.getNrjPoints() << std::endl;
    s.attack("Enemy");
    std::cout << s.getName() << " energy after: " << s.getNrjPoints() << std::endl;

    std::cout << "\n\n=== Test 6: guardGate ===" << std::endl;
    s.guardGate();
    
    std::cout << "\n\n=== Test 7: ClapTrap VS ScavTrap ===" << std::endl;
    ClapTrap c1("Alice");
    ScavTrap s1("Bob");

    std::cout << "\nGeneral Infos:" << std::endl;
    std::cout << "HitPoints = \tClapTrap: " << c1.getHitPoints() << " AND ScavTrap: " << s1.getHitPoints() << std::endl;
    std::cout << "EnergyPoints = \tClapTrap: " << c1.getNrjPoints() << " AND ScavTrap: " << s1.getNrjPoints() << std::endl;
    std::cout << "AttackDamage = \tClapTrap: " << c1.getAttackDamage() << " AND ScavTrap: " << s1.getAttackDamage() << std::endl;

    std::cout << "\n1. ClapTrap attack:" << std::endl;
    c1.attack(s1.getName());
    std::cout << s1.getName() << " hp before: " << s1.getHitPoints() << std::endl;
    s1.takeDamage(c1.getAttackDamage());
    std::cout << s1.getName() << " hp after: " << s1.getHitPoints() << std::endl;

    std::cout << "\n2. ScavTrap attack:" << std::endl;
    std::cout << s1.getName() << " nrj before: " << s1.getNrjPoints() << std::endl;
    std::cout << c1.getName() << " hp before: " << c1.getHitPoints() << std::endl;
    s1.attack(c1.getName());
    c1.takeDamage(s1.getAttackDamage());
    std::cout << s1.getName() << " nrj after: " << s1.getNrjPoints() << std::endl;
    std::cout << c1.getName() << " hp after: " << c1.getHitPoints() << std::endl;

    std::cout << "\n3. ScavTrap repairing himself" << std::endl;
    std::cout << s1.getName() << " nrj before: " << s1.getNrjPoints() << std::endl;
    std::cout << s1.getName() << " hp before: " << s1.getHitPoints() << std::endl;
    s1.beRepaired(10);
    std::cout << s1.getName() << " nrj after: " << s1.getNrjPoints() << std::endl;
    std::cout << s1.getName() << " hp after: " << s1.getHitPoints() << std::endl;

    std::cout << "\n\n=== Test 8: Construction/Destruction Chaining ===" << std::endl;
    {
        ScavTrap temp("Temporary");
    }

    std::cout << "\n\n=== Test 9: Plymorphism ===" << std::endl;
    {
        ClapTrap *d = new ScavTrap;
        d->attack("new_target");
    }

    std::cout << "\n\n=== Test 10: All Destructors ===" << std::endl;
    return 0;
}