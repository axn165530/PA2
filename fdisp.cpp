//Ashwin Nishad
//axn165530
//CS3377.0W1
#include <iostream>
#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include"version.cpp"
using namespace std;
static float version = 1.2;
void displayVersion(float version);

int main(int argc, char * argv[])
{
	
	string data;
	string f("files");
	string d("directories");
	string b("bytes");
	string file;
	string dir;
	string byte;
  	// Getting output from fcount
	while(getline(cin, data))
	{ 
		size_t found1 = data.find(f);
		size_t found2 = data.find(b);
		if( found1 != string::npos && found2 != string::npos)
			byte = data;
		else if(found1 != string::npos && found2 == string::npos)
			file = data;
		 found1 = data.find(d);
		if(found1 != string::npos)
			dir = data;
	}
   //comparing with argument provided
   if(strcmp(argv[1], "-d") == 0)
   {
      displayVersion(version);
      cout<<dir<<endl;
   } 
	else if(strcmp(argv[1], "-f") == 0)
	{
		displayVersion(version);
		cout<<file<<endl;
	}
	else if( strcmp(argv[1], "-b") == 0)
	{
		displayVersion(version);
		cout<<byte<<endl;
	}
   return 0;
}
