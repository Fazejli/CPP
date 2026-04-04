/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:31 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/02 14:52:32 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
    std::cout << "=== Test 1: FragTrap Construction Chaining ===" << std::endl;
    FragTrap f1("Frag1");
    
    std::cout << "\n\n=== Test 2: FragTrap Default Constructor ===" << std::endl;
    FragTrap f2;
    
    std::cout << "\n\n=== Test 3: FragTrap Copy Constructor ===" << std::endl;
    FragTrap f3(f1);
    
    std::cout << "\n\n=== Test 4: FragTrap Info ===" << std::endl;
    std::cout << "Name: " << f1.getName() << std::endl;
    std::cout << "HP: " << f1.getHitPoints() << std::endl;
    std::cout << "Energy: " << f1.getNrjPoints() << std::endl;
    std::cout << "Attack: " << f1.getAttackDamage() << std::endl;
    
    std::cout << "\n\n=== Test 5: FragTrap Attack  ===" << std::endl;
    std::cout << f1.getName() << " nrj before: " << f1.getNrjPoints() << std::endl;
    f1.attack("Enemy");
    std::cout << f1.getName() << " nrj after: " << f1.getNrjPoints() << std::endl;
    
    std::cout << "\n\n=== Test 6: All Three Classes ===" << std::endl;
    ClapTrap c("ALICE");
    ScavTrap s("BOB");
    FragTrap f("ROBOT");
    
    std::cout << "\n_General Infos:" << std::endl;
    std::cout << "ClapTrap - HP: " << c.getHitPoints() << ", Energy: " << c.getNrjPoints() << ", Attack: " << c.getAttackDamage() << std::endl;
    std::cout << "ScavTrap - HP: " << s.getHitPoints() << ", Energy: " << s.getNrjPoints() << ", Attack: " << s.getAttackDamage() << std::endl;
    std::cout << "FragTrap - HP: " << f.getHitPoints() << ", Energy: " << f.getNrjPoints() << ", Attack: " << f.getAttackDamage() << std::endl;
    
    std::cout << "\n_Attacks:" << std::endl;
    c.attack(f.getName());
    f.takeDamage(c.getAttackDamage());
    f.attack(s.getName());
    s.takeDamage(f.getAttackDamage());
    s.attack("target");

    std::cout << "\n_After Combat: " << std::endl;
    std::cout << "ClapTrap - HP: " << c.getHitPoints() << ", Energy: " << c.getNrjPoints() << ", Attack: " << c.getAttackDamage() << std::endl;
    std::cout << "ScavTrap - HP: " << s.getHitPoints() << ", Energy: " << s.getNrjPoints() << ", Attack: " << s.getAttackDamage() << std::endl;
    std::cout << "FragTrap - HP: " << f.getHitPoints() << ", Energy: " << f.getNrjPoints() << ", Attack: " << f.getAttackDamage() << std::endl;
    
    std::cout << "\n_FragTrap repairing himself" << std::endl;
    std::cout << f.getName() << " nrj before: " << f.getNrjPoints() << std::endl;
    std::cout << f.getName() << " hp before: " << f.getHitPoints() << std::endl;
    f.beRepaired(10);
    std::cout << f.getName() << " nrj after: " << f.getNrjPoints() << std::endl;
    std::cout << f.getName() << " hp after: " << f.getHitPoints() << std::endl;

    std::cout << "\nSpecial abilities:" << std::endl;
    s.guardGate();
    f.highFivesGuys();
    
    std::cout << "\n\n=== Test 7: Construction/Destruction Chaining ===" << std::endl;
    {
        FragTrap temp("Temporary");
    }
    
    std::cout << "\n\n=== Test 8: All Destructors ===" << std::endl;
    return 0;
}