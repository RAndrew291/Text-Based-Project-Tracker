/********* a1_functions.h ********
	
	Student Name 	= Andrew Roberts
	Student Number	= 101268396
*/
#include "a1_data_structures.h"
/*
   Calculate number of employees needed for the project based on cost and time
*/
void number_of_employees(milestone_t *project_details);

/* 
   Initialize milestones with names and planned budget
*/
milestone_t init_milestone(char stage_name[], float assigned_budget);


/* 
   Get unsigned short integer user input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
unsigned short int get_input_usi(void);


/*
   Get user float input. The value must be positive.
   If negative value entered ask user to re-enter a positive value
*/
float get_input_f(void);


/* 
   Print menu with a list of milestones/options for the user to choose from
*/
void print_menu(void);


/*
   Print out current stats of each milestone/project
   (i.e, print all members of the milestone_t struct)
*/
void print_stats(milestone_t details);


/*
   Update the stats of the milestones (not the project).
   (i.e., Asks the user to update time, number of employees and completed.
    Cost is calculated based on the input data)
*/
void update_stats(milestone_t milestone_array[], int milestone_num);

/*
   Check if all milestones are completed or not. If completed, updated the project's details to completed.
*/
void check_project_completion(milestone_t milestone_array[], int num_milestones);

/********** DON'T MODIFY **********/

// Extra functions' Prototypes/Declarations go here

/*
  prints n dashses
*/
void dashed_line(unsigned short int n);

/*
  Gets user yes or no input for milestone completion, Y for yes, N for no 
*/
bool milestone_complete_input(void);

/*
  Gets user yes or no input for finishing remaining milestones, Y for yes, N for no 
*/
bool finish_milestone_input(void);

/*
   prints milestones and prompts the user to choose a milestone 1-5 to see the stats and update them if mielstone is not complete, if user enters 0 it checks if all milestones are complete
*/
void milestone_updates(milestone_t project_d[]);
