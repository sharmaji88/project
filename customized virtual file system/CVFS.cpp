#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXFILES 100
#define FILESIZE 1024
struct SuperBlock
{
	int TotalInode;
	int FreeInode;
}Obj_Super;

struct inode
{
	char File_Name[50];
	int inode_number;
	int File_Size;
	int File_Type;
	int ActualFileSize;
	int Link_Count;
	int Reference_Count;
	char * Data;
	struct inode *next;
};

typedef struct inode INODE;
typedef struct inode * PINODE;
typedef struct inode ** PPINODE;

struct FileTable
{
	int ReadoffSet;
	int WriteOffset;
	int Count;
	PINODE pte=NULL;
	int Mode; 
};

typedef FileTable FILETABLE;
typedef FileTable * PFILETABLE;

struct UFDT
{
	PFILETABLE  ufdt[MAXFILES];	
}UFTDObj;

PINODE Head = NULL;//Global pointer of inode

void CreateUFDT()
{
	int i =0;
	for(i = 0; i < MAXFILES; i++)
	{
		UFTDObj.ufdt[i]=NULL;
	}
}
void CreateDILB()
{
	//Create Linked List of iNodes
	int i =1;
	PINODE newn = NULL;
	PINODE temp = Head;
	
	while(i <= MAXFILES) // Loop iterates 100 times
	{
		newn = (PINODE)malloc(sizeof(INODE));
		
		newn -> inode_number = i;
		newn -> File_Size = FILESIZE;
		newn -> File_Type=0;
		newn -> ActualFileSize=0;
		newn -> Link_Count=0;
		newn -> Reference_Count=0;
		newn ->  Data = NULL;
		newn -> next = NULL;
		
		if(Head = NULL)
		{ 						// First Node
			Head = newn;
			temp = Head;
		}
		else
		{
			temp->next=newn;
			temp=temp->next;
		}
		i++;
	}
	
	printf("Data inode List Block Created succesfully!!\n ");
	
}

void CreateSuperBlock()
{
	Obj_Super.TotalInode=MAXFILES;
	Obj_Super.FreeInode=MAXFILES;
	
	printf("Super Block Craeted Succesfully!!\n");
}

void SetEnviornment()
{
	CreateDILB();
	CreateSuperBlock();
	CreateUFDT();
	
	printf("Environment for the Virtual file System is set...\n");
}

void DisplayHelp()
{
	printf("-----------------------------------------------------\n");
	printf("open : It is used to open the existing file\n");
	printf("close : It is used to close the opened file\n");
	printf("read : It is used to read the contents file\n");
	printf("write : It is used to write the data into file\n");
	printf("lseek : It is used to change the offset of file\n");
	printf("stat : It is used to display the information of file\n");
	printf("stat : It is used to display the information of opned file\n");
	printf("------------------------------------------------------\n");
}
void ManPage(char *str)
{
	if(strcmp(str,"open")== 0)
	{
		printf("Description : it is used to open an existing file \n");
		printf("Usage : open File_name Mode \n");
	}
	else if(strcmp(str,"close") == 0)
	{
		printf("Description : it is used to close the existing file \n");
		printf("Usage : close File_name\n");
	}
	else if(strcmp(str,"ls") == 0)
	{
		printf("Description : it is used to list out all names of the files \n");
		printf("Usage : ls\n");
	}
	else
	{
		printf("Man Page Not Found\n");
	}
}
int main()
{
    // Variable Declations
    char str[80];
    char command[4][80];
    int count = 0;

    printf("Customised Virtual File System\n");
    
    SetEnviornment();
    
    while(1)
    {
		printf("Marvellous VFS :> ");
		fgets(str,80,stdin);//Accept the Command
		fflush(stdin);
		
		count = sscanf(str ,"%s %s %s %s",command[0],command[1],command[2],command[3]);//break that command into token
		
		if(count == 1)
		{
			if(strcmp(command[0],"help") == 0)
			{
				DisplayHelp();
			}
			else if(strcmp(command[0],"exit") == 0)
			{
				printf("Thank You for using Marvellous Virtual File System /n");
				break;
			}
			else if(strcmp(command[0],"cls") == 0)
			{
				system("cls"); //cls
			}
			else
			{
				printf("Command Not found !!\n");
			}
		}
		else if(count == 2)
		{
			if(strcmp(command[0],"man")==0)
			{
				ManPage(command[1]);
			}
			else
			{
				printf("command Not Found !!\n");
			}
		}
		else if(count == 3)
		{
		}
		else if(count == 4)
		{
			
		}
		else
		{
			printf("BAd command or File Name \n");
		}
	}
	return 0;
}






