/* -------------------------------------------

	Copyright ZKA Technologies

------------------------------------------- */

/// @file Linker.cxx
/// @brief ZKA Linker frontend for AE objects.

#include <iostream>
#include <cstring>
#include <vector>

extern "C" int CPlusPlusPreprocessorMain(int argc, char const* argv[]);
extern "C" int CompilerCPlusPlusX8664(int argc, char const* argv[]);
extern "C" int ZKAAssemblerMainAMD64(int argc, char const* argv[]);

int main(int argc, char const* argv[])
{
	for (size_t index_arg = 0; index_arg < argc; ++index_arg)
	{
		if (strstr(argv[index_arg], "/?"))
		{
			std::printf("cl.exe: Frontend C++ Compiler.\n");
			std::printf("cl.exe: Designed by Amlal El Mahrouss, Copyright ZKA Technologies.\n");
			std::printf("libndk.dylib/ndk.dll: Designed by Amlal El Mahrouss, Copyright ZKA Technologies.\n");

			return 0;
		}
	}

	if (auto code = CPlusPlusPreprocessorMain(argc, argv); code)
	{
		std::printf("cl.exe: frontend exited with code %i.\n", code);
		return 1;
	}
	else
	{
		std::vector<std::string> args_list_cxx;
		std::vector<std::string> args_list_asm;

		for (size_t index_arg = 0; index_arg < argc; ++index_arg)
		{
			if (strstr(argv[index_arg], ".cxx") ||
				strstr(argv[index_arg], ".cpp") ||
				strstr(argv[index_arg], ".cc") ||
				strstr(argv[index_arg], ".c++") ||
				strstr(argv[index_arg], ".C"))
			{
				std::string arg = argv[index_arg];

				arg += ".pp.masm";
				args_list_asm.push_back(arg);

				arg = argv[index_arg];
				arg += ".pp";

				args_list_cxx.push_back(arg);
			}
		}

		for (auto& cli : args_list_cxx)
		{
			const char* arr_cli[] = {argv[0], cli.data()};

			if (auto code = CompilerCPlusPlusX8664(2, arr_cli); code)
			{
				std::printf("cl.exe: assembler exited with code %i.", code);
			}
		}

		for (auto& cli : args_list_asm)
		{
			const char* arr_cli[] = {argv[0], cli.data()};

			if (auto code = ZKAAssemblerMainAMD64(2, arr_cli); code)
			{
				std::printf("cl.exe: assembler exited with code %i.", code);
			}
		}
	}

	return 0;
}