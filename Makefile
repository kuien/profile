# dummy project to test code review

CODE_BLD_DIR = $(shell mkdir -p code && cd ./code && pwd)

all clean test lint format tags:
	@if [ ! -d $(CODE_BLD_DIR) ] ; then \
		echoe "NOTICE: cannot find code dir:$(CODE_BLD_DIR), exit."; \
	else \
		make -C $(CODE_BLD_DIR) $@; \
	fi
