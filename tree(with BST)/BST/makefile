# 编译器设置
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# 文件设置
TARGET = BinarySearchTree
SOURCES = main.cpp
HEADERS = BinarySearchTree.h dsexceptions.h
REPORT = report.tex
PDF = report.pdf

# 默认目标
all: run report

# 编译程序并运行测试
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET)

# 编译 LaTeX 报告
report: $(REPORT)
	xelatex -interaction=nonstopmode -output-directory=. $(REPORT)

# 清理所有生成的文件
clean:
	rm -f $(TARGET) $(PDF) *.aux *.log *.out
