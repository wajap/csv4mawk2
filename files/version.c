
/********************************************
version.c
copyright 1991-95,2014-2016  Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 3, 2007.

If you import elements of this code into another product,
you agree to not name that product mawk.
********************************************/


#include "mawk.h"

/* mawk 1.9 */
static const char* PATCH_STRING = ".9.6" ;
static const char* DATE_STRING  = "21 Aug 2016" ;
/* csv */
static const char* DATE_STRING_CSV  = "19 FEB 2026" ;

static
const char* const version_string =
  "mawk 1.9%s, %s, Copyright Michael D. Brennan\n(%s, csv processing by Wilbert van der Poel)\n" ;

static  const char*const fmt = "%-14s%10lu\n";
/* print VERSION and exit */
void
print_version(void)
{

   printf(version_string, PATCH_STRING, DATE_STRING, DATE_STRING_CSV) ;

#if defined(MAWK_CSV_SKIPSPACES) || defined(MAWK_CSV_X) || defined(MAWK_CSV_X_SKIPISPACES)
#if defined(MAWK_CSV_X) || defined(MAWK_CSV_X_SKIPISPACES)
   printf("X-Mode ");
#if defined(MAWK_CSV_X_SKIPISPACES)
   printf("skip initial spaces");
#endif
#else
   printf("skip leading and trailing spaces before/after \"");
#endif
   printf("\n");
#endif

#ifdef MAWK_CSV_RFC4180
   printf("RFC4180 mode");
#ifdef MAWK_CSV_SKIPSPACES
   printf(". Skip leading and trailing spaces before/after \"");
#endif
   printf("\n");
#endif

   printf("\n");
   exit(0) ;
}


