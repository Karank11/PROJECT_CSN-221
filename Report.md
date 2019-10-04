#                                    A case for two-way skewed-associative caches

## Research Problem Statement
As the gap between the performance of microprocessor and memory performance widens, the penalty for accessing
required data from higher level cache increases rapidly. Therefore, the miss rate is a key factor in deciding 
the performance of the cache from its average memory access time. Since the size of the caches are often 
constrained so as not to make the processor chip too large.
<br/>In response to this problem, it is important to find ways of increasing the hit rate without simply 
increasing the size of the L2 cache. One way to do this is through a different mapping function, where a certain 
address is mapped to different blocks in each set, thereby reducing possible collisions.	


## Abstract
This project focuses on an idea of new organization for multi-bank cache: **The skewed-associative cache**. In which , 
we will consider the case of two-way skewed associative cache.
<hr/>There is an inherent tradeoff between direct mapped caches and associative caches.Direct mapped caches don’t have 
to choose among the cache lines (single cache line) but at the same time suffers from high miss rate.On the other hand,
set-associative caches provide has relatively less miss rate by providing flexibility to place in different cache
lines, hence less conflict misses.So skewed-associative cache is  a new design which helps in improving miss rate while
not compromising with the frequency at the same time.The hardware complexity of two-way skewed-associative cache  is same
as the two-way set-associative cache ,yet simulations show that it typically exhibits the same hit ratio as a four-way 
set associative cache with the same size. Then skewed-associative caches must be preferred to set-associative caches. 
Direct-mapped caches exhibit hit ratios nearly as good as set-associative caches at a lower hardware cost. Moreover,
the cache hit time on a direct-mapped cache may be quite smaller than the cache hit time on a set-associative cache.
