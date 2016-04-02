/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int noofdays(struct node *day1, struct node *day2, struct node *month1, struct node *month2, struct node *year1, struct node *year2)
{
	int y1 = 0, y2 = 0, m1 = 0, m2 = 0, d1 = 0, d2 = 0, c1 = 0, res, p;
	bool t = 0;
	while (year1 != NULL&&year2 != NULL)
	{
		y1 = y1 * 10 + (year1->data);
		year1 = year1->next;
		y2 = y2 * 10 + (year2->data);
		year2 = year2->next;
	}
	while (c1 != 2)
	{
		m1 = m1 * 10 + (month1->data);
		month1 = month1->next;
		m2 = m2 * 10 + (month2->data);
		month2 = month2->next;
		c1++;
	}
	while (c1 != 4)
	{
		d1 = d1 * 10 + (day1->data);
		day1 = day1->next;
		d2 = d2 * 10 + (day2->data);
		day2 = day2->next;
		c1++;
	}
	y1 = y1 + 1;
	y2 = y2 - 1;
	while (y1 <= y2)
	{
		if (y1 % 100 == 0)
		{
			if (y1 % 400 == 0)
			{
				res = res + 366;
				t = 1;
			}
			else
			{
				res = 355;
			}
		}
		else
		{
			res = res + 355;
		}
		y1++;
	}
	m1 = m1 + 1;
	if (res != 0)
	{
		while (m1 < 12)
		{
			if (m1 % 2 == 0 && m1 != 8 && m1 != 2 || m1 == 9 || m1 == 11)
			{
				res = res + 30;
				p = 2;
			}
			else if (m1 == 2)
			{
				if (t == 1)
				{
					res = res + 29;
					p = 1;
				}
				else
				{
					res = res + 28;
					p = 0;
				}
			}
			else
			{
				res = res + 31;
				p = 3;
			}
			m1++;
		}
		m2 = m2 - 1;
		while (m2 > 0)
		{
			if (m2 % 2 == 0 && m2 != 8 && m2 != 2 || m2 == 9 || m2 == 11)
			{
				res = res + 30;

			}
			else if (m2 == 2)
			{
				if (t == 1)
				{
					res = res + 29;

				}
				else
				{
					res = res + 28;

				}
			}
			else
			{
				res = res + 31;

			}
			m2--;
		}
	}
	
	else 
	{
		m1 = m1 + 1;
		m2 = m2 - 1;
		while (m1 <= m2)
		{
			if (m1 % 2 == 0 && m1 != 8 && m1 != 2 || m1 == 9 || m1 == 11)
			{
				res = res + 30;
				p = 2;
			}
			else if (m1 == 2)
			{
				if (t == 1)
				{
					res = res + 29;
					p = 1;
				}
				else
				{
					res = res + 28;
					p = 0;
				}
			}
			else
			{
				res = res + 31;
				p = 3;
			}
			m1++;
		}
}
	if (res != 0)
	{
		res = res + d2;
		if (p == 1)
		{
			res = res + (29 - d1);
		}
		else if (p == 0)
		{
			res = res + (28 - d1);
		}
		else if (p == 2)
		{
			res = res + (30 - d1);
		}
		else if (p == 3)
		{
			res = res + (31 - d1);
		}
	}
	else
	{
		res = res + (d2 - d1 - 1);
	}
	return res;
}

int between_days(struct node *date1head, struct node *date2head){

	struct node *month1, *day1, *year1,*month2,*day2,*year2;
	int count = 0,res=0;
	if (date1head != NULL&&date2head != NULL)
	{
		day1 = date1head;
		while (count != 2)
		{
			date1head = date1head->next;
			count++;
		}
		month1 = date1head;
		count = 0;
		while (count != 2)
		{
			date1head = date1head->next;
			count++;
		}
		year1 = date1head;
		count = 0;
		day2 = date2head;
		while (count != 2)
		{
			date2head = date2head->next;
			count++;
		}
		month2 = date2head;
		count = 0;
		while (count != 2)
		{
			date2head = date2head->next;
			count++;
		}
		year2 = date2head;
		res = noofdays(day1, day2, month1, month2, year1, year2);
		if (res == 0)
		{
			return -1;
		}
		else
		{
			return res;
		}
	}
	else
	{
		return -1;
	}
}