#ifndef CACHE_H
#define CACHE_H

#define CACHE_SIZE 4 

typedef struct CacheEntry {
    int process_id;
    int last_used_time; // Pode ser usado para atualizar LRU
} CacheEntry;

void initialize_cache();
int is_in_cache(int process_id);
void update_cache(int process_id);

#endif // CACHE_H
