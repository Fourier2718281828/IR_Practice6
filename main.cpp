#include <iostream>
#include "TolerantSearchTesting.h"
#include "IndexersTesting.h"
#include "BooleanSearch.h"
#include "TwowordCoordinateIndicesTesting.h"
#include "SPIMITesting.h"
#include "CompressionTesting.h"
using namespace testing;

int main()
{
	//indexers::execute_testing();
	//boolean_search::execute_boolean_search();
	//two_word_index::execute_testing();
	//coordinate_index::execute_testing();
	//tolerant_search::execute_testing();
	//spimi::execute_testing();
	compression::execute_testing();
	return EXIT_SUCCESS;
}