#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> // ��� ������������� bool, true, false
#include "../../inc/fMax.h"

/**
 * @brief �������� ������� ���������.
 *
 * ��� ������� �������������� ����� ������, ��������� ���� � �������
 * � �������� ������� fMax ��� ���������� ������������� ��������.
 * ������� ��������������� ��������� �� �������, ���� ��� ����������.
 *
 * @return int ��� ���������� ���������.
 */
int main(void)
{
    // ������������� ������
    errorflag_sintax = false;
    errorflag_empty = false;

    FILE *file = fopen("numbers.txt", "r"); // �������� �����
    if (file == NULL)
    {
        printf("Open error.\n");
        return 1;
    }

    int max_value = fMax(file); // ����� ������� fMax

    if (errorflag_empty)
    {
        printf("File is empty.\n");
        return 1;
    }
    else if (errorflag_sintax)
    {
        printf("Invalid syntax.\n");
        return 1;
    }

    printf("Max value: %d\n", max_value); // ����� ������������� ��������
    fclose(file); // �������� �����
    return 0;
}
