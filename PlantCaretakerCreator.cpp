#include "PlantCaretakerCreator.h"
#include "PlantCaretaker.h"

PlantCaretakerCreator::PlantCaretakerCreator() {}

Staff* PlantCaretakerCreator::createStaff() {
    return new PlantCaretaker();   
}
