# This file is part of ivana project.
# https://github.com/rfloriano/ivana

# Licensed under the MIT license:
# http://www.opensource.org/licenses/MIT-license
# Copyright (c) 2021, Rafael Floriano da Silva <rflorianobr@gmail.com>

%.o: 
	@$(MAKE) clean
	@gcc $*/$*.c -o ./bin/$@

run-%: %.o
	@./bin/$*.o

clean:
	@rm -f ./bin/*.o
	@$(MAKE) bin-dir

bin-dir:
	@mkdir -p ./bin