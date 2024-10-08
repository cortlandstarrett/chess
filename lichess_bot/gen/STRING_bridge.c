/*----------------------------------------------------------------------------
 * Description:   Methods for bridging to an external entity.
 *
 * External Entity:  string (STRING)
 * 
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include "lichess_bot_sys_types.h"
#include "LOG_bridge.h"
#include "STRING_bridge.h"

/*
 * Bridge:  atoi
 */
i_t
STRING_atoi( c_t p_s[ESCHER_SYS_MAX_STRING_LEN] )
{
  i_t xtumlOALrv = 0;
  if ( *p_s == 'R' ) {
    xtumlOALrv = atoi(p_s + 1);
  } else {
    xtumlOALrv = atoi(p_s);
  }
  return xtumlOALrv;
}


/*
 * Bridge:  escapetics
 */
c_t *
STRING_escapetics( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], c_t p_s[ESCHER_SYS_MAX_STRING_LEN] )
{
  A0xtumlsret[ 0 ] = 0;

  c_t * p = p_s;
  c_t * q = A0xtumlsret;

  while ( p != 0 && *p != '\0' && (q - A0xtumlsret) < ESCHER_SYS_MAX_STRING_LEN ) {
      if ( *p == '\'' ) {
          *q = *p;      // copy the character
          q++;
          *q = '\'';    // add an extra tic to escape it
      }
      else {
          *q = *p;      // copy the character
      }
      q++;
      p++;
  }
  *q = '\0';            // null terminate

  return A0xtumlsret;
}


/*
 * Bridge:  getword
 */
c_t *
STRING_getword( const i_t p_i, const i_t p_j, c_t * p_s )
{
  i_t len = Escher_strlen( p_s );
  c_t * result = Escher_malloc( len + 1 );
  result[ 0 ] = 0;

  i_t lim = p_j;
  // if j is -1, it just means the full length of the string
  if ( -1 == lim ) lim = len;

  // check arguments
  if ( !(p_i < 0 || p_i > len - 1) && !(lim < 0 || lim > len) ) {

    c_t * w_begin;
    c_t * w_end;

    // find the first non comma, whitespace, or close parenthesis
    w_begin = p_s + p_i;
    while ( w_begin - p_s < len ) {
      if ( *w_begin != ',' &&
           *w_begin != ' ' &&
           *w_begin != '\n' &&
           *w_begin != '\r' &&
           *w_begin != '\t' &&
           *w_begin != '(' &&
           *w_begin != ')' ) break;
      w_begin++;
    }

    // find the first comma, whitespace, or close parenthesis after starting the word
    w_end = w_begin;
    while ( w_end - p_s < len ) {
      if ( *w_end == ',' ||
           *w_end == ' ' ||
           *w_end == '\n' ||
           *w_end == '\r' ||
           *w_end == '\t' ||
           *w_end == '(' ||
           *w_end == ')' ) break;
      w_end++;
    }

    if ( (w_begin - p_s) < lim && (w_end - p_s) <= lim ) {
      // copy the substring into the result
      //Escher_strcpy( result, STRING_substr( (const i_t)(w_begin - p_s), (const i_t)(w_end - p_s), p_s ) );
      c_t space[ESCHER_SYS_MAX_STRING_LEN];
      c_t * sub = STRING_substr( space, (const i_t)(w_begin - p_s), (const i_t)(w_end - p_s), p_s );

      // Escher_strcpy
      c_t * dst = result;
      c_t * src = sub;
      if ( 0 != src ) {
        Escher_size_t i = Escher_strlen( src ) + 1;
        while ( ( i > 0 ) && ( *src != '\0' ) ) {
          --i;
          *dst++ = *src++;
        }
        *dst = '\0';  /* Ensure delimiter.  */
      }
    }
    
  }

  return result;
}


/*
 * Bridge:  indexof
 */
i_t
STRING_indexof( c_t p_haystack[ESCHER_SYS_MAX_STRING_LEN], c_t p_needle[ESCHER_SYS_MAX_STRING_LEN] )
{
  c_t * a;
  c_t * b;
  c_t * c;

  // check arguments
  if ( !p_needle || !p_haystack ) return -1;

  a = p_haystack;
  b = p_needle;
  if (*b == '\0') {
    return 0;   // if needle is empty string, by definition, the index is 0
  }

  // search through to find first character match
  for ( ; *a != 0; a += 1) {
    if (*a == *b) {

      // check the rest of the string
      c = a;
      while ( *c++ == *b++ ) {
        if ( *b == '\0' ) {
          return a - p_haystack;
        }
        if ( *c == '\0' ) {
          break;
        }
      }

    }

    // reset b
    b = p_needle;
  }

  // no match found
  return -1;
}


/*
 * Bridge:  itoa
 */
