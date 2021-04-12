#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "src.hpp"





gapBed readBed(const char* pfile)
{
  std::ifstream bed(pfile);
  std::string line, ch, nam;
  int sta, sto;
  gapBed gb;

  while(std::getline(bed, line))
  {
    std::stringstream sline(line);
    while(sline >> ch >> sta >> sto >> nam)
    {
      gb.chr.push_back(ch);
      gb.start.push_back(sta);
      gb.stop.push_back(sto);
      gb.name.push_back(nam);
      gb.gaplen.push_back( sto - sta);
    }
  }
  return gb;
}


void printBed(gapBed gbp)
{
  int i =0;
  while(i < gbp.chr.size())
  {
    std::cout << gbp.chr[i] << "\t" << gbp.start[i] << "\t" << gbp.stop[i] << "\t" << gbp.name[i] << "\t" << gbp.gaplen[i] << std::endl;
    i++;
  }
}



seq readFasta(const char* pfile)
{
  std::ifstream fasta(pfile);
  std::string line;
  seq ss;

  getline(fasta, line);
  ss.fasta = line;
  return ss;
}



int calculateAdjustment(seq ss, gapBed gb)
{
  int i=0, tadj = 0;
  printBed(gb);
  ss.newfa = ss.fasta;
  while(i < gb.chr.size())
  {
    ss.newfa = ss.newfa.substr(0,gb.start[i]+tadj) + std::string(FINAL_GAP_SIZE,'N') + ss.newfa.substr(gb.start[i]+tadj + gb.gaplen[i], std::string::npos);
    tadj = (ss.newfa.size() - ss.fasta.size());
    i++;
  }
std::cout << ss.fasta << std::endl;
std::cout << ss.newfa << std::endl;
std::cout << "Adjustment: \t" << tadj << std::endl;
  return tadj;
}




void adjustGaps(seq ss, gapBed gb)
{
  int i=0, tadj = 0;
  ss.newfa = ss.fasta;
  while(i < gb.chr.size())
  {
    ss.newfa = ss.newfa.substr(0,gb.start[i]+tadj) + std::string(FINAL_GAP_SIZE,'N') + ss.newfa.substr(gb.start[i]+tadj + gb.gaplen[i], std::string::npos);
    tadj = (ss.newfa.size() - ss.fasta.size());
    i++;
  }
std::cout << ss.newfa << std::endl;
}
