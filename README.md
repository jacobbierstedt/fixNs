# fixNs
Adjust size of gaps in genomic sequence to a fixed sized based on gaps identified in a BED file

The purpose of this program is to adjust a predetermined set of gaps in a genome sequence to a fixed size (i.e. set the length of unknown gaps to 100 bp for NCBI submission). 

It takes two positional arguments: 
1) a single-line sequence file (one line, one scaffold, no fasta header)
2) a 4-column sorted bed file containing the intervals for the gaps on the scaffold (chr, start, stop, name). 
 
The corrected sequence is written to stdout. It is recommended to split your genome into a single file per scaffold (no header), and split or create a bed file with the same basename corresponding to the gaps on that scaffold and passing them as arguments to fixNs. 



## Installation

Clone this repository and `make` or `make clean`

## Usage

`fixNs <scaffold_x.fa> <scaffold_x.bed>`


### TroubleShooting

The bed file needs to be sorted by position. Use `sort -k2,2n in.bed > out.bed` to sort the bed file. The sequence file can not contain a header. If you do not have an identifier for each gap, you can fill the 4th column of the bed with anything, it does not get used, but something needs to be there. You can use `awk '{print $1"\t"$2"\t"$3"\t"$1"."$2"."$3}' 3column.bed > 4column.bed` to generate a unique 4th column.  
