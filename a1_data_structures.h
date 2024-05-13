/********* a1_data_structures.h ********

    Student Name 	= Andrew Roberts
    Student Number	= 101268396
*/

/********** DON'T MODIFY **********/
#ifndef __A1_STRUCTURES_H__
#define __A1_STRUCTURES_H__

typedef struct milestone
{
    char name[100];
    float cost, time;
    unsigned short int num_employees;
    _Bool completed;
} milestone_t;

#endif