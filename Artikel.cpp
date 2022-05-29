/*
 * artikel.cpp
 *
 *  Created on: 07.05.2022
 *      Author: freyermuth
 */


#include "Artikel.h"


Artikel::Artikel(int nummer, string beschreibung, int bestand, double preis){
	validiereNummer(nummer);
	validiereBeschreibung(beschreibung);
	validiereBestand(bestand);
	validierePreis(preis);

	this->nummer = nummer;
	this->beschreibung = beschreibung;
	this->bestand = bestand;
	this->preis = preis;
}

Artikel::Artikel(int nummer, string beschreibung, double preis): Artikel(nummer, beschreibung, 0, preis){}

Artikel::~Artikel(){}

void Artikel::erhoeheBestand(int neueAnzahl){
	validiereBestand(neueAnzahl);
	this->bestand = this->bestand + neueAnzahl;
}

void Artikel::verringereBestand(int anzahl){
	validiereBestand(anzahl);
	int neuerBestand = this->bestand - anzahl;
	if(neuerBestand < 0){
		throw "Mann kann nicht mehr abziehen wie da ist!";
	}
	this->bestand = neuerBestand;
}

string Artikel::toString(){
	ostringstream output;
	output << "Artikelnummer: " << getArtikelNummer() << "\t"
			<< "Beschreibung: " << getBeschreibung() << "\t"
			<< "Bestand: " << getBestand() << "\t"
			<< "Preis: " << getPreis() << "\n";
	return output.str();
}

void Artikel::preisAendern(double prozent){
	validierePreis(prozent);
	this->preis = this->preis * (prozent/100.0);
}

void Artikel::validierePreis(double preis){
	if(preis <= 0.0){
		throw "Preis muss groesser als 0 sein!";
	}
}

void Artikel::validiereBestand(int bestand){
	if(bestand < 0){
		throw "Der Bestand muss groesser oder gleich 0 sein!";
	}
}

void Artikel::validiereNummer(int nummer){
	if(nummer < 0){
		throw "Nummern kleiner als 0 sind nicht erlaubt!";
	}
}

void Artikel::validiereBeschreibung(const string& beschreibung){
	if(beschreibung.empty()){
		throw "Es muss ein String angegeben werden!";
	}
}
