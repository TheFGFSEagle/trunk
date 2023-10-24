#include <iostream>
#include <map>
#include <functional>

#include <argparse/argparse.hpp>

#include <trunk/function.hxx>
#include <trunk/config.hpp>

namespace trunk {
	namespace globals {
		Reference print(Reference s) {
			std::cout << *s.get_object() << std::endl;
			return {};
		}
	}
}

static std::map<std::string, trunk::Reference*> globals = {
	{"print", new trunk::Reference(new trunk::Function(&trunk::globals::print))},
};

void run(std::string code) {
	bool function_name = false;
	char quote = '\0';
	char opening_parenthesis = '\0';
	std::string current_function_name;
	std::string current_symbol = "";
	for (auto& c: code) {
		if (quote) {
			if (c == quote) {
				quote = '\0';
			} else {
				current_symbol += c;
			}
		} else {
			if (c == '(') {
				opening_parenthesis = c;
				function_name = false;
			} else if (c == ')') {
				opening_parenthesis = '\0';
			} else if (c == '\'' or c == '"') {
				quote = c;
			} else {
				function_name = true;
				current_function_name += c;
			}
		}
	}
	
	trunk::Reference* function_ref = globals[current_function_name];
	trunk::Function* function = function_ref->get_object<trunk::Function>();
	(*function)(current_symbol);
}

int main(int argc, char* argv[]) {
	argparse::ArgumentParser argp("trunk", VERSION);
	argp.add_argument("code")
		.help("Code string to parse and execute")
		.default_value(std::string(""));
	
	try {
		argp.parse_args(argc, argv);
	} catch (const std::runtime_error& err) {
		std::cerr << err.what() << std::endl;
		std::cerr << argp;
		return 1;
	}
	
	run(argp.get("code"));
	return 0;
}

