# fixNs
Adjust size of gaps in genomic sequence to a fixed sized based on gaps identified in a BED file

The purpose of this program is to adjust a predetermined set of gaps in a genome sequence to a fixed size (i.e. set the length of unknown gaps to 100 bp for NCBI submission). 

It takes two arguments: 1) a single line of a file (one scaffold, no fasta header) and 2) a 4-column sorted bed file containing the intervals for the gaps on the scaffold. It outputs the corrected sequence to stdout. Recommended usage would be splitting your genome into a single file (no header) per scaffold, and splitting or creating a bed file with the same basename corresponding to the gaps on that scaffold and passing them as arguments.



## Installation

Clone this repository and `make` or `make clean`

## Usage

`fixNs <scaffold_x.fa> <scaffold_x.bed>`



