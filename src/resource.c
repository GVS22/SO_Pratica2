#include <stdio.h>
#include <stdlib.h>
#include "resource.h"

Resource* create_resource(int id) {
    Resource* resource = (Resource*)malloc(sizeof(Resource));
    resource->id = id;
    resource->is_allocated = 0;
    return resource;
}

void allocate_resource(Resource* resource) {
    resource->is_allocated = 1;
}

void release_resource(Resource* resource) {
    resource->is_allocated = 0;
}
