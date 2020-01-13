

#include "pch.h"

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

char** doesCircleExist(int commands_count, char** commands, int* result_count) {

	char ** ret = (char **)malloc(commands_count);
	*result_count = commands_count;

	for (int i = 0; i < commands_count; i++) {
		ret[i] = (char *)malloc(4);
		ret[i][2] = '\0';
		ret[i][3] = '\0';
	}

	for (int currCommand = 0; currCommand < commands_count; currCommand++)
	{
		int distance[4] = { 0,0,0,0 };

		int currentDirection = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < strlen(commands[currCommand]); j++) {
				if (commands[currCommand][j] == 'M') {
					distance[currentDirection]++;
				}
				if (commands[currCommand][j] == 'R') {
					currentDirection++;
					if (currentDirection == 4) {
						currentDirection = 0;
					}
				}
				if (commands[currCommand][j] == 'L') {
					currentDirection--;
					if (currentDirection == -1) {
						currentDirection = 3;
					}
				}
			}
		}

		//assume no
		strcpy(ret[currCommand], "NO");

		// all distances zero then in space
		if (distance[0] == distance[2] &&
			distance[1] == distance[3] 
			)
		{
			strcpy(ret[currCommand], "YES");
		}

		

	}
	return ret;
}

// M = move forward
// L = turn 90 degrees left
// R = turn 90 degrees Right

// if robot continues to execute list of commands will it remained confirned in some space?

int main()
{
	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "MR";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "MRMR";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "MRMRMR";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "MMRMRML";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "MMRR";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "MMRRMLMRMRMLML";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "LRLRLRRR";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}

	{
		char ** commands = (char **)malloc(1 * sizeof(char**));

		char  s[] = "M";
		commands[0] = s;
		int t = 0;

		char ** ret = doesCircleExist(1, commands, &t);

		printf("Is confined to space: %s\n\n", ret[0]);
	}
}
