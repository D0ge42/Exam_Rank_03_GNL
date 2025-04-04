# Fast and easy way to do get_next_line - Exam Rank 03

This repository provides a simple and efficient implementation of the **get_next_line** function for **Exam Rank 03**. The approach is designed to be easy to understand, using only fundamental functions that 42 students are already familiar with.

## Features
- **Leak-free implementation**
- **Minimal and straightforward approach**
- **Uses only essential functions**
- **Fast and easy to learn**

## Functions Used
The implementation relies on four well-known functions:
- `ft_strlen` - Calculates the length of a string.
- `ft_strchr` (revised) - Checks if a character is present in a string, returning `1` or `0`.
- `ft_strdup` - Duplicates a string.
- `ft_strjoin` - Concatenates two strings.

Additionally, three key functions are implemented:
- `extract_line` - Extracts the next line from the buffer.
- `update_stash` - Updates the buffer after extracting a line.
- `get_next_line` - The main function that reads and returns the next line.

## How It Works
1. Reads input until a newline or end-of-file is found.
2. Extracts the line from the stored buffer.
3. Updates the buffer to remove the extracted portion.
4. Returns the line, ensuring no memory leaks.

## Notes
- This implementation ensures there are **no memory leaks**.
- It is structured to be **fast and simple to understand**, making it ideal for Exam Rank 03.

## License
This project is open-source and free to use for educational purposes.

---
Good luck with your Exam Rank 03! 🚀
