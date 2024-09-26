#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

// Function to run the shell and capture its output
std::string run_shell(const std::string& input) {
    std::string output;
    std::ofstream input_file("input.txt");
    input_file << input;
    input_file.close();

    // Run the shell program with the input
    system("./myshell < input.txt > output.txt");

    // Read the output from the output file
    std::ifstream output_file("output.txt");
    std::string line;
    while (std::getline(output_file, line)) {
        output += line + "\n";
    }
    output_file.close();

    return output;
}

// Test for valid command execution (e.g., 'ls' or 'echo Hello')
TEST(ShellTest, ValidCommand) {
    std::string output = run_shell("echo Hello\nexit\n");
    ASSERT_TRUE(output.find("Hello") != std::string::npos);
}

// Test for invalid command handling (e.g., 'invalidcommand')
TEST(ShellTest, InvalidCommand) {
    std::string output = run_shell("invalidcommand\nexit\n");
    ASSERT_TRUE(output.find("exec failed") != std::string::npos);
}

// Test for the exit command
TEST(ShellTest, ExitCommand) {
    std::string output = run_shell("exit\n");
    ASSERT_EQ(output, "myshell> ");
}

// Cleanup test files after execution
class ShellTestCleanup : public ::testing::Test {
protected:
    void TearDown() override {
        std::remove("input.txt");
        std::remove("output.txt");
    }
};

// Test suite execution
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
