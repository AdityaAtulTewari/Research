/*******************************************************************************
 * Data.c
 * This is the C file for the first attempt's structures for storing data
 * Program.
 *
 * @author: Aditya Tewari
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Structure Creation

struct Datum {
  int x;
  int y;
  struct Datum *next;
};

struct Data {
  struct Datum *start;
  int len;
};

typedef struct Data data;
typedef struct Datum datum;

datum* datumConstructor(int a, int b)
{
  datum *d = (datum*) malloc(sizeof(datum));
  d->x = a;
  d->y = b;
  d->next = NULL;
  return d;
}

void datumDestructor(datum *d)
{
  free(d);
}

data* dataConstructor()
{
  data *D = (data *) malloc(sizeof(data));
  D->start = NULL;
  D->len = 0;
  return D;
}

void dataDconstructor(data *D)
{
  datum *temp = D->start;
  while(D->start != NULL)
  {
    D->start = D->start->next;
    datumDestructor(temp);
    temp = D->start;
  }
  free(D);
}

void addDatum(int x, int y, data *D)
{
  datum *d = datumConstructor(x, y);
  d->next = D->start;
  D->start = d;
  D->len = D->len + 1;
}

datum* removeDatum(data *D)
{
  datum *temp = D->start;
  D->start = D->start->next;
  D->len = D->len - 1;
  return temp;
}


