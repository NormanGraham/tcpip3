// unsigned char buffer, and length. 
#ifndef ubuff_defined_
#define ubuff_defined_
// there is a class std::string.   
// which just will not work, for us.   
// we want an insert point, lengths of short max, and write things in, as bytes.   
#include <string.h> 

class ubuff { 
     unsigned short maxsize = 0; 
     unsigned short ip = 0; 
     unsigned char *pbuffer = NULL;
     long     memOverrun = 0; 
     public: 
           ubuff( ); 
           ~ubuff();
           void GetCurrent( unsigned char **pCurrent, unsigned short *iLeft) {
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
           }
           void append( unsigned char *ptr, unsigned short ilen ) { 
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
           
}; 

#endif
