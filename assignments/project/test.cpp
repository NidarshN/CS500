#include "gtest/gtest.h"
#include "hamming_code.h"
#include "eigen/Eigen/Dense"
#include <iostream>

TEST(HammingCodeTest, SingleErrorCorrection)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword << 0,0,0,1,1,1,1;
    auto result = hammingCode.decode(codeword);
    Eigen::VectorXd temp = Eigen::VectorXd(4);
    temp << 0,0,0,1;
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, temp);
}

TEST(HammingCodeTest, NoError)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword << 1, 0, 1, 1, 0, 1, 1;
    auto result = hammingCode.decode(codeword);
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, Eigen::Vector4d(1, 0, 1, 1));
}

// TEST(HammingCodeTest, MultipleErrors)
// {
//     HammingCode hammingCode;
//     Eigen::VectorXd codeword(7);
//     codeword << 0, 1, 1, 0, 1, 0, 1;
//     auto result = hammingCode.decode(codeword);
//     EXPECT_FALSE(result.first);
// }

TEST(HammingCodeTest, AllZeros)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword.setZero();
    auto result = hammingCode.decode(codeword);
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, Eigen::Vector4d::Zero());
}

TEST(HammingCodeTest, AllOnes)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword.setOnes();
    auto result = hammingCode.decode(codeword);
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, Eigen::Vector4d::Ones());
}

TEST(HammingCodeTest, RandomData)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword << 0, 1, 1, 0, 0, 1, 1;
    auto result = hammingCode.decode(codeword);
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, Eigen::Vector4d(0, 1, 1, 0));
}

TEST(HammingCodeTest, RandomData1)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword << 1, 1, 0, 0, 0, 0, 1;
    auto result = hammingCode.decode(codeword);
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, Eigen::Vector4d(1, 1, 0, 0));
}

TEST(HammingCodeTest, GeneratorMatrixDimensionCheck)
{
    HammingCode hammingCode;
    Eigen::MatrixXd generator(4, 7);
    generator << 1, 0, 0, 0, 1, 1, 0,
                0, 1, 0, 0, 0, 1, 1,
                0, 0, 1, 0, 1, 0, 1,
                0, 0, 0, 1, 1, 1, 0;
    auto result = hammingCode.getGeneratorMatrix();
    EXPECT_EQ(result, generator);
    EXPECT_EQ(result.cols(), 7);
    EXPECT_EQ(result.rows(), 4);
}

TEST(HammingCodeTest, ParityCheckMatrixDimensionCheck)
{
    HammingCode hammingCode;
    Eigen::MatrixXd parityCheck(3, 7);
    parityCheck <<  0, 0, 1, 1, 1, 1, 0,
                    0, 1, 0, 1, 1, 0, 1,
                    1, 0, 0, 0, 1, 1, 1;
    auto result = hammingCode.getParityCheckMatrix();
    EXPECT_EQ(result, parityCheck);
    EXPECT_EQ(result.cols(), 7);
    EXPECT_EQ(result.rows(), 3);
}

TEST(HammingCodeTest, IdentityDimensionCheck)
{
    HammingCode hammingCode;
    int size = 4;
    Eigen::MatrixXd identity = Eigen::MatrixXd::Identity(size, size);
    auto result = hammingCode.getIdentityMatrix(size);
    EXPECT_EQ(result, identity);
    EXPECT_EQ(result.cols(), size);
    EXPECT_EQ(result.rows(), size);
}


TEST(HammingCodeTest, FileReadSuccess)
{
    HammingCode hammingCode;
    hammingCode.readFile("../hamming_code.txt");

    EXPECT_EQ(hammingCode.getCodewordMatrix().rows(), 20);
}

TEST(HammingCodeTest, FileReadFailure)
{
    HammingCode hammingCode;
    hammingCode.readFile("../invalid_codewords.txt");
    EXPECT_EQ(hammingCode.getCodewordMatrix().rows(), 1);
}

TEST(HammingCodeTest, DecoderFunctionality)
{
    HammingCode hammingCode;
    hammingCode.readFile("../hamming_code.txt");
    testing::internal::CaptureStdout();
    hammingCode.decoder();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_GE(output.find("Data Intact: No Errors detected!"), 0);
    EXPECT_GE(output.find("Error Detected: Corrected at Position:"), 0);
}

TEST(HammingCodeTest, InvalidFile)
{
    HammingCode hammingCode;
    testing::internal::CaptureStderr();
    hammingCode.readFile("nonexistent_file.txt");
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("File Error: File cannot be opened!"), std::string::npos);
}

TEST(HammingCodeTest, InvalidCodewordLength)
{
    HammingCode hammingCode;
    testing::internal::CaptureStderr();
    hammingCode.readFile("../invalid_codewordlength.txt");
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("Size Error: Codeword length mismatch!"), std::string::npos);
}


TEST(HammingCodeTest, CorrectedErrorOutput)
{
    HammingCode hammingCode;
    Eigen::VectorXd codeword(7);
    codeword << 1, 0, 0, 1, 1, 1, 0;
    testing::internal::CaptureStderr();
    auto result = hammingCode.decode(codeword);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_TRUE(result.first);
    EXPECT_NE(output.find("Error Detected: Corrected at Position: "), std::string::npos);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
