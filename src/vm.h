#ifndef _BF_VM_H_
#define _BF_VM_H_

#include <stdlib.h>
#include <stdint.h>

#define MAX_CELLS 30000

typedef int cell_t;

struct _bf_vm_loop {
    /* FIXME: append JIT-specific members */
#if 0
    jit_label_t start_label;
    jit_label_t end_label;
#endif
    struct _bf_vm_loop *parent;
};

typedef struct _bf_vm_loop bf_vm_loop;

typedef struct {
    cell_t *data;
    bf_vm_loop *current_loop;

    /* FIXME: append JIT-specific members */
#if 0
    jit_context_t jit_context;
    jit_value_t data_ptr;
    jit_function_t jit_function;
#endif
} bf_vm;

bf_vm *bf_vm_create();
int bf_vm_init(bf_vm *vm);
void bf_vm_free();

int bf_vm_run(bf_vm *vm);

#endif
