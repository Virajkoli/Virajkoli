#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

void getdir(){
  DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *entry;
  entry = readdir(dir);
  while(entry != NULL){
   if(entry -> d_name[0]!='.'){
     printf("%s\n",entry -> d_name);
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

void gethdir(){
  DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *entry;
  entry = readdir(dir);
  while(entry != NULL){
   if(entry -> d_name[0]=='.'){
     printf("%s\n",entry -> d_name);
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

int main(int argc, char *argv[]){
 int opt;
 while((opt = getopt(argc,argv, ":ilrsax"))!=-1){
  switch(opt){
    case 'l':
      printf("l flag is used\n");
      getdir();
      break;
      
    case 'a':
      printf("a flag is used\n");
      gethdir();
      break;  
    default: 
      printf("Unhandled option");
  }
 }
 
 return 0;
}