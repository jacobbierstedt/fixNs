#include <iostream>
#include <vector>
#include "src.hpp"

/*
This program was written to adjust the sizes of gaps in a sequence file based on the positioins of
gaps that need adjusting. It requires two input files, one single-line file that contains the sequence
and a 4-column tab-delimited file that has the columns: chromosome, start, stop, name. These columns
should give the information needed to locate the gaps that need to be modified. The name is not
completely necessary, so if you dont have a name just fill the 4th column with anything.

The output will be to stdout the sequence with the gaps corrected.

I would suggest generating the input files and passing them as arguments with GNU parallel.
*/


int main(int argc, char const *argv[])
{

  // Uncomment this one to output the adjustment in second line for quality control checks (comment out adjustGaps)
  // calculateAdjustment(readFasta(argv[1]), readBed(argv[2]));


  adjustGaps(readFasta(argv[1]), readBed(argv[2]));


  return 0;
}
