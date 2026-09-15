#include "fillTree.h"
#include "myVector.h"
#include "sphereRandomGen.h"

#include <TFile.h>
#include <TTree.h>

#include <functional>
#include <memory>
#include <random>

void fillTree(std::string_view dataset_name, std::string_view file_name,
              unsigned n_entries) {

  std::mt19937 rng{std::random_device{}()};
  std::uniform_real_distribution<float> u01pdf{0, 1};

  auto u01 = std::bind(u01pdf, rng);

  std::unique_ptr<TFile> file{TFile::Open(file_name.data(), "RECREATE")};
  //file->SetCompressionSettings(ROOT::RCompressionSetting::EDefaults::kUseSmallest);
  auto tree = std::make_unique<TTree>(dataset_name.data(), dataset_name.data());

  myVector myV{};
  tree->Branch("point", &myV, 32000, 99);

  float x, y, z;
  for (auto i = 0; i < n_entries; i++) {
    genPointOnSphere(u01(), u01(), x, y, z);
    myV.SetX(x);
    myV.SetY(y);
    myV.SetZ(z);
    tree->Fill();
  }

  file->Write();
}