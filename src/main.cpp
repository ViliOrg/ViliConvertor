#include <filesystem>

#include <lyra/lyra.hpp>

int main(int argc, char** argv)
{
    std::string input_filename;
    std::string output_filename;
    auto cli = lyra::cli()
        | lyra::opt(input_filename, "input_filename")
        ["-i"]["--input"]
        ("Input file").required()
        | lyra::opt(output_filename, "output_filename")
        ["-o"]["--output"]
        ("Output file").required();

    const auto result = cli.parse({ argc, argv });
    if (!result)
    {
        std::cerr << "Error in command line: " << result.message() << std::endl;
        return 1;
    }

    if (!std::filesystem::exists(input_filename))
    {
        std::cerr << "File (input) at path '" << input_filename << "' does not exists" << std::endl;
        return 1;
    }

    if (!std::filesystem::exists(output_filename))
    {
        std::cerr << "File (output) at path '" << output_filename << "' does not exists" << std::endl;
        return 1;
    }

    const std::string input_ext = std::filesystem::path(input_filename).extension().string();
    const std::string output_ext = std::filesystem::path(output_filename).extension().string();

    return 0;
}