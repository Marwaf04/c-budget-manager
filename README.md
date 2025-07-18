# Budget Tracker C Application
A menu-driven budget tracking application built in C that helps users manage income and expense records efficiently using modular programming and dynamic memory allocation.

## Overview

This C application allows users to:
- Add income and expense entries
- View all financial records
- Analyze expense distribution (needs vs wants)
- Sort records by ID, date, amount, or description
- Modify entries
- Filter records by month

The program is structured across multiple `.c` and `.h` files and utilizes a custom `Entry` struct to store financial data. It emphasizes clean modular design, user input handling, and real-world use cases.

## Features

- Dynamic memory management with `malloc` and `realloc`
- Modular code: separate files for data handling, budgeting, and ordering
- Structured entry data with categories like income, needs, wants
- Menu-based user interface via terminal
- Sorting with `qsort`
- Monthly filtering functionality
- Input file reading with error handling

## File Structure

```
main.c          # Entry point and main menu loop
budget.c/h      # Add, modify, display, and analyze entries
data.c/h        # Load entries from file into memory
ordering.c/h    # Sorting functionality using qsort
```

## Compilation

To compile all the source files:

```bash
gcc main.c budget.c data.c ordering.c -o budgetTracker
```

## Usage

Run the program with an input data file:

```bash
./budgetTracker data.txt
```

The input file should contain records in this format:

```
1|2024-07-01|income|Job|July paycheck|3500.00
2|2024-07-03|expense|Needs|Groceries|120.00
3|2024-07-05|expense|Wants|Dining out|45.50
```

## Concepts Demonstrated

- Structs and dynamic arrays
- Modular header and source files
- Sorting algorithms via `qsort`
- Command-line arguments and input parsing
- Memory allocation and deallocation

## Author

**Marwa Fekri**  
Software Engineering Student, Concordia University  
GitHub: [@Marwaf04](https://github.com/Marwaf04)
