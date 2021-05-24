// unsigned char buffer, and length. 
#ifndef ubuff_defined_
#define ubuff_defined_
// there is a class std::string.   
// which just will not work, for us, because the code would be unreadable if we used it.   
// instead, just write the dumb "string" class, for our unsigned chars. 

#include <string.h> 

class ubuff {
     unsigned short maxsize = 0; 
     public: 
     unsigned short ip = 0; 
     unsigned char *pbuffer = NULL;
     long     memOverrun = 0; 
     public: 
           ubuff( ); 
           ~ubuff();
           void allocate( unsigned short n); 
           void GetCurrent( unsigned char **pCurrent, unsigned short *iLeft) const {
             if ( pbuffer == NULL ) {
                   *pCurrent = NULL; 
                   *iLeft = 0; 
             }
             else if ( ip == maxsize ) {
                  *pCurrent = pbuffer + ip;
                  *iLeft = 0; 
             }
             else {
               *pCurrent = pbuffer +ip; 
               *iLeft = maxsize - ip; 
             }
           }; 
 
           void append( const unsigned char *ptr, unsigned short ilen ) { 
             if ( pbuffer ) {
                if ( (ip + ilen) < maxsize ) {
                        memcpy(pbuffer+ ip, ptr, ilen); 
                        ip+= ilen; 
                     }
                else { 
                  for (; (ilen) && (ip < maxsize) ; ip++, ptr++, ilen--) 
                     pbuffer[ip] = *ptr;
                  memOverrun += ilen; 
                }
             }
           }; 
      
           void append( const ubuff &ub ) { 
               append( ub.pbuffer, ub.ip ); 
           }; 

           int cmp( const unsigned char *ptr, unsigned short n ) { 
               if ( n > ip ) 
                   return memcmp(pbuffer, ptr, ip); 
               else 
                   return memcmp(pbuffer, ptr, n ); 
           };  
           
}; 

#endif
