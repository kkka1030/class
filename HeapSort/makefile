# 编译器
CXX = g++
# 编译选项
CXXFLAGS = -std=c++17 -Wall -O2

# 目标文件
TARGET = test
SRC = test.cpp HeapSort.h
TEX = report.tex

# 默认目标
all: $(TARGET)

# 生成可执行文件
$(TARGET): test.cpp HeapSort.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) test.cpp

# 生成报告
report: $(TEX)
	pdflatex $(TEX)

# 清理编译生成的文件
clean:
	rm -f $(TARGET) *.o *.log *.aux *.out *.pdf

# PHONY 声明
.PHONY: all report clean
