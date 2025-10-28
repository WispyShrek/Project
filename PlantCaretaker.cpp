	#include "PlantCaretaker.h"

	PlantCaretaker::PlantCaretaker() { }

	void PlantCaretaker::care() {
		std::cout << "PlantCaretaker is caring for plants\n";
	}

	void PlantCaretaker::update() {
		std::cout << "PlantCaretaker is updated\n";
	}

	void PlantCaretaker::notify(Customer* customer) {
		std::cout << "PlantCaretaker notified about a customer\n";
	}