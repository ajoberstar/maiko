/* $Id: asmbbt.c,v 1.3 1999/05/31 23:35:23 sybalsky Exp $ (C) Copyright Venue, All Rights Reserved  */
static char *id = "$Id: asmbbt.c,v 1.3 1999/05/31 23:35:23 sybalsky Exp $ Copyright (C) Venue";

/************************************************************************/
/*									*/
/*			File:	asmbbt.c				*/
/*									*/
/*	Dummy C-function "bitblt", used to compile the bitblt code	*/
/*	for hand-optimization.						*/
/*									*/
/*									*/
/*									*/
/*									*/
/************************************************************************/





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




#include "lispemul.h"
#include "lspglob.h"
#include "lispmap.h"
#include "lsptypes.h"
#include "emlglob.h"
#include "adr68k.h"
#include "address.h"
#include "arith.h"
#include "stack.h"
#include "cell.h"
#include "gc.h"


#include "bb.h"
#include "bitblt.h"
#include "pilotbbt.h"


void	bitblt(DLword *srcbase, DLword dstbase, int sx, int dx, int w, int h, int srcbpl, int dstbpl, int backwardflg, int src_comp, int op, int gray, int num_gray, int curr_gray_line)
{ 
	new_bitblt_code;
  }
