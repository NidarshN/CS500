#ifndef _hamming_code_h
#define _hamming_code_h
#define EIGEN_NO_DEBUG
#define EIGEN_NO_STATIC_ASSERT
#include "eigen/Eigen/Dense"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

/*!
@mainpage Hamming(7,4) Code Decoder Implmentation in C++

@section intro Introduction
This documentation provides information on the Hamming(7, 4) Code Decoder implementation in C++.
The Hamming Code (7,4) is a message error detection consisting of a 4-bit data word and 3 parity bits,
allowing the detection and correction of single-bit errors in the received codeword.

@section features Features
 *
 * - Matrix Operations: Uses Eigen library for efficient matrix operations, including generator matrix generation, parity check matrix generation, and identity matrix creation.
 *
 * - Easy Integration: Provides a simple C++ interface for integrating the Hamming Code (7,4) decoder into your projects.
 *
 * - File Input: Supports reading Hamming encoded codewords from a text file, making it convenient for processing large datasets.
 *
 * - Decoding Functionality: Decodes 7-bit codewords using the Hamming (7,4) code, providing a pair indicating success or error detection, and the 4-bit decoded message.


@section usage Usage
@code
#include "hamming_code.h"
#include <iostream>
#include <string>
#include <eigen3/Eigen/Dense>

int main() {
    // Create Hamming Code instance
    HammingCode hammingCode;

    std::string filename = "YOUR_HAMMING_ENCODED_CODEWORDS.txt"

    // Read Hamming Encoded Codewords from a file
    hammingCode.readFile(filename);

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
@endcode

*/

/**
 * @class HammingCode
 * @brief Class that represents a Hamming Code decoder.
 *
 * It utilizes the Hamming Code (7,4) to decode codewords. The Hamming code table used here is selected from
 * several available variations. This particular version is chosen for its simplicity and common use.
 * Please refer to this table for all decoding results:
 *
 * Hamming Code Table:
 * | Data Bits (D) | Encoded Hamming Code (H) |
 * |---------------|--------------------------|
 * | 0000          | 0000000                  |
 * | 0001          | 0001011                  |
 * | 0010          | 0010101                  |
 * | 0011          | 0011110                  |
 * | 0100          | 0100110                  |
 * | 0101          | 0101101                  |
 * | 0110          | 0110011                  |
 * | 0111          | 0111000                  |
 * | 1000          | 1000111                  |
 * | 1001          | 1001100                  |
 * | 1010          | 1010010                  |
 * | 1011          | 1011001                  |
 * | 1100          | 1100001                  |
 * | 1101          | 1101010                  |
 * | 1110          | 1110100                  |
 * | 1111          | 1111111                  |
 *
 * Note: Due to the existence of multiple encoding schemes, this table should be used as the reference for all decoding operations performed by this decoder.
 */

class HammingCode
{
private:
    const int CODEWORD_SIZE = 7;
    const int CHECKBIT_SIZE = 3;
    const int MESSAGE_SIZE = CODEWORD_SIZE - CHECKBIT_SIZE;
    const int INIT_VALUE = 1;
    int codeword_length = 1;

    Eigen::MatrixXd generator_matrix;
    Eigen::MatrixXd parity_check_matrix;
    Eigen::MatrixXd parity_matrix;
    Eigen::MatrixXd identity_matrix_generate;
    Eigen::MatrixXd identity_matrix_decode;
    Eigen::MatrixXd codeword_matrix;

public:
    /**
     * @brief Construct a new Hamming Code object
     * Initializes the generator, parity, parity checker matrices.
     * 
     * @param None
     * @return None
     */
    HammingCode();

    /**
     * @brief Destructor for the Hamming Code object
     * Destroys the objects assigned to this object.
     * 
     * @param None
     * @return None
     */
    ~HammingCode();

    /**
     * @brief Function to generate the Identity Matrix of size Size
     * 
     * @param SIZE Integer value containing the size of the identity matrix
     * @return Eigen::MatrixXd Identity Matrix of size Size
     */
    Eigen::MatrixXd getIdentityMatrix(const int SIZE) const;

    /**
     * @brief Getter Function for the Generator Matrix
     * 
     * @return Eigen::MatrixXd Generator Matrix
     */
    Eigen::MatrixXd getGeneratorMatrix() const;

    /**
     * @brief Getter Function for the Parity Check Matrix
     * 
     * @return Eigen::MatrixXd Parity Checking Matrix
     */
    Eigen::MatrixXd getParityCheckMatrix() const;

    /**
     * @brief Getter Function for the Codeword Matrix object
     * 
     * @return Eigen::MatrixXd Codeword Matrix containing several codeword inputs
     */
    Eigen::MatrixXd getCodewordMatrix() const;

    /**
     * @brief Decodes a 7-bit codeword using the Hamming (7,4) code
     *
     * @param codeword The 7-bit codeword to decode
     * @return A pair containing a bool indicating success or error detection, and the 4-bit decoded message or empty message in case of multiple errors.
     */
    std::pair<bool, Eigen::VectorXd> decode(const Eigen::VectorXd &codeword);

    /**
     * @brief Helper function to apply Hamming Decoder to each input codeword stored and obtained from the file
     * 
     * @param None
     * @return None
     */
    void decoder();

    /**
     * @brief Function to read Hamming(7, 4) encoded codewords from a textfile and store it in an Eigen Matrix.
     * 
     * @param filename A String value containing the name of the file to read.
     */
    void readFile(const std::string &filename);
};

#endif