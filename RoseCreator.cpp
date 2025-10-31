#include "RoseCreator.h"
#include "Rose.h"

Plant* RoseCreator::createPlant() {
	return new Rose();
}

RoseCreator::RoseCreator() = default;
