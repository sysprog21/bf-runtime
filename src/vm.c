#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "bf.h"
#include "vm.h"

int bf_vm_init(bf_vm *vm)
{
    size_t sz = sizeof(cell_t) * MAX_CELLS;
    vm->data = (cell_t *) malloc(sz);
    memset(vm->data, 0, sz);
    // FIXME: implement
    // vm->jit_context = jit_context_create();
    return 0;
}

bf_vm *bf_vm_create()
{
    bf_vm* vm = (bf_vm *) malloc(sizeof(bf_vm));
    bf_vm_init(vm);
    return vm;
}

void bf_vm_free(bf_vm *vm)
{
    free(vm->data);
    free(vm);
}

int bf_vm_run(bf_vm *vm)
{
    cell_t *arg = vm->data + MAX_CELLS / 2;
    void *args[1] = { &arg };
    // FIXME: implement
    // jit_function_apply(vm->jit_function, args, NULL);
    return 0;
}
