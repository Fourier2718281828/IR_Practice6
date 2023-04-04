#ifndef ILIXICAL_COMPRESSOR_
#define ILIXICAL_COMPRESSOR_
#include "DocumentIndexer.h"
#include "PairedVectorAdapted.h"
#include "VectorAdapted.h"
#include "DefaultPolicy.h"

using CompressibleIndexer = DocumentIndexer
<
	std::string,
	std::string,
	PairedVectorAdapted,
	VectorAdapted,
	DefaultPolicy
>;





#endif // !ILIXICAL_COMPRESSOR_
