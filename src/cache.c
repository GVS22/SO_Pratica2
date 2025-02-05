#include <stdio.h>
#include "cache.h"

CacheEntry cache[CACHE_SIZE];
int cache_index = 0;

void initialize_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].process_id = -1;
        cache[i].last_used_time = 0;
    }
}

int is_in_cache(int process_id) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].process_id == process_id) {
            return 1;
        }
    }
    return 0;
}

void update_cache(int process_id) {
    if (!is_in_cache(process_id)) {
        cache[cache_index].process_id = process_id;
        // Atualize last_used_time se necessário
        cache_index = (cache_index + 1) % CACHE_SIZE;
    }
}
