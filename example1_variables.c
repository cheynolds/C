#include <stdio.h>



int main()
{
    //DECLARATIONS
  
    //integer
    int a = 10;
    int b;
  
    //float
    float c = 10.0f;
  
    //double
    double d = 10.0f;
  
    //char
    char e = 'A';
  
    //character string (cstring)
    char* f = "Brief intro, deeper dives coming later";
  
    //OUTPUT
  
    //integer
    printf("a is %d\n", a);
    
    //integer-no value
    printf("b is %d\n", b);
  
    //float
    printf("c is %f\n", c);
  
    //double
    printf("d is %lf\n", d);
  
    //char 
    printf("e is '%c'\n", e);
  
    //char asci value
    printf("e is '%d'\n", e);
   
    //char*
    printf("f is %s\n", f);
     return 0;
}
