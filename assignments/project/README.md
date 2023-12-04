# Hamming (7,4) Code Decoder

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Setup](#setup)
- [Usage](#usage)

## Introduction

This C++ implementation provides a decoder for the Hamming (7,4) Code. The Hamming Code (7,4) is a systematic block code that enables the detection and correction of single-bit errors in the received codeword. This implementation utilizes the Eigen library for efficient matrix operations.

## Features

- **Hamming (7,4) Code Implementation**: The decoder is based on the Hamming Code (7,4), allowing for the detection and correction of single-bit errors in the received codeword.

- **Matrix Operations with Eigen**: Efficiently performs matrix operations using the Eigen library, including the generation of the generator matrix, parity check matrix, and identity matrix.

- **File Input Support**: Reads Hamming encoded codewords from a text file, making it convenient for processing large datasets.

- **Decoding Functionality**: Decodes 7-bit codewords using the Hamming (7,4) code, providing information on successful decoding or error detection, along with the 4-bit decoded message.

- **Example Usage**: Includes a comprehensive example in the documentation showcasing how to integrate and use the Hamming Code (7,4) decoder in a C++ program.

## Setup

```shell
$>git clone https://github.com/NidarshN/CS500.git
$> cd assignments/project
$> git clone https://github.com/google/googletest.git
$> git clone https://gitlab.com/libeigen/eigen.git
$> doxygen doxygen_config
$> g++ -std=c++17 main.cpp hamming_code.cpp -o hamming
$> ./hamming
```

### Test Using Google Test Framework

```shell
$> cd assignments/project
$> cmake -S . -B build
$> cmake --build build
$> cd build
$> make
$> ctest
```

[Test Log](./build/Testing/Temporary/LastTest.log)

## Usage

```cpp
#include "hamming_code.h"
#include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>

int main() {
    // Create Hamming Code instance
    HammingCode hammingCode;

    // Read Hamming Encoded Codewords from a file
    hammingCode.readFile("YOUR_HAMMING_ENCODED_CODEWORDS.txt");

    // Function call to the Hamming Decoder to decode the codewords
    hammingCode.decoder();

    // Decode an encoded hamming code
    Eigen::VectorXd codeword(7);
    codeword << 0, 1, 1, 0, 0, 1, 1;
    auto decodedMessage = hammingCode.decode(codeword);

    // Output results
    std::cout << "Encrypted Code for 0110: " << codeword << std::endl;
    std::cout << "Decrypted Message: " << decodedMessage << std::endl;

    return 0;
}
```

## Documentation

[Click Here](./docs/html/index.html)
