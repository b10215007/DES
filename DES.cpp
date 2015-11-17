#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <bitset>
using namespace std;


int IP[] = {58,50,42,34,26,18,10,2,
            60,52,44,36,28,20,12,4,
			62,54,46,38,30,22,14,6,
			64,56,48,40,32,24,16,8,
			57,49,41,33,25,17,9,1,
			59,51,43,35,27,19,11,3,
			61,53,45,37,29,21,13,5,
			63,55,47,39,31,23,15,7};
			
int IP1[] = {40,8,48,16,56,24,64,32,
             39,7,47,15,55,23,63,31,
			 38,6,46,14,54,22,62,30,
			 37,5,45,13,53,21,61,29,
			 36,4,44,12,52,20,60,28,
			 35,3,43,11,51,19,59,27,
			 34,2,42,10,50,18,58,26,
			 33,1,41,9,49,17,57,25};

			
int PC_1[] = {57, 49, 41, 33, 25, 17, 9,  
               1, 58, 50, 42, 34, 26, 18,  
              10,  2, 59, 51, 43, 35, 27,  
              19, 11,  3, 60, 52, 44, 36,  
              63, 55, 47, 39, 31, 23, 15,  
               7, 62, 54, 46, 38, 30, 22,  
              14,  6, 61, 53, 45, 37, 29,  
              21, 13,  5, 28, 20, 12,  4};   
  

int PC_2[] = {14, 17, 11, 24,  1,  5,  
               3, 28, 15,  6, 21, 10,  
              23, 19, 12,  4, 26,  8,  
              16,  7, 27, 20, 13,  2,  
              41, 52, 31, 37, 47, 55,  
              30, 40, 51, 45, 33, 48,  
              44, 49, 39, 56, 34, 53,  
              46, 42, 50, 36, 29, 32};
              
int E[] = {32,  1,  2,  3,  4,  5,  
            4,  5,  6,  7,  8,  9,  
            8,  9, 10, 11, 12, 13,  
           12, 13, 14, 15, 16, 17,  
           16, 17, 18, 19, 20, 21,  
           20, 21, 22, 23, 24, 25,  
           24, 25, 26, 27, 28, 29,  
           28, 29, 30, 31, 32,  1};
		   
		   		  
int S_BOX[8][4][16] = {  
    {    
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},    
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},    
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},   
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}   
    },  
    {    
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},    
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},   
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},    
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}    
    },   
    {    
        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},    
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},    
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},    
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}    
    },   
    {    
        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},    
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},    
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},    
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}    
    },  
    {    
        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},    
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},    
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},    
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}    
    },  
    {    
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},    
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},    
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},    
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}    
    },   
    {    
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},    
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},    
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},    
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}    
    },   
    {    
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},    
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},    
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},    
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}    
    }   
};

int P[] = {16,  7, 20, 21,  
           29, 12, 28, 17,  
            1, 15, 23, 26,  
            5, 18, 31, 10,  
            2,  8, 24, 14,  
           32, 27,  3,  9,  
           19, 13, 30,  6,  
           22, 11,  4, 25 };
           
int shiftbit[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};  

