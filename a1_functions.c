/********* definitions.c ********

   Student Name 	= Andrew Roberts
   Student Number	= 101268396
*/

// Your solution goes here

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "a1_data_structures.h"
#include "a1_functions.h"

#define MAX_HOURS 40
#define SALARY_PER_HOUR 25

/*
  Prints n dashses
*/
void dashed_line(unsigned short int n)
{
   for (int i = 0; i < n; i++) // prints dashes while i < n
   {
      printf("-");
   }
}

/*
   Get user float input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
float get_input_f(void)
{
   float input_f;
   scanf("%f", &input_f); // gets user input
   if (input_f < 0)       // checks if input is less than 0 and prompts them to enter a positive value
   {

      printf("\n");
      dashed_line(44);
      printf("\nThe value you entered is wrong\nEnter a positive value: ");
      return get_input_f(); // calls the function until a valid input is given
   }
   return input_f; // returns input
}

/*
   Get unsigned short integer user input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
unsigned short int get_input_usi(void)
{
   short signed int input;
   scanf("%hi", &input);       // gets user input
   if (input < 0 || input > 5) // checks if input is less than 0 or greater than 5 and prompts them to enter a value between 0 and 5
   {
      printf("\n");
      dashed_line(44);
      printf("\nThe value you entered is wrong\nEnter a value between 0 and 5: ");
      return get_input_usi(); // calls the function until a valid input is given
   }
   return input; // returns input
}

/*
  Gets user yes or no input, Y for yes, N for no
*/
bool milestone_complete_input(void)
{
   char input;
   printf("Is this milestone complete?: (Y/N)");
   scanf(" %c", &input); // gets user input
   if (input == 'Y')
   {
      return true;
   }
   else if (input == 'N')
   {
      return false;
   }
   else
   {
      printf("Invalid input!\n");
      return milestone_complete_input(); // calls the function until a valid input is given
   }
}

/*
  Gets user yes or no input for finishing remaining milestones, Y for yes, N for no
*/
bool finish_milestone_input(void)
{
   char input;
   printf("Do you want to finish the remaining milestones? (Y/N)");
   scanf(" %c", &input); // gets user input
   //checks user input 
   if (input == 'Y')
   {
      return true;
   }
   else if (input == 'N')
   {
      return false; 
   }
   else
   {
      printf("Invalid input!\n");
      return finish_milestone_input(); // calls the function until a valid input is given
   }
}

/*
   Calculate number of employees needed for the project based on cost and time
*/
void number_of_employees(milestone_t *project_details)
{
   float salary_ft; // defines local variable to be used in calculations

   salary_ft = project_details[0].time * MAX_HOURS * SALARY_PER_HOUR; //calculates full time salary (salary_ft) using time member obtained from user input

   project_details[0].num_employees = round(project_details[0].cost / salary_ft); // calculates the number of employees and rounds the result using the round() function
}

/*
   Initialize milestones with names and planned budget
*/
milestone_t init_milestone(char stage_name[], float assigned_budget)
{
   milestone_t project_details; // defines project_details structure

   strcpy(project_details.name, stage_name); // copies the name from stage name to the structures name member
   project_details.cost = assigned_budget;   // sets the structures cost member to the assigned budget

   return project_details; // returns the structure with initilized name and cost members
}

/*
   prints milestones and prompts the user to choose a milestone 1-5 to see the stats and update them if mielstone is not complete, if user enters 0 it checks if all milestones are complete
*/
void milestone_updates(milestone_t project_d[])
{
   print_menu(); // calls print_menu function

   unsigned short int input = get_input_usi(); // gets user input for an unsigned short int

   if (input == 0) // user enters 0
   {
      check_project_completion(project_d, 5); // calls fucntion check_project_completion
   }

   else if (project_d[input].completed) // structure with index the user entered is completed
   {
      print_stats(project_d[input]); // calls print stats
      printf("\n");
      dashed_line(44);
      printf("\n%s milestone is completed\n\tcannot be updated\n", project_d[input].name); // prints structure name member
      dashed_line(44);
      printf("\n");
      milestone_updates(project_d); // calls milestone_updates function to re-prompt the user for input
   }
   else
   {
      print_stats(project_d[input]);  // calls print_stats function
      update_stats(project_d, input); // calls update_stats fucntion
      print_stats(project_d[input]);  // calls print_stats function with updated stats
   }
}
/*
   Print menu with a list of milestones/options for the user to choose from
*/
void print_menu(void)
{
   printf("\nWhich milestone you want to update? (0 to exit):\n1. Technical requirements\n2. System Design\n3. Software Development\n4. Testing\n5. Product release\n\nYour choice is: ");
}

