#ifndef TRUNK_OBJECT_HXX
#define TRUNK_OBJECT_HXX

#include <iostream>
#include <string>

#include <fmt/format.h>

namespace trunk {
	class Object {
		public:
			Object() {}
			
			virtual const std::string name() { return "Object"; }
			void get_cpp_object() {}
			virtual std::string repr() {
				std::string r = "<";
				r += this->name();
				r += " (";
				r += fmt::format("{:#x}", (long int)this);
				r += ")>";
				return r;
			}
			
			friend std::ostream& operator<<(std::ostream& os, Object& obj);
	};
	
	std::ostream& operator<<(std::ostream& os, trunk::Object& obj) {
		os << obj.repr();
		return os;
	}
}

#endif

