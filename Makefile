EXEC = bf

GIT_HOOKS := .git/hooks/pre-commit
.PHONY: all
all: $(GIT_HOOKS) $(EXEC)

$(GIT_HOOKS):
	@scripts/install-git-hooks
	@echo

CC ?= gcc
CFLAGS = -std=gnu99 -Wall -O2 -g
LDFLAGS = -lpthread

OBJS := \
	src/compiler.o \
	src/optimizer.o \
	src/vm.o \
	src/bf.o
deps := $(OBJS:%.o=%.o.d)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -MMD -MF $@.d -c $<


$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(EXEC) $(OBJS) $(deps)
