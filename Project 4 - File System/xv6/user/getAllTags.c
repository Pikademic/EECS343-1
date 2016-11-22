#include "types.h"
#include "user.h"
// make sure that struct Key is included via either types.h or user.h above

#define O_RDONLY 0x000
#define O_WRONLY 0x001
#define O_RDWR 0x002
#define O_CREATE 0x200

int
main(int argc, char *argv[])
{
 int fd = open("ls", O_RDWR);
 tagFile(fd, "type", "utility", 7);
 tagFile(fd, "type", "xmanxma", 7);
 tagFile(fd, "type", "yeildxxx", 8);
 tagFile(fd, "language", "English", 7);
 tagFile(fd, "language", "Java", 4);
 tagFile(fd, "school", "Stanford", 8);
 tagFile(fd, "school", "MIT", 3);
 tagFile(fd, "Game", "NBA", 3);
 tagFile(fd, "Game", "CUBA", 4);
 close(fd);

 fd = open("ls", O_RDONLY);

 struct Key keys[16];
 int numTags = getAllTags(fd, keys, 16);
 if(numTags < 0){
   exit();
 }

 if(numTags > 16){
   numTags = 16;
 }
 char buffer[18];
 int i;
 printf(1, "Here is a list of this file's tags:\n");
 for(i = 0; i < numTags; i++){
   int res = getFileTag(fd, keys[i].key, buffer, 18);
   if(res > 0){
     printf(1, "%s: %s\n", keys[i].key, buffer);
   }
 }
 close(fd);

 exit();
}