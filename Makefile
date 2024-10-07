CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -lrt -lm
RM			= rm -rf
TARGET		= exercises
EX			= ex06 ex07 ex08 ex09 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex20 ex21 ex22
SRCDIR		= $(addprefix $(TARGET)/, $(EX))
TESTDIR		= tests
SRCS		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
TESTS		= $(foreach ex, $(EX), $(wildcard $(TESTDIR)/test_$(ex).c))
OBJS		= $(SRCS:.c=.o)
TEST_OBJS	= $(TESTS:.c=.o)
BINDIR		= tests_build

all: $(addprefix $(BINDIR)/$(TARGET)/, $(EX)) clean

debug: CFLAGS += -g
debug: $(if $(filter 1,$(words $(EX))),debug-single,debug-multiple) clean

debug-single: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(TEST_OBJS) -o $(BINDIR)/test_debug

debug-multiple: $(addprefix debug_, $(EX))

debug_%: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)/debug
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter $(TARGET)/$*/%.o, $(OBJS)) $(filter tests/test_$*.o, $(TEST_OBJS)) -o $(BINDIR)/debug/test_debug_$*

$(BINDIR)/$(TARGET)/%: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)/$(TARGET)
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter $(TARGET)/$*/%.o, $(OBJS)) $(filter tests/test_$*.o, $(TEST_OBJS)) -o $@

$(TARGET)/%.o: $(TARGET)/%.c
	$(COMPILE.c) $(addprefix -I, $(patsubst %/,%,$(basename $(dir $^)))) -Dmain=program_main $(OUTPUT_OPTION) $<

$(TESTDIR)/%.o: $(TESTDIR)/%.c
	$(COMPILE.c) $(addprefix -I, $(TARGET)/$(basename $(patsubst tests/test_%, %, $^))) $(OUTPUT_OPTION) $<

%: %.o <br>
	$(LINK.o) $^ $(LOADLIBES) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@<br>

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(BINDIR)

re: fclean
	$(MAKE) all
