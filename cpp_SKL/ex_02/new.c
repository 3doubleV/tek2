/*
** new.c for new in /home/guillaume2.roux/rendu/my_SKL/ex_01
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
**
** Started on  Sat Jan  7 09:54:00 2017 Guillaume Roux
** Last update Sat Jan  7 21:00:58 2017 Meï
*/

#include <stdlib.h>
#include <string.h>
#include "new.h"
#include "object.h"
#include "point.h"
#include "raise.h"

Object* new(Class *class, ...)
{
  Class 	*tmp;
  va_list	ap;

  va_start(ap, class);
  tmp = va_new(class, &ap);
  va_end(ap);
  return (tmp);
}

Object* va_new(Class* class, va_list* ap)
{
  Class 	*tmp;

  if ((tmp = malloc(class->__size__)) == NULL)
    raise("Out of memory");
  memcpy(tmp, class, class->__size__);
  tmp->__init__(tmp, ap);
  return (tmp);
}

void delete(Object* ptr)
{
  Class 	*tmp;

  if (ptr == NULL)
    raise("Don't erase a null Object, you moron !");
  tmp = (Class *)ptr;
  if (tmp->__del__)
    tmp->__del__(tmp);
  free(tmp);
  tmp = NULL;
}
