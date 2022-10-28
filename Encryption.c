#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



void encrypt(char str[]){ 

	int index;
	int index2;
	int N=0;
	int R;
	int C;





	for (index=0; index<500; index++)	//"getting rid of spaces" loop
	{
		if ((str[index]==' ') && (str[index+1]!=' '))
		{
			str[index]=str[index+1];					//getting rid of single spaces between characters
			str[index+1]=' ';
		}
		else if ((str[index]==' ') && (str[index+1]==' '))
		{
			int k;
			k=index;
			while ((str[k]==' ') && k<500)
			{
				k++;									//getting rid of multiple spaces between characters
			}											//which is consequence of the first if statement
			str[index]=str[k];
			str[k]=' ';
		}
	}



	for (index=0; index<500; index++)	//"getting rid of tabs" loop
	{
		if ((str[index]=='	') && (str[index+1]!='	'))
		{
			str[index]=str[index+1];						//getting rid of single tabs between characters
			str[index+1]='	';
		}
		else if ((str[index]=='	') && (str[index+1]=='	'))
		{
			int k;
			k=index;
			while ((str[k]=='	') && k<500)
			{
				k++;									//getting rid of multiple tabs between characters
			}											//which is consequence of the first if statement
			str[index]=str[k];
			str[k]='	';
		}
	}


	for (index=0; index<500; index++)
	{
		if (str[index]==' ' || str[index]=='	' || str[index]=='\n')
		{
			continue;
		}
		else if (str[index]>='!' && str[index]<='~')
		{
			N++;											//calculating number of characters
		}
	}



	R=floor(sqrt(N));							//finding R and C through conditions
	C=floor(sqrt(N));
	if (R*C<N)
	{
		R=floor(sqrt(N));
		C=ceil(sqrt(N));
		if (R*C<N)
		{
			R=ceil(sqrt(N));
			C=ceil(sqrt(N));
		}

	}


	char arr[R*C];//new array with smaller, appropriate size

	for (index=0; index<R*C; index++)
	{
		arr[index]=str[index];						//copying values from initial array to the new one
	}




	int s=0;//additional index
	char mat[R][C];//multi-dimensional array (matrix)

	for (index=0; index<R; index++)						//copying values from the arr to matrix
	{
		for (index2=0; index2<C; index2++, s++)
		{
			mat[index][index2]=arr[s];
		}
	}



	char encrypted[C][R];

	for (index=0; index<C; index++)			//copying values from the matrix to the inversed matrix "encrypted"
	{
		for (index2=0; index2<R; index2++)
		{
			encrypted[index][index2]=mat[index2][index];
		}
	}


	for (index=0; index<C; index++)
	{
		for (index2=0; index2<R; index2++)
		{
			if(encrypted[index][index2]>=0 && encrypted[index][index2]<=20)
			{
				continue;
			}
			else
			{
				printf("%c", encrypted[index][index2]);
			}
		}
		printf(" ");
	}
	printf("\n");

}

typedef struct											//TASK 2
{
	int day;
	int month;
	int year;
}Date;

typedef struct
{
	int id;
	char firstname[20];
	char lastname[20];
	char result[9];
	Date dt;
}Member;


void encryptintofile(char str[], int size){							//ENCRYPTINTOFILE

	FILE *results;
	results=fopen("encrypted_results.txt", "a");


	int index;											//variables
	int index2;
	int N=0;
	int R;
	int C;



	for (index=0; index<size; index++)	//"getting rid of spaces" loop
	{
		if ((str[index]==' ') && (str[index+1]!=' '))
		{
			str[index]=str[index+1];					//getting rid of single spaces between characters
			str[index+1]=' ';
		}
		else if ((str[index]==' ') && (str[index+1]==' '))
		{
			int k;
			k=index;
			while ((str[k]==' ') && k<size)
			{
				k++;									//getting rid of multiple spaces between characters
			}											//which is consequence of the first if statement
			str[index]=str[k];
			str[k]=' ';
		}
	}



	for (index=0; index<size; index++)	//"getting rid of tabs" loop
	{
		if ((str[index]=='	') && (str[index+1]!='	'))
		{
			str[index]=str[index+1];						//getting rid of single tabs between characters
			str[index+1]='	';
		}
		else if ((str[index]=='	') && (str[index+1]=='	'))
		{
			int k;
			k=index;
			while ((str[k]=='	') && k<size)
			{
				k++;										//getting rid of multiple tabs between characters
			}												//which is consequence of the first if statement
			str[index]=str[k];
			str[k]='	';
		}
	}


	for (index=0; index<size; index++)
	{
		if (str[index]==' ' || str[index]=='	' || str[index]=='\n')
		{
			continue;
		}
		else if (str[index]>='!' && str[index]<='~')
		{
			N++;														//calculating number of characters
		}
	}



	R=floor(sqrt(N));										//finding R and C through conditions
	C=floor(sqrt(N));
	if (R*C<N)
	{
		R=floor(sqrt(N));
		C=ceil(sqrt(N));
		if (R*C<N)
		{
			R=ceil(sqrt(N));
			C=ceil(sqrt(N));
		}

	}


	char arr[R*C];//new array with smaller, appropriate size

	for (index=0; index<R*C; index++)
	{
		arr[index]=str[index];								//copying values from initial array to the new one
	}





	int s=0;//additional index
	char mat[R][C];//multi-dimensional array (matrix)

	for (index=0; index<R; index++)									//copying values from the arr to matrix
	{
		for (index2=0; index2<C; index2++, s++)
		{
			mat[index][index2]=arr[s];
		}
	}





	char encrypted[C][R];

	for (index=0; index<C; index++)			//copying values from the matrix to the inversed matrix "encrypted"
	{
		for (index2=0; index2<R; index2++)
		{
			encrypted[index][index2]=mat[index2][index];
		}
	}


	for (index=0; index<C; index++)							//fprinting the results to a new text file
	{
		for (index2=0; index2<R; index2++)
		{
			if(encrypted[index][index2]>=0 && encrypted[index][index2]<=32)
			{
				continue;
			}
			else
			{
				fprintf(results, "%c", encrypted[index][index2]);
			}
		}
		fprintf(results, " ");
	}
	fprintf(results, "\n");

	fclose(results);
}

