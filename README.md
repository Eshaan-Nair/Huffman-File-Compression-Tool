# Huffman File Compression Tool

A file compression and decompression tool implemented in C++ using **Huffman Coding**, a greedy compression algorithm. The tool reads a text file, compresses it into a binary format, stores the Huffman codebook, and is capable of fully decompressing the file back to its original form.

---

## Table of Contents
- [Features](#features)
- [How Huffman Coding Works](#how-huffman-coding-works)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Examples](#examples)
- [Performance](#performance)
- [Limitations](#limitations)
- [Future Improvements](#future-improvements)
- [Technologies Used](#technologies-used)
- [Author](#author)

---

## Features

- Compresses text files using Huffman Coding
- Decompresses compressed files using a stored codebook
- Uses binary (bit-level) storage for real compression
- Stores Huffman codes persistently for independent decompression
- Calculates and displays compression ratio
- Handles edge cases like empty input files
- Modular and readable C++ design

---

## How Huffman Coding Works

The compression process follows these steps:

1. **Count Frequency** - Count the frequency of each character in the input file
2. **Build Min-Heap** - Build a min-heap (priority queue) based on character frequencies
3. **Construct Tree** - Construct a Huffman tree using a greedy approach
4. **Generate Codes** - Generate prefix-free binary codes for each character
5. **Encode File** - Encode the input file using these codes
6. **Pack Bits** - Pack bits into bytes and write to a binary file
7. **Store Codebook** - Store the Huffman codebook for decompression
8. **Decode** - Decode by traversing the Huffman tree using the stored codes

---

## Project Structure

```
Huffman_Compression_Project/
│
├── main.cpp              # Complete compression & decompression logic
├── input.txt             # Sample input file
├── compressed.bin        # Compressed binary output
├── compressed.txt        # Compressed '0' & '1' output
├── codes.txt             # Stored Huffman codes
├── decompressed.txt      # Decompressed output
└── README.md             # Project documentation
```

---

## Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Standard C++ libraries

### Compilation

```bash
g++ main.cpp -o huffman
```

### Running the Program

```bash
./huffman
```

---

## Examples

### Example Input
![Compression Input](Screenshots/input.png)

### Example Saved Huffman Codes
![Huffman Codes](Screenshots/codes.png)

### Example Compression Result
![Compression Output](Screenshots/ratio.png)

---

## Performance

### Time Complexity
- **Building the Frequency Table:** O(n)
- **Building Huffman Tree:** O(k log k) where k is the number of unique characters
- **Encoding:** O(n)
- **Decoding:** O(n)

### Space Complexity
- Loads entire file into memory
- Additional space for Huffman tree and codebook storage

---

## Limitations

1. Designed for text files (not binary files like images and videos)
2. Loads entire file into memory
3. Compression efficiency depends on character distribution

---

## Future Improvements

- Streaming compression for large files
- Support for binary/non-text files
- CLI arguments for input/output paths
- Performance optimization using fixed-size arrays
- Comparing compression ratio with standard tools (ZIP)

---

## Technologies Used

- **Language:** C++
- **Data Structures:** STL (priority_queue, unordered_map, vector)
- **File Handling:** File I/O (fstream)
- **Algorithms:** Bitwise operations, Huffman Coding

---

## Author

**Eshaan Nair**

- GitHub: [@Eshaan-Nair](https://github.com/Eshaan-Nair)

---

<div align="center">
  
### If you find this project helpful, please consider giving it a star!

</div>