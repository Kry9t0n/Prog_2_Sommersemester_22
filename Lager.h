/*
 * Lager.h
 *
 *  Created on: 22.05.2022
 *      Author: freyermuth
 */

#ifndef LAGER_H_
#define LAGER_H_

#include "Artikel.h"
#include <vector>
/**
 * Lagerklasse um Artikelobjekte zu speichern und zu verwalten.
 */
class Lager {
public:
	/**
	 * Erstellt ein neues Lager.
	 * @param name Name des Lagers
	 */
	Lager(string name);
	/**
	 * Kopierkonstruktor
	 * @param lager Lager von dem die Kopie erstellt werden soll.
	 */
	Lager(const Lager& lager);
	/**
	 * Ueberschreiben des Gleichheitsoperators
	 * @param lager Konstane Referenz auf das zu kopierende Lagerobjekt.
	 */
	Lager& operator=(const Lager& lager);
	/**
	 * Loescht ein Lagerobjekt.
	 */
	~Lager();
	/**
	 * Legt einen neuen Artikel mit allen Attributen an und legt diesen im Lager ab.
	 * @param artikel Pointer auf das neue Artikelobjekt.
	 */
	void legeNeuenArtikelAn(Artikel *artikel);
	/**
	 * Entfernt einen Artikel aus dem Lager.
	 * @param nummer Artikelnummer des Artikels.
	 */
	void entferneArtikel(int nummer);
	/**
	 * Bucht einen Zugang für einen Artikel.
	 * @param nummer Artikelnummer des Artikels fuer den der Zugang gebucht werden soll.
	 * @param zugangsBetrag Betrag der zu dem Artikel hinzugefuegt werden soll.
	 */
	void bucheArtikelZugang(int nummer, int zugangsBetrag);
	/**
	 * Bucht einen Abgang für einen Artikel.
	 * @param nummer Artikelnummer des Artikels fuer den der Abgang gebucht werden soll.
	 * @param abgangsBetrag Anzahl der Artikel, um die der Betrag verringert werden soll.
	 */
	void bucheArtikelAbgang(int nummer, int abgangsBetrag);
	/**
	 * Aendert den Preis für alle Artikel um einen gewissen Prozentsatz.
	 * @prozent Prozentangabe um wie viel der Preis veraendert werden soll.
	 */
	void aenderePreis(double prozent);
	/**
	 * Berechnet den Gesamtwert der Artikel im Lager.
	 * @return Gesamtwert der im Lager enthaltenen Artikel.
	 */
	double berechneGesamtWert();
	/**
	 * Gibt die Daten des Lagers aus.
	 * @return Stringobjekt, das alle Informationen zu dem Lager enthaelt.
	 */
	string toString();
	/**
	 * Prueft ob einen Artikelnummer schon verwendet wird.
	 * @param nummer Artikelnummer die geprueft werden soll.
	 * @return true falls Artikelnummer bereits belegt ist, false sonst.
	 */
	bool istArtikelnummerBelegt(int nummer);
	/**
	 * getter-Methode fuer das Namensattribut.
	 * @return Name des Lagers
	 */
	string getName() {
		return this->name;
	}
	/**
	 * Sucht einen Artikel anhand seiner Artikelnummer im Lager.
	 * @param nummer Artikelnummer des Artikels.
	 * @return Pointer auf das Artikelobjekt. NULL wenn kein passendes Objekt gefunden.
	 */
	Artikel* findeArtikel(int nummer);
	/**
	 * Loescht alle Artikel im Lager und das Lager selbst.
	 */
	void loescheLager();
private:
	/**
	 * Name des Lagers.
	 */
	string name;
	/**
	 * Container der die im Lager enthaltenen Artikel enthaelt.
	 */
	vector<Artikel*> artikelContainer;
	/**
	 * Fehlerkonstante, falls Artikel nicht gefunden werden konnte.
	 */
	const string ARTIKEL_NICHT_GEFUNDEN = "Artikel nicht gefunden!";
	/**
	 * Fehlerkonstante, fuer loeschen in einem leeren Kager.
	 */
	const string LOESCHEN_AUF_LEEREM_LAGER =
			"Es kann nichts geloescht werden! Das Lager ist noch leer!";
	/**
	 * Fehlerkonstante, falls Lager leer ist.
	 */
	const string LAGER_LEER =
			"Es existieren noch keine Artikel! Lager ist noch leer!";
	/**
	 * Fehlerkonstante, fuer Preisaenderung auf leerem Lager.
	 */
	const string PREISAENDERUNG_AUF_LEEREM_LAGER =
			"Lager ist leer! Preise koennen nicht geaendert werden!";
};

#endif /* LAGER_H_ */
