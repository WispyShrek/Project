#include "LilyCreator.h"
#include "Lily.h"

Plant* LilyCreator::createPlant() {
	return new Lily();
}

LilyCreator::LilyCreator() = default;