c_t *
STRING_itoa( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], const i_t p_i )
{
  /* Replace/Insert the following instructions with your implementation code.  */
  c_t mapping[10][ESCHER_SYS_MAX_STRING_LEN];i_t i;c_t s[ESCHER_SYS_MAX_STRING_LEN];
  /* ASSIGN mapping[9] = 9 */
  Escher_strcpy( mapping[9], "9" );
  /* ASSIGN mapping[8] = 8 */
  Escher_strcpy( mapping[8], "8" );
  /* ASSIGN mapping[7] = 7 */
  Escher_strcpy( mapping[7], "7" );
  /* ASSIGN mapping[6] = 6 */
  Escher_strcpy( mapping[6], "6" );
  /* ASSIGN mapping[5] = 5 */
  Escher_strcpy( mapping[5], "5" );
  /* ASSIGN mapping[4] = 4 */
  Escher_strcpy( mapping[4], "4" );
  /* ASSIGN mapping[3] = 3 */
  Escher_strcpy( mapping[3], "3" );
  /* ASSIGN mapping[2] = 2 */
  Escher_strcpy( mapping[2], "2" );
  /* ASSIGN mapping[1] = 1 */
  Escher_strcpy( mapping[1], "1" );
  /* ASSIGN mapping[0] = 0 */
  Escher_strcpy( mapping[0], "0" );
  /* ASSIGN i = PARAM.i */
  i = p_i;
  /* ASSIGN s =  */
  Escher_strcpy( s, "" );
  /* WHILE ( i >= 1 ) */
  while ( i >= 1 ) {
    i_t d;
    /* ASSIGN d = ( i % 10 ) */
    d = ( i % 10 );
    /* ASSIGN i = ( i / 10 ) */
    i = ( i / 10 );
    /* ASSIGN s = ( mapping[d] + s ) */
    Escher_strcpy( s, ( Escher_stradd( mapping[d], s ) ) );
  }
  /* RETURN s */
  {c_t * xtumlOALrv = s;
  return Escher_strcpy( A0xtumlsret, xtumlOALrv );}
}


/*
 * Bridge:  quote
 * implemented as macro
 */


/*
 * Bridge:  replace
 */
c_t *
STRING_replace( c_t * p_original, c_t * p_replace, c_t * p_with )
{
// You must free the result if result is non-NULL.
    char *orig = p_original;
    char *rep = p_replace;
    char *with = p_with;
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = Escher_strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = Escher_strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; (tmp = strstr(ins, rep)); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

/*
 * Bridge:  split
 */
c_t *
STRING_split( c_t * p_delimiter, c_t * p_string)
{
	char *result;
	if(0 == strcmp( p_string, "")) {
		result = strtok(NULL, p_delimiter);
	} else {
		result = strtok(p_string, p_delimiter);
	}
	if(result == NULL) {
		return "";
	} else {
		return result;
	}
}


/*
 * Bridge:  strlen
 */
i_t
STRING_strlen( c_t p_s[ESCHER_SYS_MAX_STRING_LEN] )
{
  i_t result = 0;
  result = (i_t)Escher_strlen( p_s );
  return result;
}


/*
 * Bridge:  substr
 */
c_t *
STRING_substr( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], const i_t p_begin, const i_t p_end, c_t p_s[ESCHER_SYS_MAX_STRING_LEN] )
{

  // get length of s
  i_t len = (i_t)Escher_strlen( p_s );
  c_t * result = Escher_malloc( len + 1 );
  result[ 0 ] = 0;

  // check that the indexes are in a valid range
  i_t begin = p_begin;
  i_t end = p_end;
  if ( begin > len - 1 ) {
    return result;
  }
  if ( begin < 0 ) {
    begin = 0;
  }
  if ( end < 0 || end > len ) {
    end = len;
  }
  if ( end <= begin ) {
    return result;
  }

  // if we have a string and the end is greater than begin
  if ( !(len == 0 || end <= begin) ) {

    // copy in the new string
    c_t * p = p_s + begin;
    c_t * r = result;
    while ( p < p_s + end ) {
      *r++ = *p++;
    }
    *r = '\0';  // null terminate

  }

  return result;
}


/*
 * Bridge:  trim
 */
c_t *
STRING_trim( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], c_t p_s[ESCHER_SYS_MAX_STRING_LEN] )
{
  i_t len = Escher_strlen( p_s );
  c_t * result = Escher_malloc( len + 1 );
  A0xtumlsret[ 0 ] = 0;

  c_t * a;
  c_t * b;

  // find the first non whitespace character
  a = p_s;
  for ( ; *a != '\0'; a++ ) {
    if ( *a != ' ' && *a != '\r' && *a != '\t' && *a != '\n' ) break;   // found non whitespace
  }

  // find last non whitespace character
  b = p_s + ( len - 1 );
  for ( ; b != p_s; b-- ) {
    if ( *b != ' ' && *b != '\r' && *b != '\t' && *b != '\n' ) break;   // found non whitespace
  }

  // check if they crossed ( all whitespace )
  if ( b < a ) {
    return A0xtumlsret;
  } else {
    A0xtumlsret = STRING_substr( A0xtumlsret, (const i_t)(a - p_s), (const i_t)(b - p_s)+1, p_s );
  }
  return A0xtumlsret;
}


/*
 * Bridge:  unescapetics
 */
c_t *
STRING_unescapetics( c_t A0xtumlsret[ESCHER_SYS_MAX_STRING_LEN], c_t p_s[ESCHER_SYS_MAX_STRING_LEN] )
{
  c_t * result = 0;
  /* Insert your implementation code here... */
  return result;
}