/*
   Print out current stats of each milestone/project
   (i.e, print all members of the milestone_t struct)
*/
void print_stats(milestone_t details)
{
   char status[4];        // initilizes an array used for printing yes or no based on struture's completed member value
   if (details.completed) // checks value of completed member
   {
      strcpy(status, "Yes"); // copies Yes to status
   }
   else
   {
      strcpy(status, "No"); // copies No to status
   }

   // prints a header called Milestone Stats
   printf("\n");
   dashed_line(12);
   printf(" Milestone Stats ");
   dashed_line(12);

   // prints a title with currcnt structure's name
   printf("\nBelow is \"%s\" current stats:\n", details.name);
   dashed_line(44);

   // prints the values of the structure's time, num_employees, cost and completed members
   printf("\n\nActual time: %0.2f weeks", details.time);
   printf("\nActual number of employees: %hu", details.num_employees);
   printf("\nActual cost: %0.2f$", details.cost);
   printf("\nCompleted: %s\n", status);
}

/*
   Update the stats of the milestones (not the project).
   (i.e., Asks the user to update time, number of employees and completed.
    Cost is calculated based on the input data)
*/
void update_stats(milestone_t milestone_array[], int milestone_num)
{
   // defines variables to be used in calculations
   float a_time, a_cost;
   unsigned short int n_employees;
   char completed;

   // prints an update stats title and gets user input for structure's time, num_employees and completed members and updates them according accordingly
   printf("\n-------------- Update Stats ----------------\n\n");
   printf("Enter the milestone's actual time: ");
   a_time = get_input_f();
   milestone_array[milestone_num].time = a_time;

   printf("Enter the milestone's actual number of employees: ");
   n_employees = get_input_usi();
   milestone_array[milestone_num].num_employees = n_employees;

   a_cost = n_employees * a_time * MAX_HOURS * SALARY_PER_HOUR; // equation for calculating actaul cost given user input for time and num_employees
   milestone_array[milestone_num].cost = a_cost;

   // gets user input by calling milestone_complete_input function and checks its value
   if (milestone_complete_input() == true)
   {
      milestone_array[milestone_num].completed = 1; // changes milestone's completed value to 1
   }
   printf("Stats Updated!\n");
   print_stats(milestone_array[milestone_num]);
   milestone_updates(milestone_array); // calls milestone_updates to re-prompt the user for further milestone updates or exiting the program
}

/*
   Check if all milestones are completed or not. If completed, updated the project's details to completed.
*/
void check_project_completion(milestone_t milestone_array[], int num_milestones)
{
   for (int i = 1; i < num_milestones; i++) // checks if structure completed member is completed for each milestone
   {
      // prints project's current state
      //  if milestone is not completed, prompt the user if they want to finish remaining milestones, if yes, calls milestone_updates function
      // if not, exits the loop and does final project calculations
      if (!(milestone_array[i].completed))
      {
         printf("\n");
         dashed_line(44);
         printf("\n---------- Project's Performance -----------\n");
         dashed_line(44);
         printf("\n\n");
         print_stats(milestone_array[0]); // calls print_stats function
         if (finish_milestone_input())
         {
            milestone_updates(milestone_array); // calls milestone_updates function
         }
         break; // exits the loop
      }
   }
   // calculates actual project cost by summing each milestone's cost member and compares it to planned budget
   float total_cost;

   // iterates through each milestone's cost member and adds them to the local variable total_cost
   for (int i = 0; i < num_milestones; i++)
   {
      total_cost += milestone_array[i + 1].cost;
   }
   printf("\n");
   dashed_line(44);
   printf("\n------ Final Project's Performance ------\n");
   dashed_line(44);
   // checks if total_cost is greater than or less than planned details cost member, printing the project's cost was above or below beudget accordingly
   if (total_cost < milestone_array[0].cost)
   {
      printf("\n\nThe project's cost is below budget!\n");
   }
   else
   {
      printf("\n\nThe project's cost is above budget!\n");
   }
   // prints the final results of the project's cost
   printf("Planned budget: %0.2f\n", milestone_array[0].cost);
   printf("Actual Cost: %0.2f\n\n", total_cost);
   dashed_line(44);
   printf("\n--- The program will quit now! Goodbye! ---\n");
   dashed_line(44);
   exit(0); // exit the program
}