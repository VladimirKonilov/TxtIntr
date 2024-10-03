.PHONY: run clean

run: 
 python3 calculator/calculator.cpp -o $(OPERATION) $(ARGS)

clean:
 find . -type f -name '*.pyc' -delete
 find . -type d -name '__pycache__' -exec rm -r {} +
