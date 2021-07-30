#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h> // for toupper function
#include"file.h"
#define line_len 256


// +++++++++++++++++++++++++++++++++++++++++++  SET UP FOR STORING DATA +++++++++++++++++++++++++++++++++++++++++++++++++++++++//

// to store the charecters file
struct text{
    int line_no;
    char *line;
   struct text *next;
};

struct text *node; //variable of structure

void init(){
    node = NULL;
    return;
}

struct text* Newnode(int line_no,char *filename){

    struct text *newnode = (struct text *)malloc(sizeof(struct text));//allocating  memory

    if(!newnode){
        return NULL;//if node is not allocated
    }
    newnode->line_no=line_no;

    newnode->line=read_line(line_no,filename);

    newnode->next=NULL;

    return newnode;

}

char *read_line(int line_no,char *filename){
    FILE *fptr;
    int count=1;

    char *c = (char*)malloc(line_len*sizeof(char));

    if((fptr = fopen(filename,"r"))==NULL){
        printf("Error! file not open");
        exit(1);
    }
    // reads text until newline is encountered
   while(fgets(c, line_len, fptr)!=NULL) {

        if(line_no==count){
             fclose(fptr);
             return c;
        }
        else{
            count++;
        }
    }
    return NULL;

}


void insert_line(int line_no,char *filename){
    struct text *current;

    if(node==NULL){
        node=Newnode(line_no,filename);

    }
    else
        {

        current=node;

        while(current->next!=NULL){
            current=current->next;
        }
        struct text *NEW=Newnode(line_no,filename);

        NEW->next=current->next;
        current->next=NEW;
    }

}

int count_line(char *filename){
    FILE *fp;
    int count = 0;

    fp = fopen(filename,"r");
    char c;
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file");
        return 0;
    }


    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;


    fclose(fp);
    //printf("%d",count);
    return count;
}

//it will call insert function to insert line numberwise
void line_Numbering(char *filename){
    int count = count_line(filename);
    //inserting those lines in linked list
    for(int i=1;i<=count+1;i++){
        //printf("%d",i);
        insert_line(i,filename);
    }
     //display();
}





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ MAIN functions ++++++++++++++++++++++++++++++++++++++++++++++++++++++//



//********************************************** ( -i)  *****************************************//

//for searching word or pattern that similar to input world in whichever case is in.


char *strcasestr(const char *str, const char *pattern) {
    size_t i;

    if (!*pattern)
        return (char*)str;

    for (; *str; str++) {
        if (toupper((unsigned char)*str) == toupper((unsigned char)*pattern)) {
            for (i = 1;; i++) {
                if (!pattern[i])
                    return (char*)str;
                if (toupper((unsigned char)str[i]) != toupper((unsigned char)pattern[i]))
                    break;
            }
        }
    }
    return NULL;
}

void Case_insensitive_search(char *text){

    char *flag;

    struct text *temp=node;

    while(temp!=NULL){

        flag =  strcasestr(temp->line,text);

        if(flag!=NULL){
            printf("%s",temp->line);
        }
        temp= temp->next;

    }
}

void Case_sensitive_search(char *text){

    char *flag;

    struct text *temp=node;

    while(temp!=NULL){

        flag =  strstr(temp->line,text);

        if(flag!=NULL){
            printf("%s",temp->line);
        }
        temp= temp->next;

    }
}

//*************************************** (-c) ********************************************************//



//return the count of matched word in line
int  count_occurance_match_world_in_line(char *search,int line_no){



    int searchlen = strlen(search);

    struct text *temp=node;

    while(temp->line_no!=line_no){
        temp=temp->next;
    }


    int linelen = strlen(temp->line);


    int i=0,j=0,found,count=0;

    //logic : checking each word of line with each word of search word
    for(i=0;i<(linelen-searchlen);i++){

        found=1;
        for(j=0;j<searchlen;j++){
                //form i to i+j we cam each word
            if(temp->line[i+j]!=search[j]){
                found=0;
                break;
            }
        }
        // if found increase count
        if(found==1){
            count++;
        }
    }//termination of outer for loop

    return count;
}


//return the count of matched word in file

int count_occurance_match_world_in_file(char *text){

   int count=0;
  // printf("%s ",text);
   struct text *temp=node;

   while(temp!=NULL){
        count = count + count_occurance_match_world_in_line(text,temp->line_no);
        temp=temp->next;
   }
   return count;

}







//*************************************** (-w) ********************************************************

//print the lines that contain the input word
void whole_word_search(char *text){
    struct text* temp=node;

   while(temp!=NULL){
      char* p=temp->line;
      for(;;)
          {
            p = strstr(p,text);

            if (p == NULL) {
                    break;
            }
            // if whole word is found then it check that word by word if true it print that line
            if ((p==temp->line) || !isalnum((unsigned char)p[-1]))
            {

               p += strlen(text);
               if (!isalnum((unsigned char)*p))
               {

                 printf("%s",temp->line);
                 break;  // found, quit
               }
            }
            // substring was found, but no word match, move by 1 char and retry
            p+=1;
          }
          temp=temp->next;

  }
}


//*************************************** (-n) ********************************************************//


