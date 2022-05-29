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
	 * Loescht ein Lagerobjekt.
	 */
	~Lager();
	/**
	 * Legt einen neuen Artikel mit allen Attributen an und legt diesen im Lager ab.
	 * @param artikel Pointer auf das neue Artikelobjekt.
	 */
	void legeNeuenArtikelAn(Artikel* artikel);
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
	 * @nummer Artikelnummer des Artikels fuer den der Preis geaendert werden soll.
	 * @prozent Prozentangabe um wie viel der Preis veraendert werden soll.
	 */
	void aenderePreis(int nummer, double prozent);
	/**
	 * Berechnet den Gesamtwert der Artikel im Lager.
	 * @return Gesamtwert der im Lager enthaltenen Artikel.
	 */
	double berechneGesamtWert();

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
	 * Sucht einen Artikel anhand seiner Artikelnummer im Lager.
	 * @param nummer Artikelnummer des Artikels.
	 * @return Iteratorobjekt auf den Artikelpointer. NULL wenn kein passendes Objekt gefunden.
	 */
	vector<Artikel*>::iterator findeArtikel(int nummer);
	/**
	 * Loescht alle Artikel im Lager und das Lager selbst.
	 */
	void loescheLager();
};



#endif /* LAGER_H_ */
