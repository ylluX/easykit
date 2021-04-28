cc = g++
bin_dir = bin
src_dir = src

prom = $(bin_dir)/a
deps = $(shell find ./$(src_dir) -name "*.h")
src = $(shell find ./$(src_dir) -name "*.cpp")
temp = $(subst $(src_dir),$(bin_dir),$(src))
obj = $(subst .cpp,,$(temp))

#.PHONY:test
#test:
#	@echo $(deps)
#	@echo $(src)
#	@echo $(temp)
#	@echo $(obj)

x := $(shell mkdir -p $(bin_dir))

$(prom) : $(obj)


$(bin_dir)/%: $(src_dir)/%.cpp $(deps)
	$(cc) -o $@ $<

clean:
	@rm -rf $(prom)
