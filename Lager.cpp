/*
 * Lager.cpp
 *
 *  Created on: 22.05.2022
 *      Author: freyermuth
 */

#include "Lager.h"

//TODO: Fehlerbehandlung!!!

Lager::Lager(string name){
	this->name = name;
}

Lager::~Lager(){
	loescheLager();
};

void Lager::legeNeuenArtikelAn(Artikel* artikel){
	artikelContainer.push_back(artikel);
}

void Lager::entferneArtikel(int nummer){
	auto iterator = findeArtikel(nummer);

	if(*iterator == NULL){//*
		throw "Artikel nicht gefunden!";
	}

	delete *iterator;
	artikelContainer.erase(iterator);

}

void Lager::bucheArtikelZugang(int nummer, int zugangsBetrag){
	auto iterator = findeArtikel(nummer);

	if(*iterator == NULL){
		throw "Artikel nicht gefunden!";
	}

	(*iterator)->erhoeheBestand(zugangsBetrag);
}

void Lager::bucheArtikelAbgang(int nummer, int abgangsBetrag){
	auto iterator = findeArtikel(nummer);

	if(*iterator == NULL){
		throw "Artikel nicht gefunden!";
	}

	(*iterator)->verringereBestand(abgangsBetrag);
}

vector<Artikel*>::iterator Lager::findeArtikel(int nummer){
	vector<Artikel*>::iterator it;
	for(it = artikelContainer.begin(); it != artikelContainer.end(); it++){
		if((*it)->getArtikelNummer() == nummer){
			return it;
		}
	}

	return NULL;
}

double Lager::berechneGesamtWert(){
	double gesamtpreis = 0.0;

	for(vector<Artikel*>::iterator it = artikelContainer.begin(); it != artikelContainer.end(); it++){
		gesamtpreis += (*it)->getBestand() * (*it)->getPreis();
	}

	return gesamtpreis;
}

void Lager::aenderePreis(int nummer, double prozent){
	auto iterator = findeArtikel(nummer);

	if(*iterator == NULL){
		throw "Artikel nicht gefunden!";
	}

	(*iterator)->preisAendern(prozent);

}

void Lager::loescheLager(){
	for(vector<Artikel*>::iterator it = artikelContainer.begin(); it != artikelContainer.end(); it++){
		delete *it;
	}
	artikelContainer.clear();
}



