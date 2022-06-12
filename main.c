#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <libfyaml.h>

int main(int argc, char *argv[])
{
  struct fy_document *fyd = fy_document_build_from_file(NULL, "./example.yaml");

  // unsigned int test;
  /* get the invoice number and the given name */
	// int count = fy_document_scanf(fyd,
	// 		"/name %u ",
	// 		&test);

	/* print them as comments in the emitted YAML */
	// printf("# invoice number was %u\n", invoice_nr);
	// printf("# given name is %s\n", given);


  fy_document_destroy(fyd); /* NULL is OK */

  return EXIT_SUCCESS;
}
