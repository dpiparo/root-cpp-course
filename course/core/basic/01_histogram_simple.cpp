#include <TH1D.h>

#include <iostream>

int main()
{
    TH1D h{"h", "h", 10, -5, 5};
    h.FillRandom("gaus");

    std::cout << "Histogram (" << h.GetEntries()
              << " entries): mean=" << h.GetMean()
              << " +- " << h.GetStdDev() << "\n";
}
