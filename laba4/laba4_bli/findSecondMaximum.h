#pragma once
#include <limits>

// Находит индекс второго по величине элемента в массиве
template<typename T>
int findSecondMaximum(T* array, int length) {
    if (length < 2) {
        return -1; // Недостаточно элементов для нахождения второго максимума
    }

    T highest = std::numeric_limits<T>::min(); // Максимальное значение
    T secondHighest = std::numeric_limits<T>::min(); // Второе по величине значение
    int secondHighestIndex = -1; // Индекс второго максимума

    for (int i = 0; i < length; ++i) {
        if (array[i] > highest) {
            secondHighest = highest; // Обновляем второй максимум
            highest = array[i]; // Обновляем максимум
        }
        else if (array[i] > secondHighest && array[i] < highest) {
            secondHighest = array[i]; // Найден новый второй максимум
            secondHighestIndex = i; // Сохраняем индекс второго максимума
        }
    }

    return secondHighestIndex; // Возвращаем индекс второго максимума или -1, если он не найден
}
