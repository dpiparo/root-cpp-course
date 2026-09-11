#include <TH1D.h>

#include <iostream>

int main()
{
    // Parameter meaning: name, title, number of bins, minimum x, maximum x
    TH1D h{"h", "h", 10, -5, 5};
    h.FillRandom("gaus");

    std::cout << "Histogram (" << h.GetEntries()
              << " entries): mean=" << h.GetMean()
              << " +- " << h.GetStdDev() << "\n";
}
