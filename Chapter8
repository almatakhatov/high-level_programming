#include "std_lib_facilities.h" 
         
void swap_v(int a, int b)  
{      
 int temp; 
 temp = a; 
 a = b;     
 b = temp;      
} 
   
void swap_r(int& a, int& b)         
{      
 int temp;     
 temp = a;        
 a = b;       
 b = temp;      
} 

void swap_cr(const int& a, const int& b)       
{    
 int temp;           
 temp = a;       
 a = b;     
 b = temp; 
} 
        
int main() 
{     
  int x = 7;        
  int y = 9; 
        
  swap_r(x,y); //replace ? by v, r, or cr     
  cout << 1 << x << ' '<< y << endl; //works, arguments are variables 
  
  swap_v(7,9); //will not work because arguments are integers, not variables        
  cout <<2 << x << ' '<< y << endl; //prints out result of first function
         
  const int cx = 7; 
  const int cy = 9; 
 
  swap_v(cx,cy);        
  cout << 3 <<cx << ' ' << cy << endl; //will not work (const) 
       
  /*swap_v(7.7,9.9);       
  cout << swap_v(7.7,9.9); //will work but only int part */ 
      
  double dx = 7.7; 
  double dy = 9.9;        
  swap_v(dx,dy);    //arguments must be integer
  cout << 4 <<dx << dy << endl; ////prints out original values
       
  swap_v(7.7,9.9); //will not work because arguments are doubled 
  cout << 5 <<dx << ' ' << dy << endl;   //it will print out original values       
  return 0; 
     
}
