#include "fillRNTuple.h"
#include "myVector.h"
#include "sphereRandomGen.h"

#include <ROOT/RNTupleModel.hxx>
#include <ROOT/RNTupleWriter.hxx>

#include <iostream>
#include <random>

void fillRNTuple(std::string_view dataset_name, std::string_view file_name,
                 unsigned n_entries) {

  std::mt19937 rng{std::random_device{}()};
  std::uniform_real_distribution<float> u01pdf{0, 1};

  auto u01 = std::bind(u01pdf, rng);

  auto model = ROOT::RNTupleModel::Create();
  auto myV = model->MakeField<myVector>("point");

  auto writer =
      ROOT::RNTupleWriter::Recreate(std::move(model), dataset_name, file_name);

  float x, y, z;
  for (auto i = 0; i < n_entries; i++) {
    genPointOnSphere(u01(), u01(), x, y, z);
    myV->SetX(x);
    myV->SetY(y);
    myV->SetZ(z);
    writer->Fill();
  }
}