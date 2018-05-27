SUB	=	\
		circular-array-rotation \
		extra-long-factorials \
		find-digits \
		jumping-on-the-clouds \
		permutation-equation \
#		append-and-delete \

#SOLUTIONS=	$(patsubst %,%/solution,$(SUB))
#MAKEFILES=	$(patsubst %,%/Makefile,$(SUB))
#SRCS	=	$(patsubst %,%/solution.cpp,$(SUB))
SOLUTIONS=	$(SUB:%=%/solution)
MAKEFILES=	$(SUB:%=%/Makefile)
SRCS	=	$(SUB:%=%/solution.cpp)

BIN	=	$(SRCS:.cpp=)

all: $(SOLUTIONS)

define sub_to_target
$(1): $(1)/solution

$(1)/solution:
	make -C $(1) solution

$(1)-clean:
	make -C $(1) clean

endef

$(foreach sub,$(SUB),$(eval $(call sub_to_target,$(sub))))


clean:
	@for dink in $(SUB); do \
		make -C $$dink clean; \
	done

show-projects:
	@echo $(SUB)

show-bin:
	@echo $(BIN)

show-srcs:
	@echo $(SRCS)

show-what-to-do:
	@for dink in $(SUB); do \
		/bin/echo -ne Checking $$dink : ; \
		if [ -x $$dink/solution ]; then \
			echo "nothing"; \
		else \
			echo "Needs to be built"; \
		fi \
	done
