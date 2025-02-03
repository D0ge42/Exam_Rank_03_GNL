#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE  1
#endif /* ifndef MACRO */

int ft_strlen(char *str)
{
  if (!str)
    return 0;
  int i = 0;
  while(str[i])
    i++;
  return i;
}

int ft_strchr(char *str, char c)
{
  if (!str)
    return 0;
  while(*str)
  {
    if(*str == c)
      return 1;
    str++;
  }
  return 0;
}

char *ft_strdup(char *str)
{
  int len = ft_strlen(str);
  if (len == 0)
    return NULL;
  char *dest = malloc(sizeof(char) * (len + 1));
  int i = 0;
  while(str[i])
  {
    dest[i] = str[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char *ft_strjoin(char *line, char *stash)
{
  int len_line = ft_strlen(line);
  int len_stash = ft_strlen(stash);

  int total = len_line + len_stash + 1;

  char *dest = malloc(sizeof(char) * total);
  int i = 0;
  int j = 0;
  while(line && line[i])
  {
    dest[j] = line[i];
    i++;
    j++;
  }
  i = 0;
  while(stash && stash[i])
  {
    dest[j] = stash[i];
    i++;
    j++;
  }
  free(line);
  dest[j] = '\0';
  return dest;
}

char *extract_line(char *stash)
{
  int i = 0;
  while(stash[i] && stash[i] != '\n')
    i++;
  char *line = malloc(sizeof(char) * (i + 2));
  int j = 0;
  while(j < i)
  {
    line[j] = stash[j];
    j++;
  }
  if (stash[i] == '\n')
    line[j++] = '\n';
  line[j] = '\0';
  return line;
}

void update_stash(char *stash)
{
    int i = 0;
    int j = 0;

    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    while (stash[i])
    {
        stash[j] = stash[i];
        i++;
        j++;
    }
  while(stash[j])
  {
    stash[j] = '\0';
    j++;
  }
}

/*Gnl will work like that. We join stash to line each iteration, until there's a new line.
 * If a new line is present we extract it and join it to line.
 * We update the stash and return it.
 * If no new line is present we update stash and call bytes_read.
 * If bytes_read == 0 and line at [0] is NULL we free line and return NULL?
 * else we return line.
 * 
 * Update stash will just shift the stash and fill remaining part with '/0'
 * Extract line is just basic extract line.
 * */

char *get_next_line(int fd)
{
  // error checking
  static char stash[BUFFER_SIZE + 1];
  char *line = NULL;

  stash[BUFFER_SIZE] = '\0';
  while(1)
  {
    if (ft_strchr(stash,'\n'))
    {
      char *line_to_join = extract_line(stash);
      line = ft_strjoin(line, line_to_join);
      free(line_to_join);
      update_stash(stash);
      return line;
    }
    line = ft_strjoin(line,stash);
    update_stash(stash);
    int bytes_read = read(fd,stash,BUFFER_SIZE);
    if (bytes_read == -1)
      return NULL;
    if (bytes_read == 0)
    {
      if (line[0] == '\0')
      {
        free(line);
        return NULL;
      }
      return line;
    }
  }
}

#include <fcntl.h>
int main()
{
  int fd = open("file.txt",O_RDONLY);
  char *line;
  int i = 23;
  while(i)
  {
    line = get_next_line(fd);
    printf("%s",line);
    free(line);
    i--;
  }
}
