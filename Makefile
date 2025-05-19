TARGET = main
SRC = main.c

$(TARGET): $(SRC)
	gcc -Wall -Wextra $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) > output.txt

clean:
	rm -f $(TARGET) output.txt
