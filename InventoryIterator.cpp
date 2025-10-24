#include "InventoryIterator.h"

InventoryIterator::InventoryIterator(std::vector<std::string> & items) : items(items), currentIndex(0){
}

std::string InventoryIterator::currItem()
{
    if(!isDone()){
        return items[currentIndex];
    }else{
        std::cout << "No current item, iterator is done." << std::endl;
        return std::string();
    }
}

void InventoryIterator::first(){
    currentIndex = 0;
}

bool InventoryIterator::isDone(){
    return currentIndex >= items.size();
}

void InventoryIterator::next(){
    if(!isDone()){
        currentIndex++;
    }
}

void InventoryIterator::prev(){
    if(currentIndex > 0){
        currentIndex--;
    }
}
