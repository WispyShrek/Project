#include "CustomerAssistantCreator.h"

CustomerAssistantCreator::CustomerAssistantCreator() {}

Staff* CustomerAssistantCreator::createStaff() {
    return new CustomerAssistant();  
}
