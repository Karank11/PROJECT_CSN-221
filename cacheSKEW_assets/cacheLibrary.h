#ifndef lib_file

#define lib_file

#define  NbSimul 3 /* Number of Simulations for each cache policies*/

#ifdef _WIN32
#define random rand
#endif

#include <stdio.h>
#include <malloc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
  

/********* declaration of a cache **************/

typedef struct {
  
  int           Hit;
  int           Miss;
  int           Size;    /* Size = number of lines of the cache */
  int           Logbank; /* log base 2 of the bank size */
  int           Number_of_Bank; 
  int           Size_Bank;/* size in line of a bank */
  int	        DATE;    /* date of the last access to the cache */
  int           ACCESS;  /* number of access to the cache */
  
  /* the useful size of the following arrays is equal to the number of lines of the cache */
  
  unsigned int	*Cache;  /* array that contains the memory adress of the block contained in the cache line indexed */  
  
  int	*Cache_DATE; /* this array contains the date of the last access to the line indexed */ 
  
  int	*Cache_Prio; /* this variable is used to establish the priority between the blocks for some replacement policies */
  
 /* function pointers used to carry into effect the replacement policy*/
  void (*Allocate) ();
  int (*Is_In_Cache) ();
     
}CACHEINT;
  


typedef struct {
  
  CACHEINT	cacheL2;
  CACHEINT	cachedata;
  CACHEINT	cacheinst;  
  /* split caches*/
  
}CACHE;


#define FreeAddr -1

/****** definition of the possible values for "memtype" ******/

#define mem_inst 2 
#define mem_write 1
#define mem_read 0


#ifdef _main_

int	CacheSize; /* size in Bytes of the cache */

int	LOGLINE;/* log base 2 of line size */

void (*Mapfct) ();/* pointer to the mapping function */

char *ResFile;/* pointer to the result file */

unsigned int	ADDR[16384];/* input-buffer that contains the address of the memory-access */  

unsigned int	MEMTYPE[16384];/* input-buffer that contains the type of the memory-access */
 
int	Index = 0; /* Index is used by the input-buffers ADDR and MEMTYPE */

int	nbref = 0;/* number of access to the cache */

int	nbinst = 0;/* number of access to the instruction cache */

int	lastinst;  /* lastinst contains the adress of the last used instruction */

int	lastdata; /* lastdata contains the adress of the last accessed data */

int *	AdBank;	/* array that contains the address of mapping in each bank of the Skewed Associative caches */  

int	DEUP[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

int    	SCRAMBLE[32768][16]; 
/* matrix used to obtain a good dispersion between almost neighbor memory blocks */
 
#ifdef SIML2
int    	EXCLUDE = 0;/* EXCLUDE is the variable that contains the address of the evicted block on a cache miss useful for maintaining cache inclusion property */
#endif


/****** definition of the arrays of cache that will be simulated ******/

CACHE	DM[NbSimul],
	TWOSKEWLRU[NbSimul], 
	TWOSKEWRAND[NbSimul], 
	TWOSKEWpseudoLRU[NbSimul],
	TWOSKEWNRU[NbSimul],
	TWOSKEWUNRU[NbSimul],
	TWOSKEWENRU[NbSimul],
	TWOSKEWUseful[NbSimul],  
	FOURSKEWLRU[NbSimul],
	TWOASSOCLRU[NbSimul], 
	FOURSKEWENRU[NbSimul],
	FOURASSOCLRU[NbSimul], 
	FOURSKEWRAND[NbSimul], 
	TWOASSOCRAND[NbSimul], 
	FOURASSOCRAND[NbSimul], 
	EIGHTASSOCLRU[NbSimul],
	EIGHTASSOCRAND[NbSimul], 
       	SIXTEENASSOCLRU[NbSimul],
	SIXTEENASSOCRAND[NbSimul];
	



#else

extern	int	*AdBank;  
extern	int	nbref;
extern	int	nbinst;
extern	int	lastinst;
extern	int	lastdata;
extern	int	CacheSize;
extern	int	LOGLINE;
extern	char	*ResFile;
extern	unsigned int	MEMTYPE[32768];
extern	unsigned int	ADDR[32768];
extern	int	Index;
extern	int	DEUP[16];
extern	int	SCRAMBLE[32768][16];
   
#ifdef SIML2
extern	int	EXCLUDE;
#endif


extern	CACHE	DM[NbSimul];
extern	CACHE	TWOSKEWLRU[NbSimul]; 
extern	CACHE	TWOSKEWRAND[NbSimul]; 
extern	CACHE	TWOSKEWNRU[NbSimul];
extern	CACHE	TWOSKEWUNRU[NbSimul];
extern	CACHE	TWOSKEWENRU[NbSimul];
extern	CACHE	TWOSKEWUseful[NbSimul];  
extern	CACHE	FOURSKEWLRU[NbSimul];
extern	CACHE	TWOASSOCLRU[NbSimul]; 
extern	CACHE	FOURSKEWENRU[NbSimul];
extern	CACHE	FOURASSOCLRU[NbSimul]; 
extern	CACHE	FOURSKEWRAND[NbSimul]; 
extern	CACHE	TWOASSOCRAND[NbSimul]; 
extern	CACHE	FOURASSOCRAND[NbSimul]; 
extern	CACHE	EIGHTASSOCLRU[NbSimul];
extern	CACHE	EIGHTASSOCRAND[NbSimul]; 
extern	CACHE	SIXTEENASSOCLRU[NbSimul];
extern	CACHE	SIXTEENASSOCRAND[NbSimul];
extern	CACHE	TWOSKEWpseudoLRU[NbSimul];
	

#endif
#endif