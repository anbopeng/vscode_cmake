#include <stdio.h>
#include <stdlib.h>

#include "stdint.h"
#include "string.h"
#include "stdbool.h"

#include "function.h"

void set_bit(uint8_t *value, int position)
{

    *value = *value | (1 << position);
}

void clear_bit(uint8_t *value, int position)
{
    *value = *value & ~(1 << position);

}
int main1()
{
    uint8_t value = 0b10101010;
    int position = 4;
    char print_str[20] = {0};

    set_bit(&value, position);
    itoa(value, print_str, 2);

    printf("Hello world, Set bit %d, then it will change to %s\n", position, print_str);

    position = 1;
    clear_bit(&value, position);
    itoa(value, print_str, 2);

    printf("Clear bit %d, then it will change to %s\n", position, print_str);

    return 0;
}

int find_biggest(int *data, int length)
{
    int biggest_one;
    if (length > 0)
        biggest_one = data[0];
    else
        return -1;

    for(int i = 0; i < length; i++)
    {
        if (data[i] > biggest_one)
        {
            biggest_one = data[i];
        }

    }
    return biggest_one;
}
void better_sort_array( int *data, int length)
{
    int i;

    for(i = 0; i < length-1; i++)
    {
        bool sorted = true;
        for(int j = 0; j < length-i-1; j++)
        {
            if (data[j] > data[j+1])
            {
                int temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;
                sorted = false;
            }
        }
        if (sorted)
        {

            break;
        }

    }
    printf("loop number: %d\r\n", i);

}
void sort_array( int *data, int length)
{
    int i;

    for(i = 0; i < length-1; i++)
    {

        for(int j = 0; j < length-i-1; j++)
        {
            if (data[j] > data[j+1])
            {
                int temp = data[j+1];
                data[j+1] = data[j];
                data[j] = temp;

            }
        }

    }
    printf("loop number: %d\r\n", i);

}





int main()
{
    int data_array[] = {2,3,6,8,9,0,22,33,6,1,99,32,0,-5,-6,100,102,104};

    sort_array(data_array, sizeof(data_array)/sizeof(data_array[0]));

    better_sort_array(data_array, sizeof(data_array)/sizeof(data_array[0]));

    print_array(data_array, sizeof(data_array)/sizeof(data_array[0]));

    int result = find_biggest(data_array, sizeof(data_array)/sizeof(data_array[0]));

    printf("The biggest one in this array:%d\r\n", result);
    check_endian();


    return 0;
}
