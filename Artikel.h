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

/**
 * Die Klasse Artikel beschreibt den Aufbau eines Artikelobjektes.
 */

class Artikel{
private:
	/**
	 * Eine Nummer die den Artikel eindeutig identifiziert.
	 */
	int nummer;

	/**
	 * Eine Beschreibung des Artikels in Worten.
	 */
	string beschreibung;

	/**
	 * Eine Zahl die angibt, wie oft der Artikel noch im Bestand enthalten ist.
	 */
	int bestand;

	/**
	 * Gibt den Stueckpreis fuer einen Artikel an.
	 */
	double preis;

	/**
	 * Validiert eine Artikelnummer auf ihre Gueltigkeit.
	 * @param nummer Nummer die von außen kommt und erst validiert werden muss bevor die Daten in der Klasse geaendert werden.
	 */
	void validiereNummer(int nummer);

	/**
	 * Validiert eine Beschreibung auf ihre Gueltigkeit.
	 * @param beschreibung String der die neue Beschreibung des Artikels darstellt
	 */
	void validiereBeschreibung(const string& beschreibung);

	/**
	 * Validert einen Bestand auf seine Gueltigkeit.
	 * @param bestand Neue Bestandsanzahl
	 */
	void validiereBestand(int bestand);

	/**
	 * Validiert einen Preis auf seine Gueltigkeit.
	 * @param preis Preis fuer den Artikel.
	 */
	void validierePreis(double preis);

public:
	/**
	 * Erstellt ein Artikelobjekt und belegt alle Attribute.
	 * @param nummer Artikelnummer
	 * @param beschreibung Beschreibung des Artikels
	 * @param bestand Bestandszahl dieses Artikels
	 * @param preis Preis des Artikels
	 */
	Artikel(int nummer, string beschreibung, int bestand, double preis);
	/**
	 * Erstellt ein Artikelobjekt ohne Bestand.
	 * @param nummer Artikelnummer
	 * @param beschreibung Beschreibung des Artikels
	 * @param preis Preis des Artikels
	 */
	Artikel(int nummer, string beschreibung, double preis);

	/**
	 * Loescht ein Artikelobjekt.
	 */
	~Artikel();

	/**
	 * Erhoeht den Bestand eines Artikels.
	 * @param neueAnzahl Anzahl der Artikel die neu hinzugefuegt werden
	 */
	void erhoeheBestand(int neueAnzahl);

	/**
	 * Verringert den Bestand eines Artikels.
	 * @param anzahl Anzahl der Artikel um die, der Bestand verringert werden soll.
	 */
	void verringereBestand(int anzahl);

	/**
	 * Gibt die Attribute des Artikelobjekts als String wieder.
	 * @return output Ein string der alle Attribute/Informationen enthaelt.
	 */
	string toString();

	/**
	 * Veraendert den Preis um eine bestimmte Prozentzahl.
	 * @param prozent Die Prozentangabe um die der Preis veraendert werden soll. Wenn also z.B. 80 eingegeben wird, so wird der neue Preis
	 * nur 80 Prozent des vorherigen Preises sein.
	 */
	void preisAendern(double prozent);

	/**
	 * getter-Methode für das Artikelnummer Attribut eines Artikelobjektes.
	 * @return Artikelnummer des Artikelobjekts
	 */
	int getArtikelNummer() const{
		return nummer;
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
	 * @return Bestand des Artikelobjektes
	 */
	int getBestand() const{
		return bestand;
	}

	/**
	 * getter-Methode fuer das Attribut preis eines Artikelobjektes.
	 * @return Preis des Artikelobjektes
	 */
	double getPreis() const{
		return preis;
	}

	/**
	 * setter-Methode fuer das Attribut artikelbestadn eines Artikelobjektes.
	 * @param bestand Artikelbestand der gesetzt werden soll
	 */
	void setBestand(int bestand){
		validiereBestand(bestand);
		this->bestand = bestand;
	}

	/**
	 * setter-Methode fuer das Attribut beschreibung eines Artikelobjektes.
	 * @param beschreibung Beschreibung des Artikels in Worten
	 */
	void setBeschreibung(string beschreibung){
		validiereBeschreibung(beschreibung);
		this->beschreibung = beschreibung;
	}

};



#endif /* ARTIKEL_H_ */
