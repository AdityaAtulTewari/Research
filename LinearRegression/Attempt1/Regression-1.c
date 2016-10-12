/*******************************************************************************
 * Regression-1.c
 *
 * Regression Draft 1
 *
 * This is the actual Regression algorithm
 *
 * @author: Aditya Atul Tewari
 ******************************************************************************/

#include "Data.c"
#include <errno.h>
#include <math.h>

double* Regression(data *D)
{
  if(D == NULL) perror("No Data");
  double *ans = (double *) calloc(2, sizeof(double));
  double ave_x = 0;
  double ave_y = 0;
  datum *temp = D->start;

  while(temp != NULL)
  {
    ave_x += temp->x;
    ave_y += temp->y;
    temp = temp->next;
  }
  
  ave_x = ave_x / D->len;
  ave_y = ave_y / D->len;
  
  double numer = 0;
  double denom = 0;
  temp = D->start;
  while(temp != NULL)
  {
    numer += (temp->x - ave_x) * (temp->y - ave_y);
    denom += pow((temp->x - ave_x), 2);
    temp = temp->next;
  }
  
  ans[1] = numer/ denom;
  
  ans[0] = D->start->y - ans[1] * D->start->x;

  return ans;
}
