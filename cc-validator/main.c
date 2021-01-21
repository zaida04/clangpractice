#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    printf("CC Number: ");
    unsigned long cc = 0;
    scanf("%ld", &cc);
    unsigned int first_digit = cc;
    unsigned int second_digit = cc;
    unsigned int length = 0;

    unsigned long cc_clone1 = cc;
    while (cc_clone1 != 0)
    {
        second_digit = first_digit;
        first_digit = cc_clone1 % 10;
        length++;
        cc_clone1 /= 10;
    }

    char* base;

    if (first_digit == 3)
    {
        if ((second_digit != 4 && second_digit != 7) || length != 15)
        {
            printf("INVALID\n");
            return 1;
        }
        base = "AMEX";
    }
    else if (first_digit == 5)
    {
        if ((second_digit < 1 || second_digit > 5) || length != 16)
        {
            printf("INVALID\n");
            return 1;
        }
        base = "MASTERCARD";
    }
    else if (first_digit == 4)
    {
        if (length != 13 && length != 16)
        {
            printf("INVALID\n");
            return 1;
        }
        base = "VISA";
    }
    else
    {
        printf("INVALID\n");
        return 1;
    }

    long cc_clone2 = cc;
    unsigned int total1 = 0;
    unsigned int total2 = 0;
    bool alt = false;
    while (cc_clone2)
    {
        if (alt)
        {
            int temp = (cc_clone2 % 10) * 2;
            while (temp != 0)
            {
                total2 += temp % 10;
                temp /= 10;
            }
        }
        else
        {
            total1 += cc_clone2 % 10;
        }

        alt = !alt;
        cc_clone2 /= 10;
    }

    unsigned int total = total1 + total2;
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 1;
    }

    printf("%s\n", base);
    return 0;
}
