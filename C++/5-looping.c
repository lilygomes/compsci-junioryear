/*
 * Name: Frank Gomes
 * Date: 09-01-20
 * Lab: 5.0
 * Extra: TODO add an extra
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

// Method to get the area of a circle, given the radius
float area(int radius)
{
	// Takes the radius, multiplies (M_PI)r², and then rounds to the tenths place and returns that
	return roundf((M_PI * pow(radius,2)) * 10) / 10;
}

// Method to get the volume of a sphere, given the radius
float volume(int radius)
{
	// Takes the radius, multiplies (4/3)(M_PI)r³, then rounds to the tenths place and returns that
	return roundf(((4.0/3.0) * M_PI * pow(radius,3)) * 10) / 10;
}

// Method to take two radii and return the difference of each sphere's volume
float volume_difference(int radius1, int radius2)
{
	if (radius1 > radius2)
		return (volume(radius1) - volume(radius2));
	if (radius1 == radius2)
		return 0.0;
	if (radius2 > radius1)
		return (volume(radius2) - volume(radius1));
}

// Method that makes sure there are no invalid characters in a string to be converted to an int
// Returns 0 when there are none, 1 when there is at least one present
int contains_non_numeric_chars(char* string)
{
	// Get length of string, not including null characters
	int length;
	for (length = 0; string[length] != '\0' && string[length] != '\n'; ++length);
	// Check if number is too long to convert to an int
	if (length > 9)
		return -1;
	// Check if any character is not a number
	for (int i = 0; i < length; i++)
	{
		if (!isdigit(string[i]))
		{
			printf("Non-numeric char %c found at %d.\n", string[i], i);
			return 1;
		}
	}
	// If the previous loop did not return 1, then there are no non-numeric characters
	return 0;	
}

int main()
{
	// Print a table of radii from 1 to 10 and their area
	printf("Radius      Area\n");
	printf("-------     -------\n");
	for (int i = 1; i <= 10; i++)
		printf("%7d     %7.1f\n", i, area(i));
	// Print a table of even radii from 2 to 10 and their volume
	printf("Radius      Area\n");
	printf("-------     -------\n");
	for (int i = 2; i <= 10; i += 2)
		printf("%7d     %7.1f\n", i, volume(i));
	// Get two radii from the user and compare the resulting volumes
	// Variable that holds user input to process
	unsigned long string_bytes = 128;
	char* input;
	int radius1, radius2;
	// Loop that breaks when valid input is recieved
	while (1)
	{
		printf("Enter a radius as a whole number.\n");
		getline(&input, &string_bytes, stdin);
		// If given input is not a number, loop again
		if (contains_non_numeric_chars(input))
		{
			printf("That was not a valid input. Try again.\n");
			continue;
		}
		radius1 = atoi(input);
		break;
	}
	// Loop again for second radius
	while (1)
	{
		printf("Enter another radius as a whole number.\n");
		getline(&input, &string_bytes, stdin);
		if (contains_non_numeric_chars(input))
		{
			printf("That was not a valid input. Try again.\n");
			continue;
		}
		radius2 = atoi(input);
		break;
	}
	printf("The difference in volume is %.1f.\n", volume_difference(radius1, radius2));
	// Quit gracefully
	return 0;
}
