CC=gcc
CFLAGS=-Wall -Wextra -pedantic -ggdb2
INCLUDES=-Isrc
LIBS=
TESTLIBS=-lcriterion

SRCDIR=src
BUILDDIR=build

ifeq ($(BUILD_TYPE), DEBUG)
CFLAGS += -g
endif

MAKEDIR=$(BUILDDIR)/make
CMAKEDIR=$(BUILDDIR)/cmake

NAME=logc4

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c, $(MAKEDIR)/%.o, $(SRC))
LOGC4TEST=$(MAKEDIR)/$(NAME)_test

PROGOUTDIR=out
PROGOUT=$(PROGOUTDIR)/prog_out
DOXYDIR=$(PROGOUTDIR)/doxyfile
VLGDIR=$(PROGOUTDIR)/valgrind
TEST=test_files
TESTS=$(TEST)/tests
TESTSRESDIR=$(TEST)/results
TESTSGIVDIR=$(TESTSRESDIR)/given
TESTSGENDIR=$(TESTSRESDIR)/generated

# This function is to remove all files in a directory except the directory
# itself.
define rm_wild
	$(eval $@_DIR = $(1))
	$(eval $@_RMPAT1 = "..?*")
	$(eval $@_RMPAT2 = ".[!.]*")
	$(eval $@_RMPAT3 = "*")
	echo "rm -rf ${$@_DIR}/${$@_RMPAT1} ${$@_DIR}/${$@_RMPAT2} \
${$@_DIR}/${$@_RMPAT3}"
	rm -rf "${$@_DIR}/${$@_RMPAT1}"
	rm -rf "${$@_DIR}/${$@_RMPAT2}"
	rm -rf "${$@_DIR}/${$@_RMPAT3}"
endef

.PHONY: all
all: $(MAKEDIR)/$(OBJ)

$(MAKEDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -c $< -o $@

.PHONY: test
test: $(LOGC4TEST)

$(LOGC4TEST): $(MAKEDIR)/$(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(LOGC4TEST) $(OBJ) $(TESTLIBS)

.PHONY: setup
setup:
	mkdir -p $(MAKEDIR)
	mkdir -p $(CMAKEDIR)
	mkdir -p $(PROGOUT)
	mkdir -p $(DOXYDIR)
	mkdir -p $(VLGDIR)
	mkdir -p $(TESTS)
	mkdir -p $(TESTSGIVDIR)
	mkdir -p $(TESTSGENDIR)

.PHONY: clean
clean:
	@$(call rm_wild,$(MAKEDIR))
	@$(call rm_wild,$(CMAKEDIR))
	@$(call rm_wild,$(PROGOUT))
	@$(call rm_wild,$(DOXYDIR))
	@$(call rm_wild,$(VLGDIR))
	@$(call rm_wild,$(TESTSGENDIR))

.PHONY: destroy
destroy:
	rm -rf $(BUILDDIR)
	rm -rf $(PROGOUTDIR)
	rm -rf $(TESTSGENDIR)
