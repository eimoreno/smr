#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <getopt.h>

using namespace std;

int main (int argc, char **argv)
{
  int c;

  while (1){
      static struct option long_options[] =
        {
          {"add",     no_argument,       0, 'a'}, // --add    ou -a
          {"append",  no_argument,       0, 'b'}, // --append ou -b
          {"delete",  required_argument, 0, 'd'}, // --delete ou -d
          {"create",  required_argument, 0, 'c'}, // --create ou -c
          {"file",    required_argument, 0, 'f'}, // --file   ou -f
          {"help",    no_argument,       0, 'h'}, // --help   ou -h
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "habc:d:f:", long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'a':
          puts ("option -a\n");
          break;

        case 'b':
          puts ("option -b\n");
          break;

        case 'c':
          printf ("option -c with value `%s'\n", optarg);
          break;

        case 'd':
          printf ("option -d with value `%s'\n", optarg);
          break;

        case 'f':
          printf ("option -f with value `%s'\n", optarg);
          break;

        case 'h':
          printf ("option -h\n");
          break;

        case '?':
          /* getopt_long already printed an error message. */
          printf ("HEEEEELP \n");
          break;

        default:
          abort ();
        }
    }

/* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
