# Cache

subject: Cache Memory
created: May 16, 2023 6:33 PM

## Definition

Cache is a high-speed memory used to store frequently accessed or recently accessed data and instructions, so that future requests for that data/instructions can be provided faster.

Caching is the storage of duplicate copies of digital information in places that are local, fast, and convenient so that the data can be accessed quickly if needed again rather than retrieved from the ultimate source.

### Principle of locality

Programs tend to reuse data and instructions that were recently used.

This locality principle has two different types:

- **temporal locality**: recently accessed data or instructions are likely to be needed in the near future;
- **spatial locality**: items whose memory addresses are close to each other tend to be referenced close together in time.

## Cache miss

Whenever the processor fails to obtain a given word from the cache (cache miss), the word must be read from memory.

To take advantage of locality, the word and its neighbours are brought from the main memory into the cache.

### Hit/Miss rate

With the number of hits and misses, it is possible to calculate the hit rate and the miss rate.

The time required to fetch the requested data in the cache is designated as hit time.

The miss penalty is the time required to process a miss, which includes substituting a block in the cache and the additional time to deliver the requested data to the processor.

## Cache block/line

A cache block is the minimum unit of transfer between the cache and the main memory.

A cache line is the portion of the cache memory that can store one block.

A line contains control information, including:

- a tag that identifies the memory address of the block stored in that line;
- a valid bit to signal whether the data in the line is valid or not.

![Untitled](Cache%20497dd0a6f02445f199d6efe5c41293f9/Untitled.png)

---

## Mapping functions

Caches are not accessed by address, but instead by content, that is why it is called content-addressable memory (CAM).

When a given memory address is being requested, all cache entries must be searched to check if it is stored there.
When the address matches, its content is fetched from the cache memory.

### Direct mapping

For the purpose of cache access, each main memory address can be viewed as consisting of three fields:

- The o LSBs identify a unique word or byte within a memory block (o = log2 K ).
- The next s bits specify part of the block number (s = log2 m).
- The remaining t bits are saved in the tag (t = n-s-o).

![Untitled](Cache%20497dd0a6f02445f199d6efe5c41293f9/Untitled%201.png)

![Untitled](Cache%20497dd0a6f02445f199d6efe5c41293f9/Untitled%202.png)

### Fully associative mapping