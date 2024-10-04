CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
LDFLAGS		= -lrt -lm
RM			= rm -rf
TARGET		= exercises
EX			= ex06 ex07 ex08 ex09 ex10
SRCDIR		= $(addprefix $(TARGET)/, $(EX))
TESTDIR		= tests
SRCS		= $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))
TESTS		= $(foreach ex, $(EX), $(wildcard $(TESTDIR)/test_$(ex).c))
OBJS		= $(SRCS:.c=.o)
TEST_OBJS	= $(TESTS:.c=.o)
BINDIR		= ./tests_build/$(TARGET)

all: $(addprefix $(BINDIR)/, $(EX)) clean

$(BINDIR)/%: $(OBJS) $(TEST_OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(filter $(TARGET)/$(notdir $@)/%.o, $(OBJS)) $(filter tests/test_$(notdir $@).o, $(TEST_OBJS)) -o $@

$(TARGET)/%.o: $(TARGET)/%.c
	$(COMPILE.c) -Dmain=program_main $(OUTPUT_OPTION) $<

$(TESTDIR)/%.o: $(TESTDIR)/%.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

%: %.o <br>
	$(LINK.o) $^ $(LOADLIBES) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@<br>

clean:
	$(RM) $(OBJS) $(TEST_OBJS)

fclean: clean
	$(RM) $(addprefix $(BINDIR)/, $(EX))

re: fclean
	$(MAKE) all
