/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:03 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/02 14:52:04 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*int	main()
{
	ClapTrap a("A");
	ClapTrap const b("C");
	ClapTrap c(b);

	std::cout << "nrj a:" <<  a << std::endl;
	a.attack(c.getName());
	std::cout << "nrj a:" <<  a << std::endl;
	c.takeDamage(2);
	std::cout << "nrj c:" <<  c << std::endl;
	c.beRepaired(1);
	std::cout << "nrj c:" <<  c << std::endl;
	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.beRepaired(10);
	std::cout << "nrj c:" <<  c << std::endl;
	return (0);
}*/

int main()
{
    std::cout << "\t=== Test 1: Basic Construction ===" << std::endl;
    ClapTrap a("Alice");
    
    std::cout << "\n=== Test 2: Copy Constructor ===" << std::endl;
    ClapTrap b(a);
    
    std::cout << "\n=== Test 3: Default Constructor ===" << std::endl;
    ClapTrap c;
    
    std::cout << "\n=== Test 4: Assignment Operator ===" << std::endl;
    c = a;
    //std::cout << "Claptrap a is called: " << a.getName() << std::endl;
    //std::cout << "Claptrap c is called: " << c.getName() << std::endl;
    
    std::cout << "\n=== Test 5: Basic Attack ===" << std::endl;
    std::cout << a.getName() << " energy before attack: " << a.getNrjPoints() << std::endl;
    a.attack("Bob");
    std::cout << a.getName() << " energy after attack: " << a.getNrjPoints() << std::endl;
    
    std::cout << "\n=== Test 6: Take Damage ===" << std::endl;
    std::cout << "HitPoints before: " << a.getHitPoints() << std::endl;
    a.takeDamage(5);
    std::cout << "HitPoints after: " << a.getHitPoints() << std::endl;
    
    std::cout << "\n=== Test 7: Repair ===" << std::endl;
    std::cout << "HitPoints before: " << a.getHitPoints() << std::endl;
    std::cout << "Energy before: " << a.getNrjPoints() << std::endl;
    a.beRepaired(3);
    std::cout << "HitPoints after: " << a.getHitPoints() << std::endl;
    std::cout << "Energy after: " << a.getNrjPoints() << std::endl;
    
    std::cout << "\n=== Test 8: Attack/Repair without energy ===" << std::endl;
    ClapTrap d("David");
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << " attack: ";
        d.attack("Target");
    }
    std::cout << d.getName() << " actual energy: " << d.getNrjPoints() << std::endl;
    std::cout << d.getName() << " trying to attack:" << std::endl;
    d.attack("Target");
    std::cout << d.getName() << " trying to get repaired: " << std::endl;
    d.beRepaired(10);
    
    std::cout << "\n=== Test 9: Death ===" << std::endl;
    ClapTrap e("Eric");
    std::cout << e.getName() << " HitPoints: " << e.getHitPoints() << std::endl;
    e.takeDamage(10);
    std::cout << e.getName() << " HitPoints: " << e.getHitPoints() << std::endl;
    std::cout << e.getName() << " trying to attack:" << std::endl;
    e.attack("Target");
    
    std::cout << "\n=== Test 10: Destructors ===" << std::endl;
    return 0;
}