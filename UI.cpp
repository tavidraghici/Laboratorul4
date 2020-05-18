#pragma once
#include "UI.h"
#include "Repository.h"
#include "Controller.h"
#include <iostream>

using namespace std;


ApothekeUI::ApothekeUI(Controller controller) : ctrl(controller) {
}


void Infos() {
	// Infos uber die mogliche Operationen

	cout << "\n\n";
	cout << "1. Einfugen Medikament\n";
	cout << "2. Loschen Medikament\n";
	cout << "3. Edit Medikament\n";
	cout << "4. Suchen Mediakment mit folgender Textsequenz\n";
	cout << "5. Suchen Medikamente mit Wert kleiner als:\n";
	cout << "6. Gruppieren Medikamente nach Preis\n";
	cout << "7. UNDO letzte Operation\n";
	cout << "8. REDO letzte Operation\n";
	cout << "9. Anzeigen alle Medikamente\n";
	cout << "0. Exit\n";
}


void ApothekeUI::UI() {

	Infos();
	int input;
	string name, new_name, zeichen;
	double konzentration, menge, preis, new_konzentration, new_menge, new_preis;
	cout << "\nIhre Nummer: "; cin >> input;
	while (input != 0) {
		if (input == 1) {
			cout << "Geben Sie Name, Konzentration, Menge und Preis ein:\n";
			cout << "Name: "; cin >> name;
			cout << "Konzentration: "; cin >> konzentration;
			cout << "Menge: "; cin >> menge;
			cout << "Preis: "; cin >> preis;
			Medikament medikament = Medikament(name, konzentration, menge, preis);
			ctrl.repo.einfugen(medikament);
		}
		else if (input == 2) {
			cout << "Geben Sie Name, Konzentration, Menge und Preis ein:\n";
			cout << "Name: "; cin >> name;
			cout << "Konzentration: "; cin >> konzentration;
			cout << "Menge: "; cin >> menge;
			cout << "Preis: "; cin >> preis;
			Medikament medikament = Medikament(name, konzentration, menge, preis);
			ctrl.repo.loschen(medikament);
		}
		else if (input == 3) {
			cout << "Geben Sie Daten uber die gewahlten Medikamente:\n";
			cout << "Name: "; cin >> name;
			cout << "Konzentration: "; cin >> konzentration;
			cout << "Menge: "; cin >> menge;
			cout << "Preis: "; cin >> preis;
			Medikament medikament = Medikament(name, konzentration, menge, preis);
			ctrl.repo.bearbeiten(medikament);
		}
		else if (input == 4) {
			ctrl.repo.zeichenkette();
		}
		else if (input == 5) {
			ctrl.repo.knapp();
		}
		else if (input == 6) {
			ctrl.repo.nachpreis();
		}
		else if (input == 7) {
			ctrl.repo.undo();
		}
		else if (input == 8) {
			ctrl.repo.redo();
		}
		else if (input == 9) {
			ctrl.repo.anzeigen();
		}
		else if (input == 0)
			break;
		else cout << "wrong input\n";

		cout << "\nInput: "; cin >> input;
	}
}
