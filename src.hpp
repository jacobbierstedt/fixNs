#include <vector>
#ifndef SRC_H
#define SRC_H



struct gapBed
{
  std::vector<std::string> chr, name;
  std::vector<int> start, stop, gaplen;
};

struct seq
{
  std::string fasta;
  std::string newfa;
  int adjust;
};

const int FINAL_GAP_SIZE = 100;


gapBed readBed(const char* pfile);
void printBed(gapBed gbp);
seq readFasta(const char* pfile);
int calculateAdjustment(seq ss, gapBed gb);
void adjustGaps(seq ss, gapBed gb);




#endif
