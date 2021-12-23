#include<dirent.h> // Directory Entries - Access Folder
#include<stdio.h>
#include<string.h>

int main()
{
    int i;
    char ag = 'y';
    DIR *d;
    DIR *n;
    struct dirent *dir;

while(ag == 'y')
{
    char path[1000],drive[4] = "C:\\", folder[1000], cmd[1000],file_formate[25];
    for(i=0;i<23;i++)
    {
        d = opendir(drive);      // Open Directory
        if(d != 0)
            printf("%s\n", drive);

        drive[0]++;
    }
    printf("Choose Drive: ");
    gets(drive);

    strcpy(path,drive); // path = "D:"
    strcat(path,"\\"); // path = "D:\\"

    d = opendir(drive);

    system("cls");     //Clear Screen

    if (d)
    {
        while ((dir = readdir(d)) != NULL)      //Folder Listing
        {
            printf("%s\n", dir->d_name);
        }
    }

        printf("Choose a Folder: ");
        gets(folder);

        strcat(path,folder); // path = "D:\\A"
        strcat(path,"\\"); // path = "D:\\A\\"

        d = opendir(path);         //Open the selected folder

        if (d)
        {
            while ((dir = readdir(d)) != NULL)       //File Listing
            {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        }


   printf("The file formats are above there \n");
   printf("Enter file formate to delete:\n");
   gets(file_formate);


    strcpy(cmd,"del "); // del
    strcat(cmd,path); // del D:\\A\\ ;
    strcat(cmd,"*."); // del D:\\A\\*."
    strcat(cmd,file_formate); // del D:\\A\\*.mp4"
    n = system(cmd);         //execute the command from string path
    if(n==0)
    {
        printf("files removed successfully\n");
    }
    else
    {
        printf("sorry try again\n");
    }

    printf("Do you want to delete more? (y/n): ");
    ag = getchar();
    getchar();

    system("cls");    // Clear screen
}

    printf("Thanks");
   return 0;

   }
