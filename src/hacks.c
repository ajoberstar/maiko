/* $Id: hacks.c,v 1.3 1999/05/31 23:35:33 sybalsky Exp $ (C) Copyright Venue, All Rights Reserved  */
static char *id = "$Id: hacks.c,v 1.3 1999/05/31 23:35:33 sybalsky Exp $ Copyright (C) Venue";




/************************************************************************/
/*									*/
/*	(C) Copyright 1989-95 Venue. All Rights Reserved.		*/
/*	Manufactured in the United States of America.			*/
/*									*/
/*	The contents of this file are proprietary information 		*/
/*	belonging to Venue, and are provided to you under license.	*/
/*	They may not be further distributed or disclosed to third	*/
/*	parties without the specific permission of Venue.		*/
/*									*/
/************************************************************************/

#include "version.h"


/* These functions are created so that you can split a float into */
/* four integers. The general idea behind these functions is to */
 /* act as a caster between different entitys on the stack */

int pickapart1(int i1, int i2, int i3, int i4)
{
  return(i1);
}

int pickapart2(int i1, int i2, int i3, int i4)
{
  return(i2);
}

int pickapart3(int i1, int i2, int i3, int i4)
{
  return(i3);
}

int pickapart4(int i1, int i2, int i3, int i4)
{
  return(i4);
}