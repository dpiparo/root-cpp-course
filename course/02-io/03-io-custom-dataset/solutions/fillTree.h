#ifndef __FILLTREE_H__
#define __FILLTREE_H__

#include <string_view>

void fillTree(std::string_view dataset_name, std::string_view file_name,
              unsigned n_entries);

#endif