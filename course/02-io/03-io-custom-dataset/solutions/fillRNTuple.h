#ifndef __FILLRNTUPLE_H__
#define __FILLRNTUPLE_H__

#include <string_view>

void fillRNTuple(std::string_view dataset_name, std::string_view file_name,
                 unsigned n_entries);

#endif