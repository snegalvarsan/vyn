#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <filesystem>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>      

namespace vyn{

using namespace std;

typedef uint32_t ui32;
typedef uint16_t ui16;
typedef uint64_t ui64;
typedef uint8_t ui8;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;
typedef int64_t i64;

/*//C++23 stuff
typedef float16_t f16;
typedef float32_t f32;
typedef float64_t f64;
typedef float128_t f128;
*/

using c16 = char16_t;
using c32 = char32_t;

#define print std::cout<<
#define line <<std::endl
#define printline std::cout<<std::endl
#define print_line printline
#define input std::cin>>
#define tab <<"\t"<<
#define done return 0
#define space <<" "<<
#define comma <<","<<
#define rev_string(total) reversestring(total)
#define reverse_string(total) rev_string(total)

#define int_to_string(k) inttostring(k)
#define float_to_int(k) floattoint(k)
#define string_to_char_array(k) convert_string_to_char(k)
#define print_string_to_char_array(k) print_string_to_charrr(k)


#define mul(x,y) multiply(x,y)
#define div(x,y) divide(x,y)
#define sub(x,y) subtract(x,y)
#define add(x,y) add_(x,y)
#define square(x) (x*x)
#define cube(x) (x*x*x)

#define ret return

#define forloop(i,x) for(int i = 0;i<x;i++) //default for loop
#define for_loop(i,x) forloop(i,x)

#define loopcomma <<","
#define loopspace <<" "

#define loop_space loopspace
#define loop_comma loopcomma

#define toss sendtossnumbers()
#define printmultitoss(x) tossprog(x)
#define print_multi_toss(x) printmultitoss(x)

#define oscheck oscheck_()
#define os_check oscheck

#define string_input(x) getline(cin,x)
#define sinput(x) string_input(x)

#define palindrome(x) palindrome_(x)
#define string_to_int(x) stoi(x)

#define upper(x) convert_string_to_uppercase(x)
#define lower(x) convert_string_to_lowercase(x)

#define random_number(limit) random_number_(limit)
#define rand_no(limit) random_number(limit)

#define del delete

#define system_write(x) system_write_(x)
#define get_system_write(x) get_system_write_(x)

#define char_to_ascii(x)   (int)x
#define ascii_to_char(x)   char(x)


//#define char_array_to_string(k) char_array_to_stringg(k)
//#define system_write(x) system__write(x)

template<typename M>
M multiply(M a,M b){
   ret a*b;
}

template<typename D>
D divide(D a,D b){
   ret a/b;
}

template<typename S>
S subtract(S a,S b){
   ret a-b;
}

template<typename A>
A add_(A a,A b){
   ret a+b;
}

string reversestring(string total){

   reverse(total.begin(),total.end());
   return total;
}

string inttostring(int k){
   stringstream ss;  
   ss<<k;  
   string s;  
   ss>>s;  
   return s;
}

int floattoint(float k){
   int a = (int)k;
   return a;
}

void tossprog(int times){
   srand( (unsigned)time( NULL ) );
   for(int i=0;i<times;i++){
   if(rand()%2==0){
   print true line;
   }
   else{
      print false line;
      }
   }

}

bool sendtossnumbers(){
   srand( (unsigned)time( NULL ) );
  if(rand()%2==0){
   ret true;
   }
   else{
      ret false;
      }
}

class file{
   public:

   string read(string filename){
   
   ifstream infile; 
   string data="";
   infile.open(filename);
    char d;
    while(infile.get(d)){
        data = data + d; 
    }
   infile.close();
   return data;
  
   
}

void write(string filename,string content){
   ofstream outfile;
   outfile.open(filename);
   string w = content;
   outfile << w << endl;
}



bool exists(string filename){
   ifstream f;
   f.open(filename);
   if(f){
      ret true;
   }
   else
      ret false;
}



};


string oscheck_(){
   #if __linux__
      ret "Linux";
   #elif _WIN32
      ret "Windows_32";
   #elif _WIN64
      ret "Windows_64";
   #else
      ret "other";
   #endif
}

char * convert_string_to_char(string a) {
    a = a.c_str();
    static char r[10000000];
   for (int i = 0; i < a.length(); ++i) {
      r[i] = a[i];
   }

   return r;
}



void print_string_to_charrr(string value)
{

   char *p;
    p = string_to_char_array(value);
    forloop(i,value.length()) {
      print *(p + i)<<"";
   }
   p=NULL;
}


string jsonwrite(string question,string val){
    string bracketopen = "[";
    string bracketclose = "]";
    string insertingcont = "{\""+question+"\":\""+val+"\"}";
    string insertingcontent=bracketopen+insertingcont+bracketclose;
    ret insertingcontent;

}

bool palindrome_(string a){
   if(a==rev_string(a)){
      ret true;
   }
   else{
      ret false;
   }
}

/*void system__write(string code){
    char *p;
    p = string_to_char_array(code);
    system(p);
    free(p);
}*/

string convert_string_to_lowercase(string str){
   for(int i=0;str[i]!='\0';i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')    //checking for uppercase characters
			str[i] = str[i] + 32;         //converting uppercase to lowercase
	}
   ret str;
}

string convert_string_to_uppercase(string str){
   for(int i=0;str[i]!='\0';i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')    //checking for uppercase characters
			str[i] = str[i] - 32;         //converting uppercase to lowercase
	}
   ret str;
}

int random_number_(int n1){
   int iRand = (rand() % n1) + 1;
   ret iRand;
}

void system_write_(string code){
    char *p;
    p = string_to_char_array(code);
    system(p);
    p = NULL;
}

string get_system_write_(string d) {

    string data;
    FILE * stream;
    const int max_buffer = 1000000;
    char buffer[max_buffer];
    d.append(" 2>&1"); 

    stream = popen(d.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
        pclose(stream);
    }
    ret data;
}

}//namespace vyn

