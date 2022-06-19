/*
 * Lager.cpp
 *
 *  Created on: 22.05.2022
 *      Author: freyermuth
 */

#include "Lager.h"


Lager::Lager(string name){
	this->name = name;
}

Lager::Lager(const Lager& lager){
	this->name = lager.name;

	this->artikelContainer = lager.artikelContainer;
	int i = 0;
	for(vector<Artikel*>::iterator it = this->artikelContainer.begin(); it != this->artikelContainer.end(); i++, it++){
		this->artikelContainer[i] = new Artikel((*it)->getArtikelNummer(), (*it)->getBeschreibung(), (*it)->getBestand(), (*it)->getPreis());
	}
}

Lager& Lager::operator =(const Lager& lager){
	if(this == &lager){
		return *this;
	}

	if(!this->artikelContainer.empty()){ //falls schon artikel enhalten sind wird, dieser Speicher nun frei gegeben.
		for(vector<Artikel*>::iterator it = this->artikelContainer.begin(); it != this->artikelContainer.end(); it++){
			delete (*it);
		}
		this->artikelContainer.clear();
	}

	this->name = lager.name;

	for(int j = 0; j < lager.artikelContainer.size(); j++){
		Artikel* artikel_p = lager.artikelContainer[j];
		this->artikelContainer.push_back(new Artikel(artikel_p->getArtikelNummer(), artikel_p->getBeschreibung(), artikel_p->getBestand(), artikel_p->getPreis()));
	}

	return *this;
}

Lager::~Lager(){
	loescheLager();
};

void Lager::legeNeuenArtikelAn(Artikel* artikel){
	artikelContainer.push_back(artikel);
}

void Lager::entferneArtikel(int nummer){
	if(artikelContainer.size() > 0){ // Lager ist nicht leer
		for(vector<Artikel*>::iterator it = artikelContainer.begin(); it != artikelContainer.end() && !artikelContainer.empty(); it++){
			if((*it)->getArtikelNummer() == nummer){
				delete (*it);
				artikelContainer.erase(it);
			}
		}


	}else{
		throw LOESCHEN_AUF_LEEREM_LAGER;
	}


}

void Lager::bucheArtikelZugang(int nummer, int zugangsBetrag){
	if(artikelContainer.empty()){
		throw LAGER_LEER;
	}
	
	Artikel* gefundenerArtikel = findeArtikel(nummer);

	if(gefundenerArtikel == NULL){
		throw ARTIKEL_NICHT_GEFUNDEN;
	}

	gefundenerArtikel->erhoeheBestand(zugangsBetrag);
}

void Lager::bucheArtikelAbgang(int nummer, int abgangsBetrag){
	if(artikelContainer.empty()){
		throw LAGER_LEER;
	}
	
	Artikel* gefundenerArtikel = findeArtikel(nummer);

	if(gefundenerArtikel == NULL){
		throw ARTIKEL_NICHT_GEFUNDEN;
	}

	gefundenerArtikel->verringereBestand(abgangsBetrag);
}

Artikel* Lager::findeArtikel(int nummer){
	vector<Artikel*>::iterator it;
	for(it = artikelContainer.begin(); it != artikelContainer.end(); it++){
		if((*it)->getArtikelNummer() == nummer){
			return *it;
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

void Lager::aenderePreis(double prozent){
	if(!artikelContainer.empty()){
		for(vector<Artikel*>::iterator it = artikelContainer.begin(); it != artikelContainer.end(); it++){
			(*it)->preisAendern(prozent);
		}
	}else{
		throw PREISAENDERUNG_AUF_LEEREM_LAGER;
	}


}

void Lager::loescheLager(){
	for(vector<Artikel*>::iterator it = artikelContainer.begin(); it != artikelContainer.end(); it++){
		delete *it;
	}
	artikelContainer.clear();
}

string Lager::toString(){
	ostringstream ausgabe;

	ausgabe << "Lagerausgabe\n"
			<< "Lagername: " << getName() << "\n";

	ausgabe << "Anzahl der Artikel: " << artikelContainer.size() << "\n"
			<< "Artikelausgabe: \n";

	if(!artikelContainer.empty()){ //lager nicht leer
		for(vector<Artikel*>::iterator it = artikelContainer.begin(); it != artikelContainer.end(); it++){
			ausgabe << (*it)->toString() << "\n";
		}
	}else{ //lager leer
		ausgabe << "Keine Artikel vorhanden!\n";
	}


	return ausgabe.str();
}

bool Lager::istArtikelnummerBelegt(int nummer){
	if(findeArtikel(nummer) == NULL){
		return false;
	}

	return true;
}


