#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>

using namespace std;

vector<double> input_numbers(size_t count);

vector<size_t> make_histogram(vector<double> numbers, size_t bin_count);

void show_histogram_text(vector<size_t> bins);

bool check_height (size_t bin_height, size_t bin_count, size_t IMAGE_HEIGHT);

void find_minmax(vector<double> numbers, double& min, double& max);

#endif // HISTOGRAM_H_INCLUDED
