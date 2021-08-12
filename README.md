# Grep-command-in-c
Built a command that perform operations on data on files  
The grep filter searches a file for a particular pattern of characters, and displays all lines that contain that pattern from current working directory. 
Also it print or display some specific line or charecters of the file.

idea :
1. using file handling , program  will read text files line by line and each line of text file  get store in dynamic array . 
2. To access the contained of array , I created a linked list which had three field  
3. One field is character pointer which is pointed to the dynamic array which stores the single line of file ( name as ‘line’)
4. second field is line number which stores the line number of current line
5. Third field is pointer to the next node
6. For performing the each functions of grep command I made the linked list global
7 .To show the output of grep command like terminal. I used menu driven program
