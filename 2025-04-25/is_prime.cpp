#include "is_prime.h"
bool is_prime(long n){
    if(n<=1){ return false; }
    for(long ii=2;(ii*ii)<=n;ii++){
       if( n%ii==0 ){
           return false;
           } 
       }
       return true;
   }
   