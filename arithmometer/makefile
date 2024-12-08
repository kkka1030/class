# 定义编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# 项目中的源文件和目标文件
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

# 可执行文件名
TARGET = calc

# LaTeX 相关变量
TEXFILE = report.tex
PDF = report.pdf

# 默认目标：编译程序
all: $(TARGET) $(PDF)

# 生成可执行文件
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# 编译源文件生成目标文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 生成 LaTeX 报告 PDF
$(PDF): $(TEXFILE)
	pdflatex $(TEXFILE)

# 清理编译生成的文件
clean:
	rm -f $(OBJ) $(TARGET) $(PDF) *.aux *.log *.out

# 运行程序
run: $(TARGET)
	./$(TARGET)

# 为调试添加额外的目标
debug: CXXFLAGS += -g
debug: $(TARGET)

# 如果你想只编译源文件，而不创建可执行文件
compile: $(OBJ)

# 默认输出信息
.PHONY: all clean run debug compile
