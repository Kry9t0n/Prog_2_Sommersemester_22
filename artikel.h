/*
 * artikel.h
 *
 *  Created on: 07.05.2022
 *      Author: freyermuth
 */

#include <string>
#include <sstream>

using namespace std;
#ifndef ARTIKEL_H_
#define ARTIKEL_H_

class Artikel{
private:
	/**
	 * Eine Nummer die den Artikel eindeutig identifiziert.
	 */
	int artikel_nbr;

	/**
	 * Eine Beschreibung des Artikels in Worten.
	 */
	string beschreibung;
	/**
	 * Eine Zahl die angibt, wie oft der Artikel noch im Bestand enthalten ist.
	 */
	int artikelbestand;

public:
	/**
	 * Erstellt ein Artikelobjekt.
	 * @param artikel_nbr Artikelnummer
	 * @param beschreibung Beschreibung des Artikels
	 * @artikelbestand Bestandszahl dieser Artikel
	 */
	Artikel(int artikel_nbr, string beschreibung, int artikelbestand);

	/**
	 * Loescht ein Artikelobjekt.
	 */
	~Artikel();

	/**
	 * Erhoeht den Bestand eines Artikels.
	 * @param neueArtikelAnzahl Anzahl der Artikel die neu hinzugefuegt werden
	 */
	void erhoeheArtikelBestand(int neueArtikelAnzahl);

	/**
	 * Verringert den Bestand eines Artikels.
	 * @param artikelAnzahl Anzahl der Artikel um die, der Bestand verringert werden soll.
	 */
	void verringereArtikelBestand(int artikelAnzahl);

	/**
	 * Gibt die Attribute des Artikelobjekts als String wieder.
	 * @return output Ein string der alle Attribute/Informationen enthaelt.
	 */
	string toString();

	/**
	 * getter-Methode für das Artikelnummer Attribut eines Artikelobjektes.
	 * @return Artikelnummer des Artikelobjekts
	 */
	int getArtikelNummer() const{
		return artikel_nbr;
	}

	/**
	 * getter-Methode fuer das Attribut beschreibung eines Artikelobjektes.
	 * @return Beschreibung des Artikelobjektes
	 */
	string getBeschreibung() const{
		return beschreibung;
	}

	/**
	 * getter-Methode fuer das Attribut artikelbestand eines Artikelobjektes.
	 * @return Artikelbestand des Artikelobjektes
	 */
	int getArtikelBestand() const{
		return artikelbestand;
	}

	/**
	 * setter-Methode fuer das Attribut artikelbestadn eines Artikelobjektes.
	 * @param Artikelbestand der gesetzt werden soll
	 */
	void setArtikelBestand(int artikelbestand){
		this->artikelbestand = artikelbestand;
	}
};



#endif /* ARTIKEL_H_ */
