/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:44:50 by fadwa             #+#    #+#             */
/*   Updated: 2026/04/04 12:45:04 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	for (int i = 0; i < 4; i++) {
		if (src._templates[i])
			_templates[i] = src._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete _templates[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			delete _templates[i];
			if (rhs._templates[i])
				_templates[i] = rhs._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return *this;
}

// Stocke une COPIE du template (le sujet dit "copies the materia")
void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_templates[i]) {
			_templates[i] = m->clone();
			delete m; // on a cloné, on libère l'original passé en param
			return;
		}
	}
	// Si plein, on libère quand même pour éviter une fuite
	delete m;
}

// Retourne un clone du template correspondant au type, ou NULL si inconnu
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return NULL;
}