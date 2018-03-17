//Ashwin Nishad
//axn165530
//CS 3377.0W1
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
#include<ctype.h>
#include"version.cpp"
using namespace std;
static float version = 1.2;
void displayVersion(float version);
void traverse(char *, unsigned long &, unsigned long &, unsigned long &); // function prototype

int main(int argc, char *argv[])
{
   displayVersion(version);
   unsigned long size, files, directories;
   size = files = directories =0;
   traverse((char*) argv[1], size, files, directories);
   
   cout<<"The total number of directories in "<<argv[1]<<" is "<<directories<<endl;
   cout<<"The total number of files in "<<argv[1]<<" is "<<files<<endl;
   cout<<"The total number of bytes occupied by all files in directory "<<argv[1]<<" is "<<size<<endl;
   return 0;
}

void traverse( char *dir_name,unsigned long & size, unsigned long & files, unsigned long & directories)
{
   DIR *dir;
   struct dirent *entry;
   struct stat info;
   dir = opendir(dir_name);
   if(!dir)
   {
      return;
   }
   
   while((entry = readdir(dir)) != NULL )
   {
      if( entry->d_name[0] != '.')
      {
         string path = string(dir_name) + "/" + string(entry->d_name);
         stat(path.c_str(), &info);
         if(S_ISREG(info.st_mode))
         {
            size += info.st_size;
            files++;
         }
         if(S_ISDIR(info.st_mode))
         {
            directories++;
            traverse((char*)path.c_str(), size, files, directories);
         }
      }
	else if(entry->d_name[0] == '.' && isalpha(entry->d_name[1])) // to check for hidden files and directories
	{
	string path = string(dir_name) + "/" + string(entry->d_name);
         stat(path.c_str(), &info);
         if(S_ISREG(info.st_mode))
         {
            size += info.st_size;
            files++;
         }
         if(S_ISDIR(info.st_mode))
         {
            directories++;
            traverse((char*)path.c_str(), size, files, directories);
         }
	}
   }
}
