#include <stdio.h>

typedef struct footballer
{
    char name[51];
    int id;
    int matches;
    int goals;
    int assists;
} Footballer;


/*
* Show the footballer on the screen
* Parameter: pointer to a footballer
*/
void showFootballer(Footballer *p)
{
    printf("\nID: %d\n", p->id);
    printf("Name: ");
    puts(p->name);
    printf("Matches Played: %d\n", p->matches);
    printf("Goals Scored: %d\n", p->goals);
    printf("Total of Assists: %d\n", p->assists);
}


/*
* Set the atributes of a footballer
* getting it from user
* Parameter: pointer to a footballer
*/
void setFootballer(Footballer *p)
{

    printf("\nType the ID: ");
    scanf("%d", &p->id);
    printf("Type the number of matches played: ");
    fflush(stdout);
    scanf("%d", &p->matches);
    printf("Type the number of goals scored: ");
    fflush(stdout);
    scanf("%d", &p->goals);
    printf("Type the total of assists: ");
    fflush(stdout);
    scanf("%d", &p->assists);
    getchar();
    printf("Type the name of the footballer: ");
    fflush(stdout);
    fgets(p->name, sizeof(p->name), stdin);
}

/*
* Show a list of footballers
* on the screen
* Parameters: an array of footballlers; the size of the array
*/
void showFootballerList(Footballer pArray[], int length)
{
  for (int i=0; i<length; i++)
    {
      printf("Footballer %d:\n", i+1);
      showFootballer(&pArray[i]);
    }
}
