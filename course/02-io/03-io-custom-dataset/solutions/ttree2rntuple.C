void ttree2rntuple() {
  auto importer = ROOT::Experimental::RNTupleImporter::Create(
      "myTreeFile.root", "myTree", "myNTupleFile_imported.root");
  importer->Import();
}
