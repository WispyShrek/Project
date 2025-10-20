#include "InventoryIterator.h"

template <typename T>
inline T InventoryIterator<T>::currItem()
{
    return T();
}

template <typename T>
void InventoryIterator<T>::first()
{
}

template <typename T>
bool InventoryIterator<T>::isDone()
{
    return false;
}

template <typename T>
void InventoryIterator<T>::next()
{
}

template <typename T>
void InventoryIterator<T>::prev()
{
}
