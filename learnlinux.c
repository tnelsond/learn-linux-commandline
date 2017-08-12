/* When compiled the program should be saved as execute_me
 *
 * This program teaches the linux command line by having
 * the user move and copy the file among other things. 
 *
 * Public Domain - Tnelsond 2011 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE *fp = NULL;
	if(!strcmp(*argv, "./execute_me"))
		puts("Ok, so you've executed this program.\nNow change it's name to \"icanchangenames\" by typing: \"mv execute_me icanchangenames\" (without the quotes).\nThe first word after mv (move) is the source and the last one is the destination.\nSo the file gets moved from execute_me to icanchangenames.\nUse the \"ls\" command to list the files in the folder you're in.");
	else if(!strcmp(*argv, "./icanchangenames"))
	{
		fp = fopen("execute_me", "r");
		if(fp == NULL)
			puts("Great, so you can change names,\nBut can you copy this file and call the copy \"copied\"\n(Hint: use the cp (copy) command)");
		else
			puts("That other file is still there, you didn't move it, you copied!");
	}
	else if(!strcmp(*argv, "./copied"))
	{
		fp = fopen("icanchangenames", "r");
		if(fp == NULL)
			puts("You didn't copy! You just moved the file");
		else
			puts("So you copied.\nNow mv copied to copied2 and delete the other file.\nDelete the other file using the rm command.\nBut be careful, use rm -i to allow you to confirm deletes.");
	}
	else if(!strcmp(*argv, "./copied2"))
	{
		fp = fopen("icanchangenames", "r");
		if(fp == NULL)
		{
			puts("Did you delete that other file? (y/n)");
			if(getchar() == 'y')
				puts("Ok, I believe you.\nNow change the name of this file to x.");
			else
				puts("I appreciate your honesty.");
		}
		else
			puts("That other file is still there!");

	}
	else if(!strcmp(*argv, "./x"))
	{
		int x;
		fp = fopen("hello/f", "w");
		if(fp == NULL){
			fp = fopen("x", "r");
			fseek(fp, 0, SEEK_END);
			puts("What is the size of this file in bytes?\n(Hint: du -b\nif you don't include the filename of the thing to be measured it will show the size of the whole folder)");
			printf("Filesize: ");
			scanf("%d", &x);
			if(x == ftell(fp))
				puts("Either you are a good guesser or you actually used the command.\nOk, now make a new folder and call it hello. (Use the mkdir command, mkdir is short for make directory).");
			else
				puts("Wrong! Try again");
		}
		else{
			puts("You made a folder, congratulations. Now move this file into that folder but run it from here.\nTo run a program that's in a folder do something like so: myfolder/myfile");
		}
	}
	else if(!strcmp(*argv, "hello/x")){
		puts("Woohoo, you put x in a folder and ran it.\nNow use cd to go into the folder.\nFrom there rename the file jack.");
	}
	else if(!strcmp(*argv, "./jack")){
		puts("Sweet, now move jack into the parent folder (that's the folder we were in before).\n\"../\" is a shortcut for the parent folder.");
	}
	else if(!strcmp(*argv, "../jack")){
		puts("Okie dokie.\nEarlier I created a file in the hello folder, what is it's name?\nUse \"ls\" to list the files.");
		printf("filename: ");
		if(getchar() == 'f'){
			puts("\nI'm so proud of you.\nThis is the end of the game for now.");
		}
	}

	return 0;

	return 0;
}
