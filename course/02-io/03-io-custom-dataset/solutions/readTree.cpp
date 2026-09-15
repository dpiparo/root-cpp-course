#include "readTree.h"
#include "myVector.h"

#include <TCanvas.h>
#include <TFile.h>
#include <TGraph2D.h>
#include <TTree.h>

#include <memory>

void readTree(std::string_view dataset_name, std::string_view file_name) {
  std::unique_ptr<TFile> file{TFile::Open(file_name.data())};
  auto tree = file->Get<TTree>(dataset_name.data());

  // Class type: pass by pointer to pointer
  // ROOT manages the memory pointed by the pointer
  myVector *myVec{nullptr};
  tree->SetBranchAddress("point", &myVec);

  const auto nEntries = tree->GetEntries();
  TGraph2D myGraph(nEntries);
  for (auto i = 0; i < nEntries; ++i) {
    tree->GetEntry(i);
    myGraph.SetPoint(i, myVec->X(), myVec->Y(), myVec->Z());
  }
  TCanvas c;
  myGraph.Draw("AP");
  c.SaveAs("sphereTTree.png");
}