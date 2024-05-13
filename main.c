/********* main.c ********

	Student Name 	= Andrew Roberts
	Student Number	= 101268396
*/

// Includes go here
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "a1_data_structures.h"
#include "a1_functions.h"

int main(void)
{
	float project_budget, project_duration; // defines variables to be assigned to user input

	milestone_t project_details[6]; // define array of structures called project_details that has 6 elements

	// welcomes the user to the project tracker and prompts them to enter a budget
	printf("Welcome to ABC Project Tracker\nEnter total project's Budget: ");
	project_details[0].cost = get_input_f();

	// prompts user to enter project's duration
	printf("Enter total project's duration in weeks: ");
	project_details[0].time = get_input_f();

	// calls number_of_employees function and prints the result to the user
	number_of_employees(project_details);
	printf("The planned number of employees needed is: %hu", project_details[0].num_employees);

	// initializes the name and completed members of structure with index 0
	strcpy(project_details[0].name, "Planned Details");
	project_details[0].completed = false;

	// creates an array of pointers containing project names
	char *milestone_name[5] = {"Technical requirements", "System Design", "Software Development", "Testing", "Product Release"};
	// calls init_milestone function for each name in milestone_name
	for (int i = 0; i < 5; i++)
	{
		project_details[i + 1] = init_milestone(milestone_name[i], project_details[0].cost / 5);
	}

	// prints spaces and a line to seperate the programs output and make it easier for the user to read
	printf("\n\n");
	dashed_line(44);
	printf("\n");

	// calls the milestone_updates function
	milestone_updates(project_details);
}