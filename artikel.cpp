/*
 * artikel.cpp
 *
 *  Created on: 07.05.2022
 *      Author: freyermuth
 */


#include "artikel.h"


Artikel::Artikel(int artikel_nbr, string beschreibung, int artikelbestand){
	this->artikel_nbr = artikel_nbr;
	this->beschreibung = beschreibung;
	this->artikelbestand = artikelbestand;
}

Artikel::~Artikel(){}

void Artikel::erhoeheArtikelBestand(int neueArtikelAnzahl){
	this->artikelbestand = this->artikelbestand + neueArtikelAnzahl;
}

void Artikel::verringereArtikelBestand(int artikelAnzahl){
	this->artikelbestand = this->artikelbestand - artikelAnzahl;
}

string Artikel::toString(){
	ostringstream output;
	output << "Artikelnummer: " << getArtikelNummer() << "\t"
			<< "Beschreibung: " << getBeschreibung() << "\t"
			<< "Bestand: " << getArtikelBestand() << "\n";
	return output.str();
}
