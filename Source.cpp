#include<iostream>
#include<conio.h>
#include<ctime>
#include"help.h"
using namespace std;
struct node
{
	int x;
	int y;
	node* next;
 public:
	node()
	{
		x = 0;
		y = 0;
		next = nullptr;
	}
};
class snake
{
	node* head;
 public:
	snake()
	{
		node* p = new node();
		p->x = 0;
		p->y = 0;
		p->next = nullptr;
		head = p;
		p = nullptr;
		delete p;
	}
	void print()
	{
		node* q = head;
		while (q != nullptr)
		{
			cout << "*";
			q = q->next;
		}
	}
	void printdown()
	{
		node* q = head;
		while (q != nullptr)
		{
			cout << "*"<<endl;
			q = q->next;
		}
	}
	void insert(int x, int y)
	{
		node* p = new node();
		p->x = x;
		p->y = y;
		p->next = nullptr;
		if (head != nullptr)
		{
			node* q = head;
			while (q->next != nullptr)
			{
				q = q->next;
			}
			q->next = p;
			q = nullptr;
			p = nullptr;
			delete q;
			delete p;
		}
		else if (head == nullptr)
		{
			head = p;
			p = nullptr;
			delete p;
		}
	}
	~snake()
	{
		node* q = head;
		node* p = head;
		while (q != nullptr)
		{
			q = p->next;
			delete p;
			p = q;
		}
		delete head;
		head = nullptr;
	}
	node* gethead()
	{
		return head;
	}
};
class board
{
	int** backend;
public:
	board()
	{
		backend = new int* [20];
		for (int i = 0; i < 20; i++)
		{
			backend[i] = new int[20];
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				backend[i][j] = 0;
			}
		}
		srand(time(0));
		int x = 0, y = 0;
		for (int i = 0; i < 10; i++)
		{
			x = rand() % 10;
			y = rand() % 10;
			backend[x][y] = -1;
		}
		int x1 = 0;
		int y1 = 0;
		int x2 = 20;
		int y2 = 20;
		int i = 0;
		char c;
		while (y2<100)
		{
			myRect(x1, y1, x2, y2, 0, 0, 255);
			c = _getch();
			//x1 += 20;
			y1 += 20;
			//x2 += 20;
			y2 += 20;
			i++;
		}
	}
};
void cursor(snake snk)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	while (1) 
	{
		
			char c = _getch();
			if (c == 'w')
			{
				while (y > 0)
				{
					i--;
					y = y - 2;
					gotoxy(x, y);
					//system("cls");
					snk.print();
					Sleep(50);

				}
			}
			if (c == 'a')
			{
				while (x > 0)
				{
					j--;
					x = x - 3;
					gotoxy(x, y);
					//system("cls");
					snk.print();
					Sleep(50);

				}
			}
			if (c == 'd')
			{
				while (x < 25)
				{
					j++;
					x = x + 3;
					gotoxy(x, y);
					//system("cls");
					snk.print();
					Sleep(50);
				}
			}
			if (c == 's')
			{
			    while (y < 18)//18
				{
					i++;
					y = y + 2;
					gotoxy(x, y);
					//system("cls");
					snk.printdown();
					Sleep(50);
				}
			}
	}
}
int main()
{
	//board boardsnake;
	//snake snk;
	//snk.insert(1,1);
	//snk.insert(1, 1);
	//snk.insert(1, 1);
	//snk.insert(1, 1);

	//cursor(snk);

	int x1 = 0;
	int y1 = 0;
	int x2 = 20;
	int y2 = 20;
	int i = 0;
	char c;
	while (x2 < 200 )
	{
		myRect(x1, y1, x2, y2, 0, 0, 255);
		Sleep(30);
		while (y2 < 200)
		{
			myRect(x1, y1, x2, y2, 0, 0, 255);
			Sleep(30);
			//c = _getch();
			//x1 += 20;
			y1 += 20;
			//x2 += 20;
			y2 += 20;
			//i++;
		}
		//c = _getch();
		x1 += 20;
		//y1 += 20;
		x2 += 20;
		//y2 += 20;
		//i++;
	}
	while (y2 < 200)
	{
		myRect(x1, y1, x2, y2, 0, 0, 255);
		Sleep(30);
		//c = _getch();
		//x1 += 20;
		y1 += 20;
		//x2 += 20;
		y2 += 20;
		//i++;
	}

	system("pause");
}



