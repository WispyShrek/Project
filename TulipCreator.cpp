#include "TulipCreator.h"
#include "Tulip.h"

Plant* TulipCreator::createPlant() {
	return new Tulip();
}

TulipCreator::TulipCreator() = default;
