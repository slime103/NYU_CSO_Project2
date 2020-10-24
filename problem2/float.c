#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"


int is_special ( float f ) {
    //Denormal Value
    unsigned* n = &f;
    //Is the exponent empty but there's something in the Mantissa?
    if (!(*n & (0b11111111 << 23)) && ((*n & ~(0b111111111 << 23))) )
        return 1;
    //Is the exponent full? inf or nan
    else if (((*n & (0b11111111 << 23)) == (unsigned)(0b11111111 << 23)))
        return 1;
    else
        return 0;
}

//we want the last 23 bits
float get_M  ( float f ) {

    unsigned* n = &f;
    //exp is full?
    if (get_E(f) == 255)
    {
        //mantissa is non empty?
        //if it empty then inf, if non empty then nan
        if (!(*n & ~(0b111111111 << 23)))
            return 0.0f; //inf value
        else
            return 0.5f; //nan value
    }
    *n = ( (*n & ~(0b11111111 << 23)) | (0b1111111 << 23) );
    return f;
}

//we only want the first bit
int get_s ( float f ) {
    if (*(unsigned*)&f & (0b1<<31))
	    return -1;
	else
	    return 1;
}


//We only want the first 9 bits
//Exponent is stored with bias of +127
int get_E ( float f ) {
    unsigned* n = &f;
    if (!(*n & (0b11111111 << 23)))
        return -126;
    else if (((*n & (0b11111111 << 23)) == (unsigned)(0b11111111 << 23)))
        return 255;
    else
        return (( (*n & (0b11111111 << 23) )) >> 23) - 127;
}



















