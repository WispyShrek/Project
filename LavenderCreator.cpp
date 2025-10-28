#include "LavenderCreator.h"
#include "Lavender.h"

Plant* LavenderCreator::createPlant() {
	return new Lavender();
}

LavenderCreator::LavenderCreator() = default; 
