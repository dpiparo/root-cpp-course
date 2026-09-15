#include "readRNTuple.h"
#include "myVector.h"

#include <ROOT/RNTupleModel.hxx>
#include <ROOT/RNTupleReader.hxx>

#include <TCanvas.h>
#include <TGraph2D.h>

void readRNTuple(std::string_view dataset_name, std::string_view file_name) {

  auto model = ROOT::RNTupleModel::Create();

  auto myVec = model->MakeField<myVector>("point");

  auto reader =
      ROOT::RNTupleReader::Open(std::move(model), dataset_name, file_name);

  TGraph2D myGraph;
  for (auto entry_idx : *reader) {
    reader->LoadEntry(entry_idx);
    myGraph.AddPoint(myVec->X(), myVec->Y(), myVec->Z());
  }
  TCanvas c;
  myGraph.Draw("AP");
  c.SaveAs("sphereRNTuple.png");
}
