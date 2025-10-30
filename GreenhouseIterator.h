#ifndef GREENHOUSEITERATOR_H
#define GREENHOUSEITERATOR_H
#include "Iterator.h"
#include <vector>

class greenHouse;

class GreenhouseIterator : public Iterator<greenHouse*>{
    public:
        GreenhouseIterator(std::vector<greenHouse*>& greenHouses);
        greenHouse* currItem() override;
        void first() override;
        bool isDone() override;
        void next() override;
        void prev() override;
    private:
        std::size_t currentIndex;
        std::vector<greenHouse*>& greenHouses;
};

#endif // GREENHOUSEITERATOR_H