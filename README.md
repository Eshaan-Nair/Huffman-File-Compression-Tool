# Huffman-File-Compression-Tool
This project is a file compression and decompression tool implemented in C++ using **Huffman Coding**, a greedy compression algorithm.  
The tool reads a text file, compresses it into a binary format, stores the Huffman codebook, and is capable of fully decompressing the file back to its original form.

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

## How Huffman Coding works
1. Count the frequency of each character in the input file
2. Build a min-heap (priority queue) based on character frequencies
3. Construct a Huffman tree using a greedy approach
4. Generate prefix-free binary codes for each character
5. Encode the input file using these codes
6. Pack bits into bytes and write to a binary file
7. Store the Huffman codebook for decompression
8. Decode by traversing the Huffman tree using the stored codes

---

## Project Structure
Huffman_Compression_Project/
│
├── main.cpp # Complete compression & decompression logic

├── input.txt # Sample input file

├── compressed.bin # Compressed binary output

├── compressed.txt # Compressed '0' & '1' output

├── codes.txt # Stored Huffman codes (header)

├── decompressed.txt # Decompressed output

└── README.md


---

## How to Run

### 1. Compile
```bash
g++ main.cpp -o huffman
```
### 2. Run
```
./huffman
```

---
## Example Input:
Screenshots/Screenshot 2026-01-16 173758.png

## Example Saved Huffman Codes:
Screenshots/Screenshot 2026-01-16 173916.png

## Example Compression Result:
Screenshots/Screenshot 2026-01-16 172945.png

---

## Time and Space Complexity
- Building the Frequency Table: O(n)
- Building Huffman Tree: O(k logk) where k is the number of unique Characters
- Encoding: O(n)
- Decoding: O(n)

---

## Limitations
1. Designed for textfiles (not binary files like images and videos).
2. Loads entire file into memory.
3. Compression efficiency depends on character distribution.

---

## Possible Improvements
- Streaming compression for large files.
- Support for binary/non-text files.
- CLI arguments for input/output paths.
- Performance optimization using fixed-size arrays.
- Comparing compression ratio with standard tools (ZIP).

---

## Technologies Used
- C++
- STL (priority_queue, unordered_map, vector)
- File I/O (fstream)
- Bitwise operations

---

# Author
## Eshaan Nair

















