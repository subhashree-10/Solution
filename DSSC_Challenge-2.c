/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>

typedef struct my_date_t
{
    uint8_t date;   /* date */
    uint8_t month;  /* month */
    uint16_t year;  /* year */
} my_date_t;

typedef enum status_t
{
    SUCCESS,    /* Function has successfully converted the string to structure */
    NULL_PTR,   /* Function is given NULL pointers to work with */
    INCORRECT   /* Incorrect values for date or month or year */
} status_t;

status_t string_to_date_converter(char* input_string, my_date_t* result_date)
{
    if (input_string == NULL || result_date == NULL)
        return NULL_PTR;
    
    // Parse the input string
    int day, month, year;
    if (sscanf(input_string, "%d/%d/%d", &day, &month, &year) != 3)
        return INCORRECT;
    
    // Check if the date, month, and year are within valid ranges
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0)
        return INCORRECT;
    
    // Assign the values to the result_date structure
    result_date->date = (uint8_t)day;
    result_date->month = (uint8_t)month;
    result_date->year = (uint16_t)year;
    
    return SUCCESS;
}

int main()
{
    char input_string[] = "09/06/2023";
    my_date_t result_date;
    
    status_t conversion_status = string_to_date_converter(input_string, &result_date);
    
    if (conversion_status == SUCCESS)
    {
        printf("Conversion successful!\n");
        printf("Day: %d\n", result_date.date);
        printf("Month: %d\n", result_date.month);
        printf("Year: %d\n", result_date.year);
    }
    else if (conversion_status == NULL_PTR)
    {
        printf("Error: NULL pointers provided.\n");
    }
    else if (conversion_status == INCORRECT)
    {
        printf("Error: Incorrect date format.\n");
    }
    
    return 0;
}
