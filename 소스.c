#include <stdio.h>
#include <Windows.h>
#include <conio.h>
typedef int bool;
#define true 1
#define false 0
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
struct s {
	int x; 
	int y;
};
void setcursortype(CURSOR_TYPE c)
{
	system("mode con cols=80 lines=25");
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
void gotoxy(int x, int y)
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

struct s ddong[1000];
int main(void)
{
	setcursortype(NOCURSOR);
	int px = 40, py = 24, x, y, cnt = 0, flag = 1;
	char ch;
	gotoxy(px, py);
	printf("б▌");
	while (true)
	{
		Sleep(20);
		if (flag == 1) {
			for (int i = 0; i < cnt; i++) {
				gotoxy(ddong[i].x, ddong[i].y);
				printf("  ");
				ddong[i].y++;
				gotoxy(ddong[i].x, ddong[i].y);
				printf("бс");
			}
		}
		else {
			for (int i = 0; i < 25; i++) {
				gotoxy(ddong[i].x, ddong[i].y);
				printf("  ");
				if (ddong[i].y + 1 == 25)
					continue;
				ddong[i].y++;
				gotoxy(ddong[i].x, ddong[i].y);
				printf("бс");
			}
		}
		if(kbhit)
			ch = getch();

		gotoxy(px, py);
		printf("  ");
		
		if (px > 0 && px < 78) {
			switch (ch)
			{
			case 'a':
				if (px > 0) px -= 2;
				break;
			case 'd':
				if (px < 79) px += 2;
			}
		}
		gotoxy(px, py);
		printf("б▌");

		int r;
		r = rand() % 80;
		if (r % 2)
			r -= 1;
		int x = r, y = 0;
		gotoxy(x, y);
		ddong[cnt].x = x;
		ddong[cnt++].y = y;
		if (cnt == 25)
		{
			flag = 0;
			cnt %= 25;
		}
		for (int i = 0; i < 999; i++) {
			if (ddong[i].y == 23&&ddong[i].x==px)
			{
				return 0;
			}
		}
	}
}