// ubuff.cpp 
//
#include <iostream>
#include <string.h>
#include <string>
#include <new>

#include "ubuff.h"

ubuff::ubuff() { 
}

ubuff::~ubuff() { 
   if ( pbuffer ) 
         delete [] pbuffer; 
} 

void ubuff::allocate( unsigned short n) { 
     maxsize = n; 
     ip = 0; 
     if ( pbuffer ) 
         delete [] pbuffer; 
     pbuffer = new unsigned char [n]; 
     memset(pbuffer, 0, n ); 
     memOverrun = 0; 
}

 
