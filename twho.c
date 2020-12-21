#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/param.h>
#include <pwd.h>
#include <string.h>

int main()
{
 DIR *d;
 struct dirent *dir;
 struct stat file_stats;
 const char* pts = "/dev/pts/";
 struct passwd  *pwd;

    d = opendir(pts);
    if (d == NULL) {
        return 1;
    }
    while ((dir = readdir(d)) != NULL)
    {
      char file_path[MAXPATHLEN];
      snprintf(file_path, MAXPATHLEN, "%s/%s", pts, dir->d_name);
      if (!stat(file_path, &file_stats))
       {
         if ((pwd = getpwuid(file_stats.st_uid)) != NULL)
          {
            if (S_ISCHR(file_stats.st_mode))
             {
                if (dir->d_name[strlen(dir->d_name)-1] != 'x')
                 {
                    printf("%s\n", pwd->pw_name);
           }
         }
      }
   }
}
 closedir(d);
return(0);
}
