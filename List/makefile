# Variables for compiler, options, and files
CXX = g++
CXXFLAGS = -std=c++20 -O2
TARGET = List
SRC = List.cpp

# Target for compiling the program
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Target for compiling the LaTeX report
report:
	xelatex report.tex
	xelatex report.tex  # Run twice to ensure correct cross-references

# Clean the generated files
clean:
	rm -f $(TARGET) *.aux *.log *.out *.pdf

