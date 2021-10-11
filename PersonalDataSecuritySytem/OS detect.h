
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
//For windows

#ifdef _WIN32
#include<windows.h>
#include<dir.h>
#include<conio.h>
#define cls system("cls");

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Text_Color(int clrr)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(clrr & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}

//SetConsoleTitle("Donkey");

//For Linux

#elif __linux__
#include <termios.h>

#define cls system("clear");

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}

void Text_Color(int clrr)
{
    if(clrr==0)//black
    printf("\033[0;30m");
    else if(clrr==1)//blue
    printf("\033[0;34m");
    else if(clrr==2)//green
    printf("\033[0;32m");
    else if(clrr==3)//aqua
    printf("\033[0;36m");
    else if(clrr==4)//red
    printf("\033[0;31m");
    else if(clrr==5)//purple
    printf("\033[0;35m");
    else if(clrr==6)//yellow
    printf("\033[0;33m");
    else if(clrr==7)//white
    printf("\033[0;37m");
    else if(clrr==8)//grey
    printf("\033[0;90m");
    else if(clrr==9)//light blue
    printf("\033[0;94m");
    else if(clrr==10)//light green
    printf("\033[0;92m");
    else if(clrr==11)//light aqua
    printf("\033[0;96m");
    else if(clrr==12)//light red
    printf("\033[0;91m");
    else if(clrr==13)//light purple
    printf("\033[0;95m");
    else if(clrr==14)//light yellow
    printf("\033[0;93m");
    else if(clrr==15)//light white
    printf("\033[0;97m");
   else
   {
        cls;
        printf("Your color code not supported\n");
   }
}

void Sleep(unsigned int tms) {
   usleep(tms * 1000);
}
//getch

static struct termios old, current;

/* Initialize new terminal i/o settings */
void initTermios(int echo)
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void)
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo)
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void)
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void)
{
  return getch_(1);
}

long long int poww(long long int n,int power)
{
long long int s=n;
    for(int i=1;i<power;i++)
    {
        s=s*n;
    }
    return s;
}
#endif
