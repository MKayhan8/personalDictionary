#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
							// personal dictionary


struct dictionary {
	int order;
	char data_word[20];
	char meaning[100];
	char sentence[100];
	char syn[20];
	char ant[20];
};
void do_exercise(struct dictionary *datas3);
void add_word (struct dictionary *datas2);
void search_word(struct dictionary *datas);
void menu(void);
#define SOURCE_CODE "data_base.txt"         
	
int i=0, count=1;
 FILE *file_ptr;
 fpos_t position;
 
int main(void)
{

	file_ptr = fopen(SOURCE_CODE,"a+");
	
	fgetpos (file_ptr,&position);
	
	int order;
	char data_word[20],meaning[100],sentence[100],syn[20],ant[20];
	while ( !feof(file_ptr) )
	{
		fscanf(file_ptr,"%d %s %s %s %s %s\n",&order,data_word,meaning,sentence,syn,ant);
		++count;
		
	}
	
	
	fsetpos (file_ptr,&position);
	
	
	struct dictionary *WORDS;
	WORDS = (struct dictionary*)malloc(sizeof(struct dictionary) * count+1);


		while (!feof(file_ptr) )
	{
		
		fscanf(file_ptr,"%d %s %s %s %s %s\n", &WORDS[i].order, WORDS[i].data_word, WORDS[i].meaning, WORDS[i].sentence, WORDS[i].syn, WORDS[i].ant);
		
		i++;
	
	}
	
	
	
	
	
	printf("\t------------------------------------------------------------------------");
	printf("\n\t\t Welcome to Personal Dictionary");
	printf("\n\t---------------------------------------------------------------------");
	int selection;
	do{
		menu();
		scanf("%d",&selection);
		if(selection ==1)
		{
			search_word(WORDS);
			fsetpos (file_ptr,&position);
		}
		else if (selection==2)
		{
			add_word(WORDS);
			fsetpos (file_ptr,&position);
		}
		else if(selection==3)
		{
			do_exercise(WORDS);
			fsetpos (file_ptr,&position);
		}
		
		
		
		
	}while(selection != 4);
	fclose(file_ptr);

	return 0;
}

void menu(void)
{
	printf("\nPlease choose what you want to do:");
	printf("\n1. Search a word:");
	printf("\n2. Add a word:");
	printf("\n3. Do some exercise:");
	printf("\n4. Quit\n");

	printf("--> Input your selection: ");
}


	
		
void search_word(struct dictionary *datas)
{

	printf("\nPlease input word which you want to search:");
		
	char searching_word[20];
	scanf("%s",&searching_word);
	int j;
	
	for(j=0 ; j<=i ;++j)
	{
			
		if (strstr(datas[j].data_word,searching_word) == '\0')
			continue;
		else
		{
			
			printf("\n------------------------------------------------------------------");
			printf("\n Word Number: %d\t",datas[j].order);
			printf("\n  %s ",datas[j].data_word);
			
			int z;
			for(z=0 ; z<strlen(datas[j].meaning); ++z)
			{
				if(datas[j].meaning[z]=='_')
					datas[j].meaning[z]=' ';
			}
			printf("%s\t",datas[j].meaning);
			for(z=0 ; z<strlen(datas[j].sentence); ++z)
			{
				if(datas[j].sentence[z]=='_')
					datas[j].sentence[z]=' ';
			}
				printf("\n  Ex: %s\t",datas[j].sentence);
				printf("\n%s\t",datas[j].syn);
				printf("\n%s\t",datas[j].ant);

		}
			printf("\n----------------------------------------------------------------");
	
	}

//	data_word[0]='\0',meaning[0]='\0',sentence[0]='\0',syn[0]='\0',ant[0]='\0';

}
void add_word (struct dictionary *datas2)
{

	datas2[count].order=count+1;

	fprintf(file_ptr,"\n%d",datas2[count].order);
	fprintf(file_ptr," ");
	int z;
	printf("\nPlease input word which you want to add to dictionary:");
	gets(datas2[count].data_word);
	gets(datas2[count].data_word);
	for(z=0 ; z<strlen(datas2[count].data_word); ++z)
			{
				if(datas2[count].data_word[z]==' ')
					datas2[count].data_word[z]='_';
			}
	fprintf(file_ptr,"%s",datas2[count].data_word);
	fprintf(file_ptr," ");
	
	printf("\nPlease input meaning of word:");
	//scanf("%s",datas2[count].meaning);
	gets(datas2[count].meaning);
	for(z=0 ; z<strlen(datas2[count].meaning); ++z)
			{
				if(datas2[count].meaning[z]==' ')
					datas2[count].meaning[z]='_';
			}
	fprintf(file_ptr,"%s",datas2[count].meaning);
	fprintf(file_ptr," ");
	
	printf("\nPlease input a sentence about word:");
//	scanf("%s",datas2[count].sentence);
	gets(datas2[count].sentence);
	for(z=0 ; z<strlen(datas2[count].sentence); ++z)
			{
				if(datas2[count].sentence[z]==' ')
					datas2[count].sentence[z]='_';
			}
	fprintf(file_ptr,"%s",datas2[count].sentence);
	fprintf(file_ptr," ");
	
	printf("\nPlease input synonym of word:");
//	scanf("%s",datas2[count].syn);
	gets(datas2[count].syn);
	
	for(z=0 ; z<strlen(datas2[count].syn); ++z)
			{
				if(datas2[count].syn[z]==' ')
					datas2[count].syn[z]='_';
			}
	fprintf(file_ptr,"%s",datas2[count].syn);
	fprintf(file_ptr," ");
	
	printf("\nPlease input antonym of word:");
	//scanf("%s",datas2[count].ant);
		gets(datas2[count].ant);
		for(z=0 ; z<strlen(datas2[count].ant); ++z)
			{
				if(datas2[count].ant[z]==' ')
					datas2[count].ant[z]='_';
			}
	fprintf(file_ptr,"%s",datas2[count].ant);
	fprintf(file_ptr," ");
	count=count+1;

	
	printf("\n Addig word is succesful..");

	
	
}
void do_exercise(struct dictionary *datas3)
{
	srand(time(NULL));
	char guess[20];
	printf("\nLet's do some exercise!");
	printf("\n---> Write the word which is correct one..");
	int c,z;
	c=rand()%count;
	for(z=0 ; z<strlen(datas3[c].meaning); ++z)
			{
				if(datas3[c].meaning[z]=='_')
					datas3[c].meaning[z]=' ';
			}
	printf("\n......... :  %s",datas3[c].meaning);
	printf("\n>>");
	scanf("%s",&guess);
	if (strstr(datas3[c].data_word,guess) == '\0')
			printf("\n :( NOT TRUE )");
		else
	{
		printf("\nBINGO !!!");
	}
	
	int prefer;
	printf("\n Do you want to exercise(1) again or return to menu(2)?");
	scanf("%d",&prefer);
	if(prefer==1)
	{
			do_exercise(datas3);
			fsetpos (file_ptr,&position);
		}
	else
		exit(0);
		
	
	
}












