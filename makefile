# 参考资料:
#   [Makefile经典教程(掌握这些足够)](https://blog.csdn.net/ruglcc/article/details/7814546)
#   [Makefile教程：Makefile文件编写1天入门](http://c.biancheng.net/makefile/)
cc = g++
bin_dir = bin
src_dir = src

prom = $(bin_dir)/a
deps = $(shell find ./$(src_dir) -name "*.h")
src = $(shell find ./$(src_dir) -name "*.cpp")
obj = $(basename $(addprefix $(bin_dir)/,$(notdir $(src))))
obj += $(bin_dir)/fa-upper $(bin_dir)/fa-fmt
#obj := $($src:.cpp=)

#.PHONY:test
#test:
#	@echo $(deps)
#	@echo $(src)
#	@echo $(obj)

x := $(shell mkdir -p $(bin_dir))

$(prom) : $(obj)

#% : %.cpp
$(bin_dir)/%: $(src_dir)/%.cpp $(deps)
	$(cc) -o $@ $<

$(bin_dir)/%: $(src_dir)/fakit/%.cpp $(deps)
	$(cc) -o $@ $<

$(bin_dir)/fa-upper : py_src/fa-upper
	cd $(bin_dir) && ln -s ../py_src/fa-upper

$(bin_dir)/fa-fmt : py_src/fa-fmt
	cd $(bin_dir) && ln -s ../py_src/fa-fmt

#clean:
#	@rm -rf $(prom)

