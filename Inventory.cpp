#include "Inventory.h"

template <typename T>
inline void Inventory<T>::addItem(T item)
{
}

template <typename T>
Iterator *Inventory<T>::CreateIterator()
{
    return nullptr;
}

template <typename T>
T Inventory<T>::getCurrItem()
{
    return T();
}

template <typename T>
bool Inventory<T>::isEmpty()
{
    return false;
}

template <typename T>
void Inventory<T>::removeItem(T item)
{
}
