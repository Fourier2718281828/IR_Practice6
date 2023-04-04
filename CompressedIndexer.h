#ifndef COMPRESSED_INDEXER_
#define COMPRESSED_INDEXER_
#include <string>
#include <vector>
#include "LexicalCompressor.h"
#include "Utilities.h"


class CompressedIndexer
{
public:

	CompressedIndexer(const CompressibleIndexer& indexer) :
		lexems_{},
		pointers_{},
		indices_{},
		block_size_(5)
	{
		//lexems_.reserve(7 * indexer.size());
		indices_.reserve(indexer.size());
		pointers_.push_back(0);
		compress_from(indexer);
	}

	

private:

	void copy_indices(const CompressibleIndexer& indexer) const
	{
		for (const auto& [_, list] : indexer.get_dict())
		{
			//indices_.emplace_back(list);
		}
	}

	void compress_from(const CompressibleIndexer& indexer) const
	{
		std::vector<std::string> words;
		words.reserve(block_size_);
		for (const auto& [word, index] : indexer.get_dict())
		{
			words.push_back(word);
			if (words.size() == block_size_)
			{
				add_block(words);
				words.clear();
			}
		}
		if (!words.empty())
		{
			add_block(words);
			words.clear();
		}
	}

	void add_block(const std::vector<std::string>& block) const
	{
		auto encode = [](const std::string& word) { return std::to_string(word.size()) + word; };
		auto prefix = common_prefix(block);
		std::string next_block = encode(prefix);
		for (auto&& word : block)
		{
			next_block += encode(word.substr(prefix.size()));
		}
		lexems_ += next_block;
		pointers_.push_back(pointers_.back() + next_block.size());
	}

private:
	mutable std::string lexems_;
	mutable std::vector<size_t> pointers_;
	mutable std::vector<VectorAdapted<size_t>> indices_;
	const size_t block_size_;
};

#endif // !COMPRESSED_INDEXER_
