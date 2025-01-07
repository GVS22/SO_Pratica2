#ifndef RESOURCE_H
#define RESOURCE_H

typedef struct {
    int id;
    int is_allocated;
} Resource;

Resource* create_resource(int id);
void allocate_resource(Resource* resource);
void release_resource(Resource* resource);

#endif
