/* $Id: dspif.c,v 1.4 2001/12/24 01:09:01 sybalsky Exp $ (C) Copyright Venue, All Rights Reserved  */
static char *id = "$Id: dspif.c,v 1.4 2001/12/24 01:09:01 sybalsky Exp $ Copyright (C) Venue";
/* This is the display interface  */


/************************************************************************/
/*									*/
/*	(C) Copyright 1989, 1990, 1990, 1991, 1992, 1993, 1994,         */
/*                    1995, 1999 Venue.                                 */
/*	    All Rights Reserved.		                        */
/*	Manufactured in the United States of America.			*/
/*									*/
/*	The contents of this file are proprietary information 		*/
/*	belonging to Venue, and are provided to you under license.	*/
/*	They may not be further distributed or disclosed to third	*/
/*	parties without the specific permission of Venue.		*/
/*									*/
/************************************************************************/


#include "version.h"



#include <stdio.h>
#include "lispemul.h"
#include "dbprint.h"
#include "devif.h"

DspInterfaceRec _curdsp, _coldsp;

DspInterface currentdsp = &_curdsp;
DspInterface colordsp = &_coldsp;

#ifdef XWINDOW
extern int LispDisplayRequestedWidth;
extern int LispDisplayRequestedHeight;

extern DspInterface X_init( DspInterface dsp, 
		     char *lispbitmap, 
		     int width_hint, 
		     int height_hint, 
		     int depth_hint );
#endif /* XWINDOW */

#ifdef DOS
extern int dosdisplaymode;
#endif /* DOS */

make_dsp_instance(DspInterface dsp, char *lispbitmap, int width_hint, int height_hint, int depth_hint)
{
#ifdef DOS

  TPRINT(("Enter make_dsp_instance, dosdisplaymode is: %d\n", dosdisplaymode));

  if (depth_hint == 0) depth_hint = 1;

  switch(dosdisplaymode) {
  case 1:
    VGA_init( dsp ,0, 0, 0, depth_hint );
    break;
  case 0x102:
  case 0x104:
    VESA_init( dsp ,0, 0, 0, depth_hint );
    break;
  default:
    if (VESA_p()) {
      VESA_init( dsp ,0, 0, 0, depth_hint );
    } else if (VGA_p()){    
      VGA_init( dsp ,0, 0, 0, depth_hint );
    } else {			/* Can't set *ANY* video mode! */
      (void)fprintf(stderr, "No portable graphics mode supported by this host.\n");
      (void)fprintf(stderr, "\n-Expected VESA or VGA.\n");
      exit(1);
    }
    break;
  }

#elif XWINDOW
  /* lispbitmap is 0 when we call X_init the first time. */
  if ( X_init( dsp, 0, LispDisplayRequestedWidth, 
	       LispDisplayRequestedHeight, depth_hint ) == NULL) {
    fprintf(stderr, "Can't open display.");
    exit(-1);
  }
#endif	/* DOS | XWINDOW */
}	/* Now we know the Maxi-MooM capabillities of the hardware. */

#ifdef DOS
VESA_p()
{
  /* Magic. Do a vesa call to determine the current mode. */
  return(VESA_call( 3 , 0 ));
}

VGA_p()
{
  return( TRUE );
}
#endif /* DOS */

/*********************************************************************/
/*                                                                   */
/*		     G e n e r i c R e t u r n T                     */
/*                                                                   */
/* Utility function that just returns T                              */
/*                                                                   */
/*********************************************************************/
unsigned long
GenericReturnT(void)
{
  return(T);
}

void GenericPanic(DspInterface dsp)
{
  TPRINT(("Enter GenericPanic\n"));
  fprintf( stderr, "Panic! Call to uninitialized display slot!" );
  exit(0);
}


SwitchDisplay(LispPTR display)
{
  DspInterface tmp;		/* Switch-a-roo! */

  TPRINT(("Enter SwitchDisplay\n"));
  tmp = currentdsp;
  currentdsp = colordsp;
  colordsp = tmp;
  TPRINT(("Exit SwitchDisplay\n"));
  return( display );
}

void describedsp(DspInterface dsp)
{
  if ( dsp == 0 ){
    printf("describedsp: Not a dsp!\n");
    return;
  }
  if ( dsp == &_curdsp )
    printf("dsp is B/W display\n");
  else
    printf("dsp is COLOR display\n");

  printf("\n");
  printf("width= %d\n", dsp->Display.width);
  printf("height= %d\n", dsp->Display.height);
  printf("bitsperpixel= %d\n", dsp->bitsperpixel);
  printf("colors= %d\n", dsp->colors);
  printf("graphicsmode= %d\n", dsp->graphicsmode);
  printf("numberofbanks= %d\n", dsp->numberofbanks);
#ifdef DOS
  printf("BytesPerLine= %d\n", dsp->BytesPerLine);
  printf("DisplayStartAddr= %d\n", dsp->DisplayStartAddr);
#endif /* DOS */
  printf("bitblt_to_screen= %d\n", dsp->bitblt_to_screen);
  printf("cleardisplay= %d\n", dsp->cleardisplay);
#ifdef DOS
  printf("mouse_vissible= %d\n", dsp->mouse_vissible);
  printf("mouse_invissible= %d\n", dsp->mouse_invissible);
  printf("\n");
#endif /* DOS */
  fflush(stdout);
}