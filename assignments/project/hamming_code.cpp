#include "hamming_code.h"
#include "eigen/Eigen/Dense"
HammingCode::HammingCode()
{
    generator_matrix = Eigen::MatrixXd::Zero(MESSAGE_SIZE, CODEWORD_SIZE);
    parity_matrix = Eigen::MatrixXd(MESSAGE_SIZE, CHECKBIT_SIZE);
    parity_matrix.setZero();
    parity_check_matrix = Eigen::MatrixXd(CHECKBIT_SIZE, CODEWORD_SIZE);

    for (int i = 0; i < MESSAGE_SIZE; i++)
    {
        parity_matrix(i, i % CHECKBIT_SIZE) = INIT_VALUE;
        parity_matrix(i, (i + 1) % CHECKBIT_SIZE) = INIT_VALUE;
    }

    identity_matrix_generate = getIdentityMatrix(MESSAGE_SIZE);
    generator_matrix << identity_matrix_generate, parity_matrix;

    identity_matrix_decode = getIdentityMatrix(CHECKBIT_SIZE);
    parity_check_matrix << identity_matrix_decode, parity_matrix.transpose();
    parity_check_matrix.block(0, 0, parity_check_matrix.rows(), INIT_VALUE).swap(parity_check_matrix.block(0, 2, parity_check_matrix.rows(), INIT_VALUE));
    parity_check_matrix.col(parity_check_matrix.cols() - 1).setOnes();
    parity_check_matrix.block(0, 4, parity_check_matrix.rows(), INIT_VALUE).swap(parity_check_matrix.block(0, 6, parity_check_matrix.rows(), INIT_VALUE));

    codeword_matrix = Eigen::MatrixXd(codeword_length, CODEWORD_SIZE);
    codeword_matrix.setOnes();
}

HammingCode::~HammingCode() {}

Eigen::MatrixXd HammingCode::getIdentityMatrix(const int SIZE) const
{
    return Eigen::MatrixXd::Identity(SIZE, SIZE);
}

Eigen::MatrixXd HammingCode::getGeneratorMatrix() const
{
    return generator_matrix;
}

Eigen::MatrixXd HammingCode::getParityCheckMatrix() const
{
    return parity_check_matrix;
}

Eigen::MatrixXd HammingCode::getCodewordMatrix() const
{
    return codeword_matrix;
}

void HammingCode::readFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "File Error: File cannot be opened!" << std::endl;
        return;
    }
    std::string line = "";
    while (getline(file, line))
    {
        if (line.size() != (unsigned long)CODEWORD_SIZE)
        {
            std::cerr << "Size Error: Codeword length mismatch!" << std::endl;
            continue;
        }

        Eigen::MatrixXd codeword = Eigen::MatrixXd(INIT_VALUE, CODEWORD_SIZE);
        for (int i = 0; i < CODEWORD_SIZE; i++)
        {
            codeword[i] = line[i] - '0';
        }
        codeword_matrix.row(codeword_length - 1) = codeword;
        ++codeword_length;
        codeword_matrix.conservativeResize(codeword_length, CODEWORD_SIZE);
    }
}

std::pair<bool, Eigen::VectorXd> HammingCode::decode(const Eigen::VectorXd &codeword)
{
    Eigen::VectorXd syndrome = Eigen::VectorXd(CHECKBIT_SIZE);
    syndrome.setZero();
    Eigen::MatrixXd parityChecker = getParityCheckMatrix();
    syndrome = parityChecker * codeword;
    for (int i = 0; i < CHECKBIT_SIZE; i++)
    {
        syndrome[i] = ((int)syndrome[i]) % 2;
    }
    if (syndrome != (Eigen::Vector<double, 3>::Zero()))
    {
        int error_position = -1;
        for (int i = 0; i < CODEWORD_SIZE; i++)
        {
            if (parityChecker.col(i) == syndrome)
            {
                error_position = i;
                break;
            }
        }
        if (error_position == -1)
        {
            std::cout << "Multiple Errors Detected: Unable to perform correction!" << std::endl;
            Eigen::VectorXd invalid_data = Eigen::VectorXd(MESSAGE_SIZE);
            invalid_data.setZero();
            return std::make_pair(false, invalid_data);
        }
        else
        {
            Eigen::VectorXd corrected_codeword = codeword;
            corrected_codeword[error_position] = ((int)(corrected_codeword[error_position])) ^ 1;
            std::cerr << "Error Detected: Corrected at Position: " << error_position + 1 << std::endl;
            return std::make_pair(true, corrected_codeword.segment<4>(0));
        }
    }
    else
    {
        std::cout << "Data Intact: No Errors detected!" << std::endl;
        return std::make_pair(true, codeword.segment<4>(0));
    }
}

void HammingCode::decoder()
{
    for (int i = 0; i < codeword_matrix.rows() - 1; i++)
    {
        Eigen::VectorXd codeword_vector = codeword_matrix.row(i);
        std::cout << "Input: ";
        for (int i = 0; i < CODEWORD_SIZE; ++i)
        {
            std::cout << codeword_vector[i];
        }
        std::cout << std::endl;

        auto [success, decodedMessage] = decode(codeword_vector);
        if (success)
        {
            std::cout << "Decoded Message: ";
            for (int i = 0; i < MESSAGE_SIZE; ++i)
            {
                std::cout << decodedMessage[i];
            }
            std::cout << std::endl << std::endl;
        }
        else
        {
            std::cerr << "Multiple Errors Detected: Unable to decode!" << std::endl << std::endl;
        }
    }
}
