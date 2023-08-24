#include <./digit_counting.h>
#include <cmath>

bool ReturnTrue(void)
{
    return true;
}

double Warp(double number, double factor)
{
    double warped_number = number;
    
    warped_number += factor;
    warped_number -= factor;

    return warped_number;
}

int CountSameSignificantDigits(double a, double b)
{
    int same_significant_digits{0};
    int counted_digits{0};

    double abs_a = fabs(a);
    double abs_b = fabs(b);

    if((a/abs_a) != (b/abs_b))
    {
        return 0;
    }

    long int whole_part_a = static_cast<long int>(a);
    long int whole_part_b = static_cast<long int>(b);

    double fractional_part_a = fabs(a - whole_part_a);
    double fractional_part_b = fabs(b - whole_part_b); 

    while((whole_part_a != 0) || (whole_part_b != 0))
    {
        if((whole_part_a % 10) == (whole_part_b % 10))
        {
            same_significant_digits++;
        }

        counted_digits++;

        if(counted_digits == 100)
        {
            return same_significant_digits;
        }

        whole_part_a /= 10;
        whole_part_b /= 10;
    }

    while(counted_digits < 100)
    {
        if(static_cast<int>(fractional_part_a*10) == static_cast<int>(fractional_part_b*10))
        {
            same_significant_digits++;
        }

        fractional_part_a = fabs(fractional_part_a*10 - static_cast<int>(fractional_part_a*10));
        fractional_part_b = fabs(fractional_part_b*10 - static_cast<int>(fractional_part_b*10));

        counted_digits++;
    }

    return same_significant_digits;
}