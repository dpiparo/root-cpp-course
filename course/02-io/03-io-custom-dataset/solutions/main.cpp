#include "fillRNTuple.h"
#include "fillTree.h"
#include "readRNTuple.h"
#include "readTree.h"

int main() {
  auto n_entries = 10000;
  fillTree("myTree", "myTreeFile.root", n_entries);
  fillRNTuple("myNTuple", "myNTupleFile.root", n_entries);

  readTree("myTree", "myTreeFile.root");
  readRNTuple("myNTuple", "myNTupleFile.root");

  return 0;
}