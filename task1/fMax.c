#include "../inc/fMax.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h> // ��� ������� isdigit
#include <stdbool.h> // ��� ������������� bool, true, false

bool errorflag_sintax = false; // ������������� ������
bool errorflag_empty = false;   // ������������� ������

/**
 * @brief ��������� ������� fMax.
 *
 * ��� ������� ������ ������ �� ����� � �������� �������������
 * �� � ����� �����, ����� ����� ������������ ��������. ����
 * ����������� ������������ ���������, ��������������� ����
 * errorflag_sintax. ���� ���� ������, ���������������
 * errorflag_empty.
 *
 * @param file ��������� �� ����, �� �������� �������� �����.
 * @return int ������������ �������� �� �����.
 */
int fMax(FILE *file)
{
    int max_value = INT_MIN;    // ������������� ������������� ��������
    int current_value;           // ������� ��������
    int has_numbers = 0;         // ���� ������� �����
    char current_str[20];        // ������ ��� �������� �������� ��������

    while (fscanf(file, "%s", current_str) == 1)
    {
        int is_number = 1; // ������������, ��� � current_str �����
        for (int i = 0; current_str[i] != '\0'; i++)
        {
            if (!isdigit(current_str[i]) && !(i == 0 && current_str[i] == '-')) // �������� �� ������������� �����
            {
                is_number = 0;
                break;
            }
        }

        if (!is_number)
        {
            errorflag_sintax = true;
            return 0;
        }

        current_value = atoi(current_str); // �������������� ������ � �����

        if (current_value > max_value)
        {
            max_value = current_value; // ���������� ������������� ��������
        }
        has_numbers = 1;
    }

    if (has_numbers)
    {
        return max_value; // ���������� ������������ ��������
    }
    else
    {
        errorflag_empty = true; // ��������� ����� ������� �����
    }
    return 0; // ���������� 0, ���� ����� ���
}
