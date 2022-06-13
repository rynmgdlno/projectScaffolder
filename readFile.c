#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char line[50];
  FILE *fptr;

  if ((fptr = fopen("./example.yaml", "r")) == NULL)
  {
    printf("Error! opening file");

    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  while (fgets(line, 50, fptr) != NULL) // iterating lines
  {
    if (strcmp(line, "---\n") != 0) // skipping first line
    {
      int leadingSpaces = 0;
      int currentLevel = 1;
      int lineLength = strlen(line);
      char key[40] = "";
      char prevKey[40] = "";
      char value[50] = "";
      int trackingSpaces = 1; // used to stop counting spaces after key
      int writingKey = 1;     // used to switch to value after writing key
      char lead[10] = "";

      for (int i = 0; i < lineLength; i++) // iterating characters
      {

        if (line[i] == ' ' && trackingSpaces) // counting leading spaces
        {
          leadingSpaces++;
          // ! sort out nesting level
          currentLevel = leadingSpaces / 2;
        }
        if (line[i] != ' ' && line[i] != ':' && line[i] != '-' && writingKey) // creating key
        {
          strncat(key, &line[i], 1);
        }
        if (line[i] == '-' || line[i] == ':') // cancelling space counting after key
        {
          trackingSpaces = 0;
        }
        if (line[i] == ':') // switching to writing to value
        {
          writingKey = 0;
        }
        if (line[i] != ' ' && line[i] != ':' && line[i] != '-' && !writingKey) // creating value
        {
          strncat(value, &line[i], 1);
        }
      }
      // if (!strcmp(key, "children") && strlen(value) > 1)
      // {
      //   // printf("children present\n");
      //   currentLevel++;
      // }
      // ! sort out nesting level:
      // if (!strcmp(key, "children"))
      // {
      //   currentLevel++;
      // }

      printf("%i %s: %s", currentLevel, key, value);

      leadingSpaces = 0;
    }
  }

  fclose(fptr);

  return 0;
}