#pragma once
#include <limits>

// ������� ������ ������� �� �������� �������� � �������
template<typename T>
int findSecondMaximum(T* array, int length) {
    if (length < 2) {
        return -1; // ������������ ��������� ��� ���������� ������� ���������
    }

    T highest = std::numeric_limits<T>::min(); // ������������ ��������
    T secondHighest = std::numeric_limits<T>::min(); // ������ �� �������� ��������
    int secondHighestIndex = -1; // ������ ������� ���������

    for (int i = 0; i < length; ++i) {
        if (array[i] > highest) {
            secondHighest = highest; // ��������� ������ ��������
            highest = array[i]; // ��������� ��������
        }
        else if (array[i] > secondHighest && array[i] < highest) {
            secondHighest = array[i]; // ������ ����� ������ ��������
            secondHighestIndex = i; // ��������� ������ ������� ���������
        }
    }

    return secondHighestIndex; // ���������� ������ ������� ��������� ��� -1, ���� �� �� ������
}