int readresults(Member members[])									//READRESULTS
{
	FILE *pcr;
	pcr=fopen("pcr_results.txt", "r");



	if (pcr==NULL)								//checking if file is ok
	{
		printf("Problem opening file.");
		return 1;
	}


	int i=0;//variable for calculating number of lines
	do
	{


		fscanf(pcr, "%04d %s %s %s %d-%d-%d", &members[i].id, members[i].firstname, members[i].lastname,
				members[i].result, &members[i].dt.day, &members[i].dt.month, &members[i].dt.year);

		//scanning the file in the given template
		//04 was added to %d since ID contains 4 digits and that zeros would not be ignored



						if (members[i].id==0 && members[i].dt.day==0)			//condition if there are empty new lines in the end of file
						{
							break;
						}
		i++;

	}while (!(feof(pcr)));


	fclose(pcr);
	pcr=fopen("pcr_results.txt", "r");									//reopening the file in order to get through it again



	int step;
	for (step=0; step<i; step++)
	{
		int chnum=0;
		char ch;

		ch=getc(pcr);//This is needed because when counting in order to skip the newline character

		while (!(ch=='\n' || ch==EOF))									//loop for calculating number of characters in a line
		{
			chnum++;
			ch=getc(pcr);
		}

		char line[chnum];												//array of an appropriate size
		sprintf(line, "%04d %s %s %s %02d-%02d-%04d ", members[step].id, members[step].firstname,
				members[step].lastname, members[step].result, members[step].dt.day, members[step].dt.month,
				members[step].dt.year);
		//sprinting into an array
		encryptintofile(line, chnum);
	}


	fclose(pcr);
	return i;//returning number of lines
}


Member updateRecord(Member members[], int pos, char newresult[9], int day, int month, int year)
{

	sprintf(members[pos].result, "%s", newresult); //sprintf was used to copy the result to a struct member

	members[pos].dt.day=day;
	members[pos].dt.month=month;
	members[pos].dt.year=year;



			int len1=strlen(members[pos].firstname);
			int len2=strlen(members[pos].lastname);
			int size=4+len1+len2+8+10+4;

			/*first "4" - ID
			 *len1 - name
			 *len2 - surname
			 *"8" - result
			 *"10" - date
			 *second "4" - number of spaces in each line
			 */


			char line[size];//array of an appropriate size
			sprintf(line, "%04d %s %s %s %02d-%02d-%04d ", members[pos].id, members[pos].firstname,
					members[pos].lastname, members[pos].result, members[pos].dt.day, members[pos].dt.month, members[pos].dt.year);
			//sprintfing into an array

			encryptintofile(line, size);

	return members[pos];
}



int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Assylzhan Omarov\n\n");

	printf("------\n");
	printf("TASK 1\n");
	printf("------\n");
	char S[500] = "So, few years ago I found this really neat and fascinating thing that is called pizza among humans."
			" It's a circle looking, delicious piece of bread with sauce and various toppings on it."; // you can change this
	//I used a longer string to check the encryption
	encrypt(S);

	printf("\n\n\n------\n");
	printf("TASK 2\n");
	printf("------\n");


	Member members[100];

	int lineNumber = readresults(members);

	printf("Number of lines in a file \"pcr_results.txt\" is: %i", lineNumber);

	printf("\n\n\n------\n");
	printf("TASK 3\n");
	printf("------\n");

	int IDupd;		//updated ID

	do
	{
		printf("Please give an ID:");			//asking for an ID
		scanf("%d", &IDupd);

		int step;
		for (step=0; step<lineNumber; step++)//loop that goes over the whole list
		{
			if (IDupd==members[step].id)
			{
				int pos=step;

				char newresult[9];
				printf("Please give a new result:");
				scanf("%s", newresult);


				int day;
				int month;
				int year;

				printf("Please give the new date (dd-mm-yyyy):");
				scanf("%02d-%02d-%04d", &day, &month, &year);

				updateRecord(members, pos, newresult, day, month, year);//function use

				printf("A new record has been added!\n");
				break;
			}
			else if (IDupd==0)
			{
				break;
			}
			else if (step==lineNumber-1)	//if after checking the whole list for given ID program did not find it
			{
				printf("This ID does not exist!\n");
				continue;
			}
		}

	}while (IDupd!=0);

	return 0;
}
