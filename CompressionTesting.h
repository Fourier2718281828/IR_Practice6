#ifndef COMPRESSING_TESTING_
#define COMPRESSING_TESTING_
#include "LexicalCompressor.h"
#include "CompressedIndexer.h"

namespace testing
{


	namespace compression
	{
		void execute_testing()
		{
			CompressibleIndexer indexer;
			indexer.add_word(std::string("abdddddddddddddddddddd"), "1");
			indexer.add_word(std::string("abdddddddddddddddddddd"), "2");
			indexer.add_word(std::string("abdddddddddddddddddddd"), "3");

			indexer.add_word(std::string("akdddddddddddddddddddd"), "3");


			indexer.add_word(std::string("bc"), "2");
			indexer.add_word(std::string("bc"), "3");
			indexer.add_word(std::string("bc"), "4");

			indexer.add_word(std::string("bk"), "4");


			indexer.add_word(std::string("cd"), "3");
			indexer.add_word(std::string("cd"), "4");
			indexer.add_word(std::string("cd"), "5");
			
			indexer.add_word(std::string("ck"), "5");



			CompressedIndexer compressed(indexer);

		}
	}
}

#endif // !COMPRESSING_TESTING_