vector<int> shift(vector<int> k,int s)
{
      int tmp[30],temp2[30];

      for(int i=0;i<28;i++)
        tmp[i] = k[i];
	  for(int i=0;i<28;i++)
	  {
	  	if(i+s > 27)
	  	temp2[i] = tmp[i+s-28];
	  	else
  	    temp2[i] = tmp[i+s];
	  }
	  for(int i=0;i<28;i++)
	    {
	    k[i] = temp2[i];
	   // printf("%d",k[i]);
		}
	
	return k;
}	 
vector<vector<int> > get_key(vector<int> key)
{
	//int P_key[60];
	vector<int> real_key;
	vector<int> left_key;
	vector<int> right_key;
	vector<int> subkey;
	vector<vector<int> > S_key;
	

	for(int i=0;i<56;i++)
	{
		if(i>28)
		left_key.push_back(key[PC_1[i]-1]);
		else
		right_key.push_back(key[PC_1[i]-1]);
	}
    for(int i=0;i<28;i++)
    //printf("%d",left_key[i]);
	for(int round=0; round < 16; round++)
	{
		left_key = shift(left_key,shiftbit[round]);
		right_key = shift(right_key,shiftbit[round]);
		
		for(int i=0;i<28;i++)
		   real_key.push_back(left_key[i]);
		for(int i=0;i<28;i++)   
           real_key.push_back(right_key[i]);
        for(int i=0;i<48;i++)
		   subkey.push_back(real_key[PC_2[i]-1]);
		for(int i=0;i<48;i++)   
		S_key.push_back(subkey);
		
	  	real_key.clear();
		subkey.clear();
	//	for(int i=0;i<48;i++)
		//  printf("%d",S_key[round][i]);
	//	printf("\n");  
		//system("pause");    
	}
	 
	return S_key;
}
/*char Expand(char right_text[32])
{
     

   return E_text;
}	
*/		
	
		   
vector<int> f_function(vector<int> right_text,vector<int> key,int round)
{
	       vector<int> E_text;
	       vector<vector<int> > skey;
	       vector<int> output;
	       
	       int b[36];
		   int temp,temp2,x;
		     
           for(int i = 0;i < 48;i++)
               E_text.push_back(right_text[E[i]-1]);
                   
	        skey = get_key(key);
           
		    	
		     	for(int i=0;i<48;i++)
	              E_text[i] = E_text[i] ^ skey[round][i];
		   //for(int i=0;i<48;i++)
	         //printf("%d ",E_text[i]);  	
	        x=0;
           for(int i=0;i<48;i+=6)
           {
           	    int row = E_text[i]*2 + E_text[i+5];
           	    int col = E_text[i+1]*8 + E_text[i+2]*4 + E_text[i+3]*2 + E_text[i+4];
 	            int n = S_BOX[x][row][col];
 	            
 	            temp2 = n;
 	            
 	            for(int j=3;j >= 0;j--)
 	            {
 	            	 temp = temp2 % 2;
	 	 	         temp2 = temp2 / 2;
	 	 	         if(temp2 >= 1)
					 b[j] = temp;
					 else
					 b[j] = 0;
					 
 	            }
 	            
 	           for(int i=0;i<4;i++)
 	              output.push_back(b[i]);  
 	            x++;  
           }

         vector<int> tmp = output;
	   for(int i=0;i<32;i++)
	       output[i] = tmp[P[i]-1];
           
	return output;
}		   
void encrypt(vector<int> text,vector<int> key)
{

	  vector<int> plain_IP;
	  vector<int> left_text;
	  vector<int> right_text;
	  vector<int> newright;
      vector<int> cipher;
	  vector<int> cipher_text;
      int c;
	  	  

	/*for(int i=0;i<64;i++)
	{
	      text.push_back(tp[i]);
	      key.push_back(int(k1[i]));
	}*/
	     for(int i=0;i<64;i++)
	      {
		    plain_IP.push_back(text[IP[i]-1]);
		    //printf("%d  ",plain_IP[i]);
	      }
         for(int i=0;i<32;i++)
	     {
	  	   left_text.push_back(plain_IP[i]);
	  	   right_text.push_back(plain_IP[i+32]);
	  	
	     }
	       	//for(int i=0;i<32;i++)
			  // printf("%d ",right_text[i]);
		 // newright = f_function(right_text,key,0);	   
          for(int round=0; round < 16; round++)
          {

			  newright = f_function(right_text,key,round);
          	     for(int j=0;j<32;j++)
			       {
			  	      newright[j] = newright[j] ^ left_text[j];
		            }
          	   left_text = right_text;
       	       right_text = newright;
          	  // for(int i=0;i<32;i++)
          	  // printf("%d ",i);
          }
          for(int i=0;i<64;i++)
          {
          	  if(i<32)
			  cipher.push_back(left_text[i]);
          	  else
 	          cipher.push_back(right_text[i-32]);
          } 
          for(int i=0;i<64;i++)
          {
          	cipher_text.push_back(cipher[IP1[i]-1]);
          	printf("%d",cipher_text[i]);
          }
          /*for(int i=0;i<64;i+=8)
          {
          	c = cipher_text[i]*128 + cipher_text[i+1]*64 + cipher_text[i+2]*32 +cipher_text[i+3]*16 +cipher_text[i+4]*8 +cipher_text[i+5]*4 +cipher_text[i+6]*2 + cipher_text[i+7];
          	printf("%c",(char)c);
          }*/
}
void decrypt(vector<int> text,vector<int> key)
{
	vector<int> plaintext;
	vector<int> F_permutation;
	vector<int> I_permutation;
	vector<int> left;
	vector<int> right;
	vector<int> last_left;
	int p;	
	
	for(int j=0;j<64;j++)
	{
	
	       for(int i=0;i<64;i++)
	         {
			      if(j == IP1[i]-1)
			       F_permutation.push_back(text[i]);
	         } 
	  
	}  
    for(int i=0;i<32;i++)
    {
    	left.push_back(F_permutation[i]);
    	right.push_back(F_permutation[i+32]);
    }
	for(int round=15;round >= 0;round--)
	{
	  
	  last_left = f_function(left,key,round);
	  for(int i=0;i<32;i++)
	    last_left[i] = last_left[i] ^ right[i];
	  right = left;
	  left = last_left;
	}
	//printf("%d",right)
	for(int i=0;i<64;i++)
	{
		if(i<32)
		I_permutation.push_back(left[i]);
		else
		I_permutation.push_back(right[i-32]);
	}
  	for(int j=0;j<64;j++)
  	{
		 for(int i=0;i<64;i++)
	     {
	       if(j == IP[i]-1)
		   plaintext.push_back(I_permutation[i]);
	     }
	}
	/*for(int i=0;i<64;i+=8)
          {
          	p = plaintext[i]*128 + plaintext[i+1]*64 + plaintext[i+2]*32 +plaintext[i+3]*16 +plaintext[i+4]*8 +plaintext[i+5]*4 +plaintext[i+6]*2 + plaintext[i+7];
          	printf("%c",(char)p);
          }*/
	for(int i=0;i<64;i++)
      printf("%d",plaintext[i]);
	
}		      
int main()
{
	  char plain_text[10] = "romantic";  //內文為8個8bits 的文字
	  char cipher_text[10] = "ewfwfwg";
	  int xx[70] = {1,0,0,0,1,0,0,1,0,1,0,0,1,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,0,0,1,0,1,1,0,1,1,1,1,1,1,0,0,1,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,1};
	  int yy[70] = {0,1,1,0,1,1,0,0,0,1,1,0,0,1,0,1,0,1,1,0,0,0,0,1,0,1,1,1,0,0,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,1,1,0,0,1,1,0,0,1,1,1};
	  int tp[70],tp2[70];
	  vector<int> text;// 64 bit內文 
	  vector<int> plain_IP;
	  vector<int> left_text;
	  vector<int> right_text;
      vector<int> key;
	  int k1[100] = {1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1};
	  int k2[100] = {0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,0,0,1,1,0,0,1,0,1,0,1,1,1,0,0,1,0};
	  int temp=0,temp2;
	  int k=0,l=0,m=0,n;
	  
	  
	  
	for(int i=0;i<strlen(plain_text);i++)
	{  temp2 = int(plain_text[i]);
		for(int j=0;j<8;j++)
		  {
		    temp = temp2 % 2;
	 	 	temp2 = temp2 / 2;
		  	tp[7+l-k] = temp;
		  	//printf("%d",text[j]);
		    k++;    
		  }
		k=0;
		l=l+8;
		printf("%d",l);
	}
	printf("\n");
	k=0;
	l=0;
	for(int i=0;i<strlen(cipher_text);i++)
	{  temp2 = int(cipher_text[i]);
		for(int j=0;j<8;j++)
		  {
		    temp = temp2 % 2;
	 	 	temp2 = temp2 / 2;
		  	tp2[7+l-k] = temp;
		  	//printf("%d",text[j]);
		    k++;
		  }
		k=0;
		l=l+8;
	}
	for(int i=0;i<64;i++)
	{
	      text.push_back(yy[i]);
	      key.push_back(k2[i]);
	 //     printf("%d",key[i]);
	}
	 encrypt(text,key);
	 printf("\n");
	 for(int i=0;i<64;i++)
	{
	      text.push_back(xx[i]);
	      key.push_back(k2[i]);
	      //printf("%d %d\n",text[i],i);
	}  
    decrypt(text,key);
    printf("\n");
	

	
	
	
	system("pause");
	return 0;
} 		
