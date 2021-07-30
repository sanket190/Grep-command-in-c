#include<stdio.h>
#include"file.h"
#include<string.h>
#include<stdlib.h>

/* NAME : SANKT  MOHAN CHAUDHARI
    MIS : 111903085
    DIV : 1
    BATCH : S5
*/


 int main(){


     char filename[50];
     char arr[50];

     init();

     while(1){

     char input[100];
     printf("$");
     gets(input);
     int len = strlen(input);
     int flag,k,l,m,temp=0;


     for(int i=0;i<4;i++){
        if(input[i]=='g' || input[i]=='r' || input[i]=='e'|| input[i]=='p'){
            flag = 1;
        }
        else{
            flag=0;
           break;
        }
     }
     if(flag==1){

            for(int j=4;j<len;j++){

               if(input[j]==' '){
                    continue;
                }

               else if(input[j]=='-'){
                     k=j+1;



                    //Case insensitive search
                    if(input[k]=='i'){
                            init();//initialisation of linked list
                            m=k+1;
                            while(m<len){

                                if(input[m]==' '){
                                     m++;
                                     continue;
                                }
                                else if(input[m]=='"'){
                                        l=m+1;
                                        temp=0;
                                   while(input[l]!='"'){
                                        arr[temp]=input[l];
                                        temp++;
                                    l++;
                                  }
                                  arr[temp]='\0'; // for end of line
                                  m=l;
                                }
                                else if(ischar(input[m])){
                                          l=m;
                                          temp=0;
                                   while(input[l]!='\0'){

                                        if(input[l]==' '){
                                            continue;
                                        }
                                        else{
                                            filename[temp]=input[l];
                                            temp++;
                                            l++;
                                        }
                                  }
                                   filename[temp]='\0'; // for end of line
                                   line_Numbering(filename); //insering the lines into the linked list

                                   Case_insensitive_search(arr);

                                  m=l;
                                }
                                m++;

                            }


                    }

                    //This prints only a count of the lines that match a pattern
                        else if(input[k]=='c'){

                                int count;
                                init();//initialisation of linked list
                                m=k+1;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       count = count_occurance_match_world_in_file(arr);
                                       printf("%d",count);
                                      m=l;
                                    }
                                    m++;

                                }

                        }
                        //print all filename that contain match pattern
                        else if(input[k]=='l'){
                               init();
                               char arr_store[50];
                               char arr_file[50];
                                m=k+1;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                arr_file[temp]='z'; //marker
                                                temp++;

                                            }
                                            else if(ischar(input[l]) || input[l]=='.'){
                                                arr_file[temp]=input[l];
                                                temp++;


                                            }

                                            l++;

                                      }
                                      arr_file[temp]='z';
                                      arr_file[temp+1]='\0';
                                      int length=strlen(arr_file);

                                      int index =0;
                                      for(int x=0;x<length;x++){
                                                //check for marker
                                            if(arr_file[x]=='z'){
                                                 arr_store[index]='\0';
                                                   Display_filename(arr,arr_store);
                                                  while(index){
                                                    arr_store[index]=0;
                                                    index--;
                                                  }



                                            }
                                            else if(ischar(arr_file[x]) || arr_file[x]=='.'){

                                                arr_store[index]=arr_file[x];
                                                index++;
                                            }

                                      }

                                      m=l;
                                    }
                                    m++;

                                }



                        }



                        //to check the whole word in string instead of substring
                        else if(input[k]=='w'){



                                init();//initialisation of linked list
                                m=k+1;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       whole_word_search(arr);
                                      m=l;
                                    }
                                    m++;

                                }


                        }

                        //Displaying only the matched pattern

                        else if(input[k]=='o'){


                                int count;
                                init();//initialisation of linked list
                                m=k+1;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       count = count_occurance_match_world_in_file(arr);
                                       for(int i=0;i<count;i++){
                                          printf("%s\n",arr);
                                       }
                                      m=l;
                                    }
                                    m++;

                                }


                        }
                        //Show line number while displaying
                        else if(input[k]=='n'){

                                init();//initialisation of linked list
                                m=k+1;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       print_line_no_of_match(arr);

                                      m=l;
                                    }
                                    m++;

                                }

                        }
                        //it display the lines that are not matched with the specified search sting pattern
                        else if(input[k]=='v'){

                                init();//initialisation of linked list
                                m=k+1;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       Display_lines_not_match_word(arr);

                                      m=l;
                                    }
                                    m++;

                                }
                            }
                        // it will print n line After searched line
                        else if(input[k]=='A'){
                                int n;//for number of lines
                                init();//initialisation of linked list
                                m=k+1;
                                n=(int)(input[m]);
                                n= n-'0';
                                m++;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       print_n_line_after_line(arr,n);

                                      m=l;
                                    }
                                    m++;

                                }

                        }
                        // it will print n line before searched line
                        else if(input[k]=='B'){
                                int n;//for number of lines
                                init();//initialisation of linked list
                                m=k+1;
                                n=(int)(input[m]);
                                n= n-'0';
                                m++;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       print_n_line_before_line(arr,n);

                                      m=l;
                                    }
                                    m++;

                                }


                        }
                        // it will print n line before and after searched line
                        else if(input[k]=='C'){
                                int n;//for number of lines
                                init();//initialisation of linked list
                                m=k+1;
                                n=(int)(input[m]);
                                n= n-'0';
                                m++;
                                while(m<len){

                                    if(input[m]==' '){
                                         m++;
                                         continue;
                                    }
                                    else if(input[m]=='"'){
                                            l=m+1;
                                            temp=0;
                                       while(input[l]!='"'){
                                            arr[temp]=input[l];
                                            temp++;
                                        l++;
                                      }
                                      arr[temp]='\0'; // for end of line
                                      m=l;
                                    }
                                    else if(ischar(input[m])){
                                              l=m;
                                              temp=0;
                                       while(input[l]!='\0'){

                                            if(input[l]==' '){
                                                continue;
                                            }
                                            else{
                                                filename[temp]=input[l];
                                                temp++;
                                                l++;
                                            }
                                      }
                                       filename[temp]='\0'; // for end of line
                                       line_Numbering(filename);
                                       print_n_line_before_and_after_line(arr,n);

                                      m=l;
                                    }
                                    m++;

                                }
                        }

                        j=m; // update the index

                }
                else if(input[j]=='"' && input[j+1]=='^'){
                    init();

                    l=j+2;
                    temp=0;
                    while(input[l]!='"'){
                            arr[temp]=input[l];
                            temp++;
                        l++;
                      }
                      arr[temp]='\0'; // for end of line
                    m=l;



                    while(m<len){

                                if(input[m]==' '){
                                     m++;
                                     continue;
                                }

                                else if(ischar(input[m])){
                                          l=m;
                                          temp=0;
                                   while(input[l]!='\0'){

                                        if(input[l]==' '){
                                            continue;
                                        }
                                        else{
                                            filename[temp]=input[l];
                                            temp++;
                                            l++;
                                        }
                                  }
                                   filename[temp]='\0'; // for end of line
                                   line_Numbering(filename);
                                   Display_the_line_start_with_word(arr);

                                  m=l;
                                }
                                m++;

                            }
                            printf("\n");

                }
                else if(input[j]=='"' && ischar(input[j+1])){
                        init();
                        l=j+1;
                        while(input[l]!='$'){
                            arr[temp]=input[l];
                                temp++;
                            l++;
                          }
                          arr[temp]='\0'; // for end of line
                           m=l+1;

                        while(m<len){

                                if(input[m]==' '){
                                     m++;
                                     continue;
                                }

                                else if(ischar(input[m])){
                                          l=m;
                                          temp=0;
                                   while(input[l]!='\0'){

                                        if(input[l]==' '){
                                            continue;
                                        }
                                        else{
                                            filename[temp]=input[l];
                                            temp++;
                                            l++;
                                        }
                                  }
                                   filename[temp]='\0'; // for end of line
                                   line_Numbering(filename);
                                   Display_the_line_End_with_word(arr);

                                  m=l;
                                }
                                m++;

                            }
                            printf("\n");

                }
            }

     }
     else{
        printf("Invalid input!\n");
     }

    printf("\n");


}



  return 0;
}















