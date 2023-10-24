#ifndef TRUNK_STRING_HXX
#define TRUNK_STRING_HXX

#include <iostream>
#include <string>

#include <trunk/object.hxx>

namespace trunk {
	class String: public Object {
		public:
			String(): _string("") {}
			String(std::string string): _string(string) {}
			
			virtual const std::string name() { return "String"; }
			std::string get_cpp_object() { return _string; }
			virtual std::string repr() { return "\"" + _string + "\""; }
		
		protected:
			std::string _string;
	};
}

#endif

