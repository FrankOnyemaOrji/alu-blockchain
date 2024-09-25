#include "blockchain.h"

/**
 * block_mine - mines a block with requisite difficulty.
 * @block: pointer to block to mine.
 * Author: Frank Onyema Orji.
 */
void block_mine(block_t *block)
{
	/* nonce is a 64-bit number that will be used once */
	uint64_t nonce = 0;

	uint8_t hash[SHA256_DIGEST_LENGTH];

	while (1)
	{
		/* Update the block's info with the new nonce */
		block->info.nonce = nonce;

		block_hash(block, hash);

		if (hash_matches_difficulty(hash, block->info.difficulty))
			break;

		nonce++;
	}
	/* Copy the resulting hash to the block's data */
	memcpy(block->hash, hash, SHA256_DIGEST_LENGTH);
}

