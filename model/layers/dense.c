#include "dense.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void dense_forword(struct Layer *layer) {
    struct DenseLayer *denseLayer = ContainerOf(layer, DenseLayer, base);
    // TODO
}

void dense_backword(struct Layer *layer) {
    struct DenseLayer *denseLayer = ContainerOf(layer, DenseLayer, base);
    // TODO
}

struct Layer *Dense(uint64_t units, ActivationType actv) {
    struct DenseLayer *layer = (struct DenseLayer*)malloc(sizeof(DenseLayer));
    if (layer == NULL) {
        printf("dense layer alloc failed!\n");
        exit(1);
    }

    dlist_init(&layer->base.node);
    layer->base.activation = actv;

    layer->units = units;

    layer->base.ops.backword = dense_backword;
    layer->base.ops.forword = dense_forword;

    return &layer->base;
}