void print_line_no_of_match(char *text){

    char *flag;

    struct text *temp=node;

    while(temp!=NULL){

        flag =  strstr(temp->line,text);

        if(flag!=NULL){
           printf("%d.",temp->line_no);
           printf("%s",temp->line);


        }
        temp = temp->next;

    }
}


//*************************************** (-v) ********************************************************//


void Display_lines_not_match_word(char *text){

    char *flag;

    struct text *temp=node;

    while(temp!=NULL){

        flag =  strstr(temp->line,text);

        if(flag==NULL){
            printf("%s",temp->line);
        }
        temp= temp->next;

    }
}

//*************************************** (-l) ********************************************************//


//it display the file that match give pattern the pattern
void Display_filename(char *text,char *filename){

    FILE *fptr;
    char c[1000];
    char ch;
    if((fptr = fopen(filename,"r"))==NULL){
        printf("Error! file not open !!");
        exit(1);
    }
    // reads text until newline is encountered
   do{
        ch = fscanf(fptr ,"%s", c);
        if(strcmp(c,text)){
            printf(" %s ",filename);
            break;
        }
   }while(ch!=EOF);
   return;
}


//*************************************** (^) && ($)  ********************************************************//

void Display_the_line_start_with_word(char *text){

    struct text *temp=node;

    int len = strlen(text);

    int i=0;
    while(temp!=NULL){


        //checking starting word char by char of line
        while(temp->line[i]==text[i]){
           i++;
        }

        if(i==len){
             printf("%s",temp->line);
        }
        i=0;
        temp = temp->next;

    }
}

void Display_the_line_End_with_word(char *text){

    struct text *temp=node;

    int wordlen = strlen(text);

    int i=0,k;
    while(temp!=NULL){
            i=0;
            while(temp->line[i]!='.'){
                i++;
            }
            i--;
         k=wordlen-1;

        while(temp->line[i]==text[k]){
           k--;
           i--;
        }

        if(k==-1){
             printf("%s",temp->line);

        }

        temp = temp->next;

    }
}







//*************************************** (-A) && (-B) && (-C) ********************************************************//

//it will print the n lines after given line including given line
void print_n_line_after_line(char *line,int n){
    struct text *temp = node;

    int x;
    char *k;
    while(temp!=NULL){

        k=strcasestr(temp->line,line);

        if(k!=NULL){
            printf("%s",temp->line);
            x=n;
            while(x){
                temp=temp->next;
                printf("%s",temp->line);
                x--;

            }
             printf("\n  --  \n");

        }

        temp = temp->next;
    }
    if(x){
        printf("line not found");
    }


}
//it will print the n lines before given line including given line
void print_n_line_before_line(char *line,int n){
    struct text *temp = node;

    int count=0,linenum,mark[50];
    char *k;
    for(int i=0;i<49;i++){
        mark[i]=0;
    }
    while(temp!=NULL){

        k=strcasestr(temp->line,line);
        count++;
        //if identical
        if(k!=NULL && mark[temp->line_no]!=1){
            linenum=temp->line_no;
            mark[linenum]=1;//mark the index of line number
            count=count-n-1;
            temp=node;
            while(count){
                temp=temp->next;

                count--;

            }
            while(temp->line_no!=linenum+1){
                printf("%s",temp->line);
                temp=temp->next;
            }

              printf("\n  --  \n");// end of one search
              temp=node;
              count++;
        }
        temp = temp->next;
    }
    if(!count){
        printf("line not found");
    }

}
//it will print the n lines before and after given line including given line
void print_n_line_before_and_after_line(char *line,int n){
    struct text *temp = node;

    int count=0,linenum,mark[50],x=n;
    char *k;
     for(int i=0;i<49;i++){
        mark[i]=0;
    }
    while(temp!=NULL){

        k=strcasestr(temp->line,line);
        count++;
        //if identical
        if(k!=NULL && mark[temp->line_no]!=1){
            linenum=temp->line_no;
            mark[linenum]=1;//mark the index of line number
            count=count-n-1;
            temp=node;
            while(count){
                temp=temp->next;

                count--;

            }
            while(temp->line_no!=linenum+1){
                printf("%s",temp->line);
                temp=temp->next;
            }
            x=n;//count of line
             while(x){

                printf("%s",temp->line);
                temp=temp->next;
                x--;

            }

             printf("\n  --  \n"); // end of one search
             temp=node;
             count++;
        }
        temp = temp->next;
    }
    if(!count){
        printf("line not found");
    }

}
//*************************************** extra functions ********************************************************//
int ischar(char var){

    if((var>='A' && var<='Z')|| (var>='a' && var<='z')){
        return 1;
    }
    return 0;


}

void display(){
    struct text *temp=node;
    while(temp!=NULL){
            printf("\n%d",temp->line_no);
            temp=temp->next;
        }
}

/*
//comparison of string
int compare(char *str1,char *str2){
    int len=strlen(str2);
    int flag=0;
    for(int i=1;i<len;i++){
       if(str1[i]==str2[i]){
          flag=1;
       }else{
           return 0;
       }
    }
    if(flag==1){
        return 1;
    }
}
*/


//***************************************   END   ********************************************************//